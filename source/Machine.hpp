#ifndef TRICORE_EMU_MACHINE_HPP
#define TRICORE_EMU_MACHINE_HPP

#include "Elf.hpp"
#include "Cpu.hpp"

namespace Tricore {

class Machine {

public:

    enum class Family : u8 {
        TC33X
    };

    Machine() = default;

    void init(Elf& elf_file, Family family);

    void start();

private:

    Cpu m_cpu;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_MACHINE_HPP