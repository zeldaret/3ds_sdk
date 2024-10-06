#pragma once

#include <non_matchings.h>
#include <nn/Handle.h>

namespace nn {

namespace gxlow {

namespace CTR {

class DisplayCaptureInfo;

UNK_RETURN Unlock();

namespace detail {

class CmdReq;

UNK_RETURN GetGpuIpc();

UNK_RETURN GetInterruptReceiver();

UNK_RETURN IsFatalErrMode();

UNK_RETURN IsInitialized();

UNK_RETURN IsAppletMode();

} // detail

UNK_RETURN Lock();

namespace Gpu {

UNK_RETURN RegisterInterruptRelayQueue(nn::Handle, unsigned int, nn::Handle*, int*);

UNK_RETURN ImportDisplayCaptureInfo(nn::gxlow::CTR::DisplayCaptureInfo*);

UNK_RETURN WriteHWRegsWithMask(unsigned int, unsigned char const*, unsigned char const*, unsigned int);

UNK_RETURN TriggerCmdReqQueue();

UNK_RETURN RestoreVramSysArea();

UNK_RETURN SetLcdForceBlack(bool);

UNK_RETURN SaveVramSysArea();

UNK_RETURN ReleaseRight();

UNK_RETURN AcquireRight(nn::Handle, bool);

UNK_RETURN WriteHWRegs(unsigned int, unsigned char const*, unsigned int);

UNK_RETURN ReadHWRegs(unsigned int, unsigned char*, unsigned int);

} // Gpu

UNK_RETURN GetNumSpeculativeRequests();

UNK_RETURN RegisterInterruptHandler(void (*)(), UNK_TYPE nngxlowInterrupt);

UNK_RETURN ImportDisplayCaptureInfo(nn::gxlow::CTR::DisplayCaptureInfo*);

UNK_RETURN IsFirstInitialization();

UNK_RETURN WriteHWRegsWithMask(unsigned int, void const*, void const*, unsigned int);

UNK_RETURN SetDisplayTransfer(void*, unsigned short, unsigned short, void*, unsigned short, unsigned short, unsigned int);

UNK_RETURN RestoreVramSysArea();

class InterruptReceiver {
public:
    ~InterruptReceiver();

    UNK_RETURN WaitAnyHandlerDone();

    UNK_RETURN ReceiverThreadFunc(unsigned int);

    UNK_RETURN Initialize();
};

UNK_RETURN StartLcdDisplay();

UNK_RETURN SaveVramSysArea();

UNK_RETURN ReleaseGpuRight();

UNK_RETURN GetPhysicalAddr(unsigned int);

UNK_RETURN AcquireGpuRight();

UNK_RETURN SetTextureCopy(void*, void*, unsigned int, unsigned short, unsigned short, unsigned short, unsigned short, unsigned int);

UNK_RETURN SetCommandlist(void*, unsigned int, bool, bool);

UNK_RETURN SetMemoryFill(void*, void*, unsigned int, unsigned int, void*, void*, unsigned int, unsigned int);

UNK_RETURN SetBufferSwap(int, int, void*, void*, unsigned int, unsigned int, unsigned int);

UNK_RETURN SetAppletMode();

namespace CmdReqQueueTx {

UNK_RETURN TryEnqueue(nn::gxlow::CTR::detail::CmdReq const*);

UNK_RETURN Initialize(void*);

} // CmdReqQueueTx

UNK_RETURN YieldThread();

UNK_RETURN WriteHWRegs(unsigned int, void const*, unsigned int);

UNK_RETURN RequestDma(void*, void const*, unsigned int, bool, bool);

UNK_RETURN ReadHWRegs(unsigned int, void*, unsigned int);

UNK_RETURN Initialize();

} // CTR

} // gxlow

} // nn

