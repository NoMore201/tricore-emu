add_library(
  emulator STATIC
  Bus.cpp
  IBusClient.cpp
  Cpu/Cpu.cpp
  Cpu/InstructionFormat.cpp
  Elf.cpp
  Machine.cpp
  Memory.cpp
  # Peripherals/Asclin.cpp
  # Peripherals/Can.cpp
  # Peripherals/Cbs.cpp
  # Peripherals/Ccu6.cpp
  # Peripherals/Converter.cpp
  # Peripherals/Cpu.cpp
  # Peripherals/Dma.cpp
  # Peripherals/Dmu.cpp
  # Peripherals/Dom.cpp
  # Peripherals/Eray.cpp
  # Peripherals/Evadc.cpp
  # Peripherals/Fce.cpp
  # Peripherals/Fsi.cpp
  # Peripherals/Gpt12.cpp
  # Peripherals/Gtm.cpp
  # Peripherals/Int.cpp
  # Peripherals/Iom.cpp
  # Peripherals/Mtu.cpp
  # Peripherals/Pfi.cpp
  # Peripherals/Pms.cpp
  # Peripherals/Pmu.cpp
  # Peripherals/Port.cpp
  # Peripherals/Qspi.cpp
  # Peripherals/Sbcu.cpp
  # Peripherals/Scu.cpp
  # Peripherals/Sent.cpp
  # Peripherals/Smu.cpp
  # Peripherals/Src.cpp
  # Peripherals/Stm.cpp
)
target_include_directories(emulator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(emulator PRIVATE cxx_std_20)
target_link_libraries(emulator PRIVATE fmt::fmt Microsoft.GSL::GSL
                                       spdlog::spdlog)
