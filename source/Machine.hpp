#ifndef TRICORE_EMU_MACHINE_HPP
#define TRICORE_EMU_MACHINE_HPP

#include "Elf.hpp"
#include "Cpu.hpp"

namespace Tricore {

class Machine {

public:
    Machine() = default;

    void init(Elf& elf_file);

    void start();

private:

    Cpu m_cpu;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_MACHINE_HPP