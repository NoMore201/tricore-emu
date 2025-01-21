#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

GIT_REVISION="0affe8710a4a5b26328e909fe1ad7146df39d108"

if [ ! -d "$SCRIPT_DIR/third_party/vcpkg" ]; then
    cd "$SCRIPT_DIR/third_party"
    git clone https://github.com/microsoft/vcpkg.git
    cd vcpkg
    git checkout "$GIT_REVISION"
    ./bootstrap-vcpkg.sh -disableMetrics
fi
