#pragma once

#include <non_matchings.h>
#include <nn/dbg/dbg.h>
#include <nn/Handle.h>

namespace nn {

namespace srv {

class NotificationHandler;

namespace detail {

namespace Service {

UNK_RETURN ReceiveNotification(unsigned int*);

UNK_RETURN EnableNotification(nn::Handle*);

UNK_RETURN GetServiceHandle(nn::Handle*, char const*, int, unsigned int);

UNK_RETURN RegisterClient();

} // Service

class HandlerManager {
public:
    ~HandlerManager();
};

} // detail

namespace {

UNK_RETURN DispatcherThread();

} // (anonymous namespace)

template <typename T>
class EventNotificationHandlerBase {
public:
    ~EventNotificationHandlerBase();

    UNK_RETURN HandleNotification(unsigned int);
};
// EventNotificationHandlerBase<nn::os::LightEvent>

UNK_RETURN RegisterNotificationHandler(nn::srv::NotificationHandler*, unsigned int);

UNK_RETURN StartNotification();

UNK_RETURN GetServiceHandle(nn::Handle*, char const*, int, unsigned int);

UNK_RETURN Initialize();

} // srv

} // nn

