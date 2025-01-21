#include "Machine.hpp"

void Tricore::Machine::init(Elf &elf_file) {
    m_cpu.init(elf_file);
}

void Tricore::Machine::start() {
    m_cpu.start();
}