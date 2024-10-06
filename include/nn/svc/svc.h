#pragma once

#include <non_matchings.h>
#include <nn/dbg/dbg.h>
#include <nn/os/os.h>

namespace nn {

namespace svc {

UNK_RETURN SetTimer(nn::Handle, long long, long long);

UNK_RETURN Break(nn::dbg::BreakReason);

UNK_RETURN WaitSynchronizationN(int*, nn::Handle const*, int, bool, long long);

UNK_RETURN CreateAddressArbiter(nn::Handle*);

UNK_RETURN GetResourceLimit(nn::Handle*, nn::Handle);

UNK_RETURN ArbitrateAddress(nn::Handle, unsigned int, nn::os::ArbitrationType, int);

UNK_RETURN DuplicateHandle(nn::Handle*, nn::Handle);

UNK_RETURN GetSystemTick();

UNK_RETURN ControlMemory(unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

Result ConnectToPort(nn::Handle*, char const*);

UNK_RETURN GetProcessId(unsigned int*, nn::Handle);

UNK_RETURN CreateThread(nn::Handle*, void (*)(unsigned int), unsigned int, unsigned int, int, int);

UNK_RETURN SleepThread(long long);

UNK_RETURN ExitProcess();

UNK_RETURN CreateTimer(nn::Handle*, nn::os::ResetType);

UNK_RETURN CreateMutex(nn::Handle*, bool);

UNK_RETURN CreateEvent(nn::Handle*, nn::os::ResetType);

UNK_RETURN ExitThread();

Result CloseHandle(Handle handle);

Result SendSyncRequest(Handle handle);

} // svc

} // nn

