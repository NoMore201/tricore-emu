#ifndef TRICORE_EMU_TC33X_HPP
#define TRICORE_EMU_TC33X_HPP

#include "Cpu.hpp"
#include "Machine.hpp"

namespace Tricore {

class Tc33x : public Machine {
public:
    Tc33x();

    virtual ~Tc33x();

    void init(Elf &elf_file) override;

    void start() override;

private:
    Cpu m_cpu;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_TC33X_HPP