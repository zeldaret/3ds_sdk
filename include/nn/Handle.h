#pragma once

#include "types.h"

namespace nn {

class Handle {
public:
    Handle() : mHandle(0) {}

    explicit Handle(u32 handle) : mHandle(handle) {}

    bool IsValid() const {
        return mHandle != 0;
    }
private:
    u32 mHandle;
};

namespace {
    const u32 PSEUDO_HANDLE_CURRENT_PROCESS = 0xFFFF8001;
    const u32 INVALID_HANDLE_VALUE = 0;
}

} // nn
