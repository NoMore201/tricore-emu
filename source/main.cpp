#include "Elf.hpp"
#include "Machine.hpp"
#include "Tricore.hpp"

#include <spdlog/common.h>
#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {

    // TODO: handle with parameters
    spdlog::set_level(spdlog::level::trace);

    if (argc > 1) {
        Tricore::Elf elf_file;

        auto result = elf_file.parse_file(argv[1]);
        if (result) {
            switch (result.value()) {
            case Tricore::Elf::Error::ReadError:
                spdlog::info("Error while reading ELF file");
                break;
            case Tricore::Elf::Error::InvalidFile:
                spdlog::info("Provided file is not ELF");
                break;
            }
        } else {
            Tricore::Machine machine{Tricore::CpuVariant::TC33X};
            machine.init(elf_file);
            machine.start();
        }
    }

    return 0;
}
