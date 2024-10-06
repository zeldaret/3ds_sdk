#include <nn/svc/svc.h>

namespace nn {
namespace svc {

__asm Result CloseHandle(Handle handle) {
    svc 0x23
    bx lr
}

__asm Result SendSyncRequest(Handle handle) {
    svc 0x32
    bx lr
}

} // svc
} // nn
