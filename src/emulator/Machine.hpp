#ifndef TRICORE_EMU_MACHINE_HPP
#define TRICORE_EMU_MACHINE_HPP

#include "Cpu/Cpu.hpp"
#include "Memory.hpp"
#include "Tricore.hpp"

namespace Tricore {

class Elf;

class Machine {

public:
    explicit Machine(CpuVariant variant);

    void init(Elf& elf_file);

    void start();

private:
    Memory m_memory;
    Cpu m_cpu;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_MACHINE_HPP
