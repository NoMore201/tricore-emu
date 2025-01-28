#include "Tc33x.hpp"
#include "Elf.hpp"

Tricore::Tc33x::Tc33x() = default;

Tricore::Tc33x::~Tc33x() = default;

void Tricore::Tc33x::init(Elf &elf_file) {
    m_cpu = Cpu::create_tc33x();
    m_cpu.init(elf_file);
}

void Tricore::Tc33x::start() { m_cpu.start(); }