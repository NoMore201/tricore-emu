#include "Machine.hpp"
#include "Elf.hpp"
#include "Tricore.hpp"

Tricore::Machine::Machine(Tricore::CpuVariant variant)
    : m_memory(variant)
    , m_memory_registration(m_bus.register_device(m_memory))
    , m_cpu(m_bus)
{
}

void Tricore::Machine::init(Elf& elf_file)
{
    m_cpu.initialize_program(elf_file);
}

void Tricore::Machine::start()
{
    m_cpu.start();
}
