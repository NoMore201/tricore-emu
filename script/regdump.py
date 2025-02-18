"""
Generate CPU peripherals definitions from Infineon iLLD files
"""

import argparse
import re
import string
from pathlib import Path
from typing import List, Optional

from clang import cindex
from clang.cindex import CursorKind

MODULE_HEADER_REGEXP_STR = r"Ifx(\w+)_reg.h"

HEADER_TEMPLATE = string.Template(
    """#pragma once

#include "BusClient.hpp"
#include "Types.hpp"

namespace Tricore {

class $module_name : public BusClient {

public:

    $module_name();

    void read(std::byte *buffer_out, u32 address, usize length) override;

    void write(const std::byte *buffer_in, u32 address, usize length) override;

private:

$member_list

};

} // namespace Tricore
"""
)

SOURCE_TEMPLATE = string.Template(
    """#include "Peripherals/$module_name.hpp"
#include "BusClient.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace {

$register_reset_constants

constexpr u32 $module_name_memory_start_address = 0xF0036000U;
constexpr u32 $module_name_memory_size = 1U * KiB;
constexpr u32 $module_name_memory_end_address = $module_name_memory_start_address + $module_name_memory_size;

} // anonymous namespace


Tricore::Scu::Scu()
    : $register_initialization_list
{}

void Tricore::Scu::read(std::byte *buffer_out, u32 address, usize length) {

}

void Tricore::Scu::write(const std::byte *buffer_in, u32 address,
                         usize length) {

}
"""
)


class Module:
    """Object representing CPU peripheral"""

    name: str
    file_list: List[Path]

    def __init__(self, name: str, file_list: Optional[List[Path]] = None) -> None:
        self.name = name
        if file_list is None:
            file_list = []
        self.file_list = file_list

    def get_reg_file(self) -> Optional[Path]:
        """Return file Path corresponding to Ifx<module_name>_reg.h"""

        for file in self.file_list:
            if file.name == f"Ifx{self.name}_reg.h":
                return file
        return None

    def add_file(self, file_path: str | Path):
        """Add file to internal list"""
        self.file_list.append(Path(file_path))

    def get_registers(self) -> List[str]:
        """Get list of registers associated with this peripheral"""

        reg_file = self.get_reg_file()
        register_list: List[str] = []
        if reg_file is not None:
            index = cindex.Index.create()
            translation_unit = index.parse(str(reg_file))
            for child in translation_unit.cursor.get_children():
                if child.spelling in [
                    "Ifx_UReg_32Bit",
                    "Ifx_SReg_32Bit",
                    "Ifx_UReg_16Bit",
                    "Ifx_SReg_16Bit",
                    "Ifx_UReg_8Bit",
                    "Ifx_SReg_8Bit",
                    f"Ifx_{self.name.upper()}",
                ]:
                    # ignore generic typedefs
                    continue
                name_fields = child.spelling.split("_")
                if (
                    len(name_fields) in [3, 4]
                    and child.kind == CursorKind.TYPEDEF_DECL
                    and (
                        name_fields[1] == self.name.upper()
                        or name_fields[1][0].lower() == self.name[0].lower()
                    )
                    and name_fields[-1] != "Bits"
                ):
                    register_name = "_".join(name_fields[2:])
                    register_list.append(register_name)

        return register_list


def get_repo_path() -> Path:
    """Returns this repository absolute path, e.g. /home/abc/tricore_emu"""
    return Path(__file__).parent.parent.resolve()


def parse_illd(path: str | Path):
    """Parse modules from infineon iLLD header and generate source code"""

    illd_path = Path(path)
    if not illd_path.exists() or not illd_path.is_dir():
        print(f"provided path {illd_path} not found")

    file_list = illd_path.glob("*_reg.h")

    module_list: List[Module] = []
    base_folder = get_repo_path()

    # remove some unnecessary headers
    filtered_list = [
        header
        for header in file_list
        if header.name not in ["Ifx_reg.h", "Ifx_TypesReg.h"]
    ]

    for file in filtered_list:
        match = re.search(MODULE_HEADER_REGEXP_STR, str(file))
        if match is not None:
            module_name = match.group(1)
            file_list = list(illd_path.glob(f"*Ifx{module_name}_*.h"))
            module_list.append(Module(module_name, file_list))

    for module in module_list:
        regs = module.get_registers()
        member_list = [f"    u32 m_{reg.lower()};" for reg in regs]
        member_list = "\n".join(member_list)
        final_string = HEADER_TEMPLATE.substitute(
            module_name=module.name, member_list=member_list
        )
        final_header_path = (
            base_folder / "source" / "Peripherals" / f"{module.name}.hpp"
        )
        final_header_path.write_text(final_string)


def main():
    """Main function"""

    arg_parser = argparse.ArgumentParser(
        "regdump", description="Generate register definitions from Infineon files"
    )
    arg_parser.add_argument("illd_path", action="store", type=str)

    arguments = arg_parser.parse_args()
    parse_illd(arguments.illd_path)


if __name__ == "__main__":
    main()
