FROM mcr.microsoft.com/devcontainers/base:jammy

ARG DEFAULT_UID=1000
ARG DEFAULT_GID=1000

# Install extra development dependencies
RUN apt-get --yes update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get --no-install-recommends --yes install \
      git \
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
  
RUN wget -O /usr/share/keyrings/llvm-snapshot.gpg.key https://apt.llvm.org/llvm-snapshot.gpg.key && \
    echo "deb [signed-by=/usr/share/keyrings/llvm-snapshot.gpg.key] http://apt.llvm.org/jammy/ llvm-toolchain-jammy-18 main" | tee -a /etc/apt/sources.list.d/llvm.list && \
    apt-get update && \
    apt-get install -y llvm-18 clang-18 lldb-18 clang-tidy-18 clang-format-18 && \
    apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*
