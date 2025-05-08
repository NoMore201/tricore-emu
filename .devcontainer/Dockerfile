FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

# Install extra development dependencies
RUN apt-get --yes update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get --no-install-recommends --yes install \
      git \
      pre-commit \
      llvm \
      clang \
      clangd \
      clang-format \
      clang-tidy \
      libclang-rt-dev \
      ca-certificates \
      curl zip unzip tar \
      gdb \
      valgrind \
      pkg-config \
      cmake \
      ninja-build \
      make \
      doxygen \
      graphviz \
      cppcheck && \
    apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*
