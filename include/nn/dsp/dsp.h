#pragma once

#include <non_matchings.h>
#include <nn/Handle.h>

namespace nn {

namespace dsp {

namespace CTR {

UNK_RETURN RecvData(unsigned short, unsigned short*);

UNK_RETURN WakeUp();

UNK_RETURN Sleep();

UNK_RETURN Awake();

namespace DSP {

UNK_RETURN RecvData(unsigned short, unsigned short*);

UNK_RETURN ConvertProcessAddressFromDspDram(unsigned int, unsigned int*);

UNK_RETURN RegisterInterruptEvents(nn::Handle, int, int);

UNK_RETURN GetSemaphoreEventHandle(nn::Handle*);

UNK_RETURN ReadPipeIfPossible(int, int, unsigned char*, unsigned short, unsigned short*);

UNK_RETURN GetHeadphoneStatus(bool*);

UNK_RETURN WriteProcessPipe(int, unsigned char const*, unsigned int);

UNK_RETURN SetSemaphoreMask(unsigned short);

UNK_RETURN UnloadComponent();

UNK_RETURN RecvDataIsReady(unsigned short, bool*);

UNK_RETURN FlushDataCache(nn::Handle, unsigned int, unsigned int);

UNK_RETURN LoadComponent(unsigned char const*, unsigned int, unsigned short, unsigned short, bool*);

UNK_RETURN SetSemaphore(unsigned short);

} // DSP

namespace {

UNK_RETURN SleepAcceptedCallback(unsigned int);

} // (anonymous namespace)

UNK_RETURN ConvertProcessAddressFromDspDram(unsigned int, unsigned int*);

UNK_RETURN RegisterSleepWakeUpCallback(void (*)(), void (*)(), void (*)());

UNK_RETURN RegisterInterruptEvents(nn::Handle, int, int);

UNK_RETURN GetSemaphoreEventHandle(nn::Handle*);

UNK_RETURN OrderToWaitForFinalize();

UNK_RETURN SetSemaphoreEventMask(unsigned short);

UNK_RETURN LoadDefaultComponent();

UNK_RETURN ReadPipeIfPossible(int, void*, unsigned short, unsigned short*);

UNK_RETURN GetHeadphoneStatus(bool*);

UNK_RETURN IsComponentLoaded();

UNK_RETURN WriteProcessPipe(int, void const*, unsigned int);

UNK_RETURN RecvDataIsReady(unsigned short, bool*);

UNK_RETURN FlushDataCache(unsigned int, unsigned int);

UNK_RETURN SetSemaphore(unsigned short);

UNK_RETURN Initialize();

} // CTR

} // dsp

} // nn

