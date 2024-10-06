#pragma once

#include "types.h"

namespace nn {

class Result {
public:
    Result() : mResult(0) {};

    bool Failed() const {
        return mResult & 0x80000000;
    }

    bool Succeeded() const {
        return !Failed();
    }

private:
    u32 mResult;
};

} // nn
