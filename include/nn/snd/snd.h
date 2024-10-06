#pragma once

#include <non_matchings.h>
#include <nn/fnd/fnd.h>

namespace nn {

namespace snd {

namespace CTR {

class WaveBuffer;

class SampleFormat;

class AdpcmParam;

class MixParam;

class DspsndAudioInfo;

class SurroundSpeakerPosition;

class FilterType;

class OutputMode;

class DspsndMasterPlayParam;

class AuxBusId;

class DspFxDelayParams;

class DspFxReverbParams;

class ClippingMode;

class AuxBusData;

class DspsndDspCycles;

class DspsndChannelPlayVars;

class Voice {
public:
    Voice(int);

    class State;

    UNK_RETURN IsPlaying() const;

    UNK_RETURN GetPlayPosition() const;

    UNK_RETURN SetVolume(float);

    UNK_RETURN SetState(nn::snd::CTR::Voice::State);

    UNK_RETURN SetPitch(float);

    UNK_RETURN AppendWaveBuffer(nn::snd::CTR::WaveBuffer*);

    UNK_RETURN SetSampleFormat(nn::snd::CTR::SampleFormat);

    UNK_RETURN SetChannelCount(int);

    UNK_RETURN SetSampleRate(int);

    UNK_RETURN SetAdpcmParam(nn::snd::CTR::AdpcmParam const&);

    UNK_RETURN SetMixParam(nn::snd::CTR::MixParam const&);

    UNK_RETURN Initialize();
};

class VoiceImpl {
public:
    VoiceImpl(int);

    UNK_RETURN GetPlayPosition() const;

    UNK_RETURN SetVolume(float);

    UNK_RETURN SetState(nn::snd::CTR::Voice::State);

    UNK_RETURN SetPitch(float);

    UNK_RETURN Start();

    UNK_RETURN UpdateWaveBufferStatus(unsigned short);

    UNK_RETURN UpdateWaveBufferList();

    UNK_RETURN ReleaseWaveBuffer();

    UNK_RETURN ForceUpdateParams();

    UNK_RETURN AppendWaveBuffer(nn::snd::CTR::WaveBuffer*);

    UNK_RETURN SetSampleFormat(nn::snd::CTR::SampleFormat);

    UNK_RETURN SetChannelCount(int);

    UNK_RETURN SendWaveBuffer();

    UNK_RETURN SetSampleRate(int);

    UNK_RETURN SetAdpcmParam(nn::snd::CTR::AdpcmParam const&);

    UNK_RETURN UpdateStatus(void const*);

    UNK_RETURN UpdateParams();

    UNK_RETURN SetSyncCount();

    UNK_RETURN SetMixVolume();

    UNK_RETURN SetMixParam(nn::snd::CTR::MixParam const&);

    UNK_RETURN Initialize();
};

UNK_RETURN FreeVoice(nn::snd::CTR::Voice*);

namespace FxReverb {

UNK_RETURN UpdateBuffer(unsigned int);

} // FxReverb

namespace FxDelay {

UNK_RETURN UpdateBuffer(unsigned int);

} // FxDelay

UNK_RETURN WakeUp();

class Dspsnd {
public:
    ~Dspsnd();

    UNK_RETURN AssignPCM(unsigned char, nn::snd::CTR::WaveBuffer const*, int, nn::snd::CTR::DspsndAudioInfo, unsigned short);

    UNK_RETURN WaitPipe();

    UNK_RETURN WaitPipe(nn::fnd::TimeSpan);

    UNK_RETURN Finalize(bool);

    UNK_RETURN SetIsApplyBugFixFor5msDelay(bool);

    UNK_RETURN InitializeChannelParameters(unsigned char);

    UNK_RETURN SetSurroundSpeakerPosition(nn::snd::CTR::SurroundSpeakerPosition);

    UNK_RETURN SetChannelIIRFilter_Biquad(unsigned char, short, short, short, short, short);

    UNK_RETURN SetChannelIIRFilter_Mono(unsigned char, short, short);

    UNK_RETURN SetChannelIirFilterType(unsigned char, nn::snd::CTR::FilterType);

    UNK_RETURN AppendChannelNextBuffer(unsigned char, nn::snd::CTR::WaveBuffer const*, int, int, unsigned short);

    UNK_RETURN SetIsHeadsetConnected(bool);

    UNK_RETURN SetChannelAdpcmParam(unsigned char, nn::snd::CTR::AdpcmParam const*);

    UNK_RETURN GetDroppedFrameCount();

    UNK_RETURN SetChannelSyncCount(unsigned char, short);

    UNK_RETURN SetChannelPlayStart(unsigned char);

    UNK_RETURN MakeCompressorTable(float, unsigned short, unsigned short*);

    UNK_RETURN InitializeVariables(bool);

    UNK_RETURN SetSoundOutputMode(nn::snd::CTR::OutputMode);

    UNK_RETURN SetMasterPlayParam(unsigned int, nn::snd::CTR::DspsndMasterPlayParam const*);

