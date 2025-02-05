# tricore-emu

Emulator for AURIX Tricore architecture targeting TC-3xx family of MCUs.
Currently under development.

## Building and installing

### Dependencies

For a list of dependencies, please refer to [vcpkg.json](vcpkg.json).

### Build

This project doesn't require any special command-line flags to build to keep
things simple.

Here are the steps for building in release mode with a single-configuration
generator, like the Unix Makefiles one:

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
cmake --build build
```

Here are the steps for building in release mode with a multi-configuration
generator, like the Visual Studio ones:

```sh
cmake -S . -B build
cmake --build build --config Release
```

## Developing

This repository provides CMake presets to ease project setup with most common
editor and IDEs.

## Contributing

Every contribution is welcome. Remember to be respectful.

## Licensing

This project is licensed under the [MIT license](./COPYING).
