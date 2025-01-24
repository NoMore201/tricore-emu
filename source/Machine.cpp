#include "Machine.hpp"

void Tricore::Machine::init(Elf &elf_file, Family family) {
    switch (family) {
    case Family::TC33X:
        m_cpu = Cpu::create_tc33x();
    }
    m_cpu.init(elf_file);
}

void Tricore::Machine::start() { m_cpu.start(); }