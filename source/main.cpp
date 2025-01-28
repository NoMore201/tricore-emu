#include "Elf.hpp"
#include "Tc33x.hpp"

#include <fmt/base.h>
#include <fmt/core.h>

int main(int argc, char *argv[]) {

    if (argc > 1) {
        Tricore::Elf elf_file;

        auto result = elf_file.parse_file(argv[1]);
        if (result) {
            switch (result.value()) {
            case Tricore::Elf::Error::ReadError:
                fmt::print("Error while reading ELF file\n");
                break;
            case Tricore::Elf::Error::InvalidFile:
                fmt::print("Provided file is not ELF\n");
                break;
            }
        } else {
            fmt::print("Entrypoint: {:x}\n", elf_file.entrypoint());

            Tricore::Tc33x machine{};
            machine.init(elf_file);
            machine.start();
        }
    }

    return 0;
}
