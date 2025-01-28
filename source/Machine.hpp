#ifndef TRICORE_EMU_MACHINE_HPP
#define TRICORE_EMU_MACHINE_HPP

namespace Tricore {

class Elf;

class Machine {

public:

    virtual void init(Elf& elf_file) = 0;

    virtual void start() = 0;

};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_MACHINE_HPP