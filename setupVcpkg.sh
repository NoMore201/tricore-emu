#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

GIT_REVISION="9e8416f15d93fa9347e3291bd8c128dd44200ba5"

if [ ! -d "$SCRIPT_DIR/third_party/vcpkg" ]; then
    cd "$SCRIPT_DIR/third_party"
    git clone https://github.com/microsoft/vcpkg.git
    cd vcpkg
    git checkout "$GIT_REVISION"
    ./bootstrap-vcpkg.sh -disableMetrics
fi
