#pragma once

#include <non_matchings.h>
#include <nn/fnd/fnd.h>
#include <nn/Handle.h>
#include <nn/Result.h>

namespace nn {

namespace applet {

namespace CTR {

class Notification;

class AppletPos;

class QueryReply;

class WakeupState;

class CaptureBufferInfo;

class AppletDisplayInfo;

class TransitionType;

namespace detail {

UNK_RETURN SetActive();

UNK_RETURN IsActive();

UNK_RETURN Receive(unsigned int*, unsigned int*, unsigned char*, unsigned int, int*, nn::Handle*, nn::fnd::TimeSpan);

UNK_RETURN Connect();

UNK_RETURN Glance(unsigned int*, unsigned int*, unsigned char*, unsigned int, int*, nn::Handle*);

UNK_RETURN Enable(bool);

namespace APPLET {

UNK_RETURN Enable(unsigned int);

UNK_RETURN ReplySleepNotificationComplete(unsigned int);

UNK_RETURN PrepareToStartSystemApplet(unsigned int);

UNK_RETURN PrepareToCloseApplication(bool);

UNK_RETURN PrepareToJumpToHomeMenu();

UNK_RETURN SendCaptureBufferInfo(unsigned char const*, unsigned int);

UNK_RETURN InquireNotification(unsigned int, nn::applet::CTR::Notification*);

UNK_RETURN CancelLibraryApplet(bool);

UNK_RETURN StartSystemApplet(unsigned int, unsigned char const*, unsigned int, nn::Handle);

UNK_RETURN ReceiveParameter(unsigned int*, unsigned int, unsigned int*, unsigned char*, unsigned int, int*, nn::Handle*);

UNK_RETURN GetAppletManInfo(nn::applet::CTR::AppletPos, nn::applet::CTR::AppletPos*, unsigned int*, unsigned int*, unsigned int*);

UNK_RETURN CloseApplication(unsigned char const*, unsigned int, nn::Handle);

UNK_RETURN ReplySleepQuery(unsigned int, nn::applet::CTR::QueryReply);

UNK_RETURN GlanceParameter(unsigned int*, unsigned int, unsigned int*, unsigned char*, unsigned int, int*, nn::Handle*);

UNK_RETURN CancelParameter(bool, unsigned int, bool, unsigned int, bool*);

UNK_RETURN JumpToHomeMenu(unsigned char const*, unsigned int, nn::Handle);

UNK_RETURN SendParameter(unsigned int, unsigned int, unsigned int, unsigned char const*, unsigned int, nn::Handle);

UNK_RETURN GetLockHandle(nn::Handle*, unsigned int, unsigned int*, unsigned int*);

UNK_RETURN AppletUtility(unsigned int, unsigned char const*, unsigned int, unsigned char*, unsigned int, int*);

UNK_RETURN NotifyToWait(unsigned int);

UNK_RETURN IsRegistered(unsigned int, bool*);

UNK_RETURN SleepSystem(unsigned long long);

UNK_RETURN Initialize(unsigned int, unsigned int, nn::Handle*, nn::Handle*);

} // APPLET

UNK_RETURN Send(unsigned int, unsigned int, unsigned char const*, unsigned int, nn::Handle, nn::fnd::TimeSpan);

UNK_RETURN Lock();

UNK_RETURN ReplySleepNotificationCompleteToManager();

UNK_RETURN CancelLibraryAppletIfRegistered(bool, nn::applet::CTR::WakeupState*);

UNK_RETURN ClearAbsoluteHomeButtonState();

UNK_RETURN CaptureScreenForSystemApplet(unsigned int);

UNK_RETURN PrepareToStartSystemApplet(unsigned int);

UNK_RETURN GetAbsoluteHomeButtonState();

UNK_RETURN PrepareToCloseApplication(bool);

namespace PreloadLibraryApplet_Func {

UNK_RETURN CancelCore();

} // PreloadLibraryApplet_Func

UNK_RETURN ReplySleepQueryToManager(nn::applet::CTR::QueryReply);

UNK_RETURN PrepareToJumpToHomeMenu();

UNK_RETURN ExecFunctionTillSuccess(nn::Result (*)(), nn::fnd::TimeSpan);

namespace StartSystemApplet_Func {

UNK_RETURN StartCore();

UNK_RETURN PrepareCore();

} // StartSystemApplet_Func

UNK_RETURN SendCaptureBufferInfo(unsigned char const*, unsigned int);

namespace CloseApplication_Func {

UNK_RETURN CloseCore();

UNK_RETURN PrepareCore();

} // CloseApplication_Func

UNK_RETURN CalcCaptureBufferInfo(nn::applet::CTR::CaptureBufferInfo*);

UNK_RETURN GetOrderToCloseState();

UNK_RETURN FinalizeClientThread();

UNK_RETURN WaitToCaptureScreen(unsigned int, nn::Handle*);

namespace JumpToHomeMenu_Func {

UNK_RETURN PrepareCore();

} // JumpToHomeMenu_Func

UNK_RETURN GetPowerButtonState();

UNK_RETURN SleepIfShellClosed();

UNK_RETURN SetReceiveCallback(bool (*)(unsigned int), unsigned int);

UNK_RETURN RestoreVramSysArea();

UNK_RETURN ClearSleepSysState();

UNK_RETURN TryLockTransition(unsigned int);

UNK_RETURN StartSystemApplet(unsigned int, unsigned char const*, unsigned int, nn::Handle);

UNK_RETURN ProcessHomeButton();

UNK_RETURN InitializeConnect(unsigned int, unsigned int, int);

UNK_RETURN AssignCameraRight(bool);

UNK_RETURN UnlockTransition(unsigned int);

UNK_RETURN GetSleepSysState();

UNK_RETURN GetAppletManInfo(nn::applet::CTR::AppletPos, nn::applet::CTR::AppletPos*, unsigned int*, unsigned int*, unsigned int*);

UNK_RETURN CloseApplication(unsigned char const*, unsigned int, nn::Handle);

UNK_RETURN WaitForStarting(unsigned int*, unsigned char*, unsigned int, int*, nn::Handle*, nn::fnd::TimeSpan);

UNK_RETURN WaitForRegister(unsigned int, nn::fnd::TimeSpan);

UNK_RETURN CancelParameter(bool, unsigned int, bool, unsigned int);

UNK_RETURN JumpToHomeMenu(unsigned char const*, unsigned int, nn::Handle);

UNK_RETURN GetDisplayInfo(nn::applet::CTR::AppletDisplayInfo*);

UNK_RETURN AssignGpuRight(bool);

UNK_RETURN AssignDspRight(bool);

UNK_RETURN NotifyToWait();

UNK_RETURN IsRegistered(unsigned int);

UNK_RETURN SetInactive();

UNK_RETURN CallUtility(unsigned int, unsigned char const*, unsigned int, unsigned char*, unsigned int, int*);

UNK_RETURN TryReceive(unsigned int*, unsigned int*, unsigned char*, unsigned int, int*, nn::Handle*, bool);

UNK_RETURN ThreadFunc(int);

UNK_RETURN Initialize(unsigned int);

UNK_RETURN Disconnect();

} // detail

UNK_RETURN SetReceivedWakeupByCancelFlag();

UNK_RETURN IsExpectedToProcessHomeButton();

namespace SysSleepAcceptedCallbackInfo {

UNK_RETURN Register();

} // SysSleepAcceptedCallbackInfo

UNK_RETURN ClearPowerButtonCallbackFlag();

UNK_RETURN ProcessSleepAcceptedCommand();

UNK_RETURN IsToCallPowerButtonCallback();

UNK_RETURN ClearSleepNotificationState();

UNK_RETURN ReceiveCallbackForCommands(unsigned int);

UNK_RETURN GetSleepNotificationState();

UNK_RETURN ClearShutdownCallbackFlag();

UNK_RETURN IsToCallShutdownCallback();

UNK_RETURN IsReceivedWakeupByCancel();

UNK_RETURN SetTransitionCallback(void (*)(unsigned int), unsigned int);

UNK_RETURN SetSleepQueryCallback(nn::applet::CTR::QueryReply (*)(unsigned int), unsigned int);

UNK_RETURN ClearHomeButtonState();

UNK_RETURN SetShutdownCallback(void (*)(unsigned int), unsigned int);

UNK_RETURN ProcessPowerButton();

UNK_RETURN SetTransitionType(nn::applet::CTR::TransitionType);

UNK_RETURN InitializeWrapper();

UNK_RETURN GetTransitionType();

UNK_RETURN SetAwakeCallback(void (*)(unsigned int), unsigned int);

UNK_RETURN ReplySleepQuery(nn::applet::CTR::QueryReply);

UNK_RETURN CloseAppletHook();

UNK_RETURN IsInitialized();

UNK_RETURN IsEnableSleep();

UNK_RETURN GetAppletType();

UNK_RETURN DisableSleep(bool);

UNK_RETURN EnableSleep(bool);

} // CTR

} // applet

} // nn