    UNK_RETURN SetDspReverbEffect(nn::snd::CTR::AuxBusId, nn::snd::CTR::DspFxReverbParams&);

    UNK_RETURN SetChannelPlayStop(unsigned char);

    UNK_RETURN SetAuxReturnVolume(nn::snd::CTR::AuxBusId, float);

    UNK_RETURN SetDspDelayEffect(nn::snd::CTR::AuxBusId, nn::snd::CTR::DspFxDelayParams&);

    UNK_RETURN SetAuxFrontBypass(nn::snd::CTR::AuxBusId, bool);

    UNK_RETURN SetSurroundDepth(unsigned short);

    UNK_RETURN SetMasterVolume(float);

    UNK_RETURN SetClippingMode(nn::snd::CTR::ClippingMode);

    UNK_RETURN SetChannelTimer(unsigned char, float);

    UNK_RETURN SyncFrameData();

    UNK_RETURN SetChannelRIM(unsigned char, unsigned short, unsigned short);

    UNK_RETURN SetChannelMix(unsigned char, nn::snd::CTR::MixParam const*);

    UNK_RETURN SendParameter();

    UNK_RETURN SetRearRatio(unsigned short);

    UNK_RETURN EnableAuxBus(nn::snd::CTR::AuxBusId, bool);

    UNK_RETURN Initialize(bool);
};

UNK_RETURN Sleep();

namespace Bcwav {

UNK_RETURN GetWave(void const*, int);

UNK_RETURN GetDspAdpcmInfo(void const*, int);

UNK_RETURN GetChannelCount(void const*);

UNK_RETURN GetWaveInfo(void const*);

} // Bcwav

UNK_RETURN OrderToWaitForFinalize();

UNK_RETURN InitializeWaveBuffer(nn::snd::CTR::WaveBuffer*);

UNK_RETURN ConvertAdpcmNib2Pos(unsigned int);

UNK_RETURN SetSoundOutputMode(nn::snd::CTR::OutputMode);

UNK_RETURN SendParameterToDsp();

UNK_RETURN GetHeadphoneStatus();

class MasterManagerImpl {
public:
    ~MasterManagerImpl();

    UNK_RETURN SetIsHeadsetConnected(bool);

    UNK_RETURN RegisterAuxCallback(nn::snd::CTR::AuxBusId, void (*)(nn::snd::CTR::AuxBusData*, int, unsigned int), unsigned int);

    UNK_RETURN SetSoundOutputMode(nn::snd::CTR::OutputMode);

    UNK_RETURN ForceUpdateParams();

    UNK_RETURN SetMasterVolume(float);

    UNK_RETURN InitializeParam();

    UNK_RETURN AuxUserCallback(nn::snd::CTR::AuxBusId, unsigned int);

    UNK_RETURN Initialize();
};

namespace DspFxManagerImpl {

UNK_RETURN ForceUpdateParams();

UNK_RETURN GetInstance();

UNK_RETURN Initialize();

} // DspFxManagerImpl

UNK_RETURN SetMasterVolume(float);

UNK_RETURN GetSampleLength(int, nn::snd::CTR::SampleFormat, int);

UNK_RETURN WaitForDspSync();

UNK_RETURN FlushDataCache(unsigned int, unsigned int);

namespace OutputCapture {

UNK_RETURN Write(short*, int);

} // OutputCapture

class MasterManager {
public:
    ~MasterManager();

    UNK_RETURN UpdateDroppedSoundFrameCount();

    UNK_RETURN SetIsHeadsetConnected(bool);

    UNK_RETURN SetSoundOutputMode(nn::snd::CTR::OutputMode);

    UNK_RETURN SetMasterVolume(float);

    UNK_RETURN AuxUserCallback(nn::snd::CTR::AuxBusId, unsigned int);

    UNK_RETURN ExecuteEffect(nn::snd::CTR::AuxBusId, unsigned int);

    UNK_RETURN GetDspCycles();

    UNK_RETURN Initialize();
};

class VoiceManager {
public:
    ~VoiceManager();

    UNK_RETURN FreeVoice(nn::snd::CTR::Voice*);

    UNK_RETURN UpdateWaveBufferList();

    UNK_RETURN AdjustVoicePlayState(int);

    UNK_RETURN ForceUpdateParams();

    UNK_RETURN UpdateDspCycles(nn::snd::CTR::DspsndDspCycles*);

    UNK_RETURN UpdateStatus(int, nn::snd::CTR::DspsndChannelPlayVars const*);

    UNK_RETURN UpdateParams();

    UNK_RETURN Initialize();

    UNK_RETURN AllocVoice(int, void (*)(nn::snd::CTR::Voice*, unsigned int), unsigned int);
};

namespace DspFxManager {

UNK_RETURN GetDspCycles();

UNK_RETURN GetInstance();

UNK_RETURN Initialize();

} // DspFxManager

class WaveBuffer {
public:
    WaveBuffer();
};

UNK_RETURN Initialize();

UNK_RETURN AllocVoice(int, void (*)(nn::snd::CTR::Voice*, unsigned int), unsigned int);

} // CTR

} // snd

} // nn

