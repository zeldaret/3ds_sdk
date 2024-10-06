#include <nn/err/err.h>

#include <nn/macros.h>
#include <nn/svc/svc.h>
#include <nn/os/os.h>

extern const char fatal_err_port_name[];

namespace nn {
namespace err {
namespace CTR {

struct Request {
    u32 headerCode;
    u32 data[31];
};

struct Response {
    u32 headerCode;
    Result result;
};

namespace {

FatalErrInfo sFatalErrorInfo;
os::CriticalSection sLock;
const char* FATAL_ERR_PORT_NAME = fatal_err_port_name;
Handle sFatalErrSession;

} // anonymous namespace

namespace ANONYMOUS {

void Throw(nn::err::CTR::FatalErrInfo&);

}

Result FatalErr::Throw(const FatalErrInfo& fatalErrorInfo) {
    os::ThreadLocalInfo* threadLocalInfo;
    GET_THREAD_LOCAL_STORAGE(threadLocalInfo);
    void* ipcCommand = threadLocalInfo->ipcCommand;
    {
        Request* request = reinterpret_cast<Request*>(ipcCommand);
        request->headerCode = 0x10800;
        FatalErrInfo* info = reinterpret_cast<FatalErrInfo*>(request->data);
        *info = fatalErrorInfo;
    }
    {
        Result result = nn::svc::SendSyncRequest(mHandle);
        Response* response = reinterpret_cast<Response*>(ipcCommand);

        if (result.Failed()) {
            return result;
        } else {
            return response->result;
        }
    }
}

inline void setResult(FatalErrInfo& f, Result r) {
    f.fatalResult = r;
}

void ThrowFatalErr(Result result) {
    FatalErrInfo& fatalErrInfo = sFatalErrorInfo;

    fatalErrInfo.revisionHigh = 0;
    fatalErrInfo.revisionLow = 0x8C2F;
    fatalErrInfo.errorType = GENERIC;
    setResult(fatalErrInfo, result);
    fatalErrInfo.linkRegister = __return_address();
    ANONYMOUS::Throw(fatalErrInfo);
}

} // CTR
} // err
} // nn

// Below here: tricks to prevent data being discarded

nn::Handle& getsFatalErrSession() {
    return nn::err::CTR::sFatalErrSession;
}

nn::os::CriticalSection& getsLock() {
    return nn::err::CTR::sLock;
}

const char* getFATAL_ERR_PORT_NAME() {
    return nn::err::CTR::FATAL_ERR_PORT_NAME;
}
