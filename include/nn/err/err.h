#pragma once

#include <non_matchings.h>
#include <nn/Handle.h>
#include <nn/Result.h>

namespace nn {

namespace err {

namespace CTR {

enum FatalErrorType {
    GENERIC,
    CORRUPTED,
    CARD_REMOVED,
    EXCEPTION,
    RESULT_FAILURE,
    LOGGED
};

enum ExceptionType {
    PREFETCH_ABORT,
    DATA_ABORT,
    UNDEFINED_EXCEPTION,
    VFP_EXCEPTION
};

struct ExceptionInfo {
    ExceptionType exceptionType;
    u32 statusRegister;
    u32 abortRegister;
    u32 fpexc;
    u32 fpinst;
    u32 fpinst2;
};

struct CPURegisters {
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc;
    u32 cpsr;
};

struct Exception {
    ExceptionInfo exceptionInfo;
    CPURegisters cpuRegisters;
};

struct Failure {
    char message[0x60];
};

union ExceptionData {
    Exception exception;
    Failure failure;
};

struct FatalErrInfo {
    FatalErrorType errorType;
    u8 revisionHigh;
    u16 revisionLow;
    Result fatalResult;
    u32 linkRegister;
    u32 processID;
    u64 titleID;
    u64 appletTitleID;
    ExceptionData data;
};

class FatalErr {
public:
    explicit FatalErr(Handle handle) : mHandle(handle) {}

    Result Throw(const FatalErrInfo& fatalErrorInfo);
private:
    Handle mHandle;
};

void ThrowFatalErr(nn::Result);

} // CTR

} // err

} // nn

