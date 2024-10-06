#pragma once

#include <non_matchings.h>
#include <nn/math/math.h>
#include <nn/Handle.h>

namespace nn {

namespace hid {

namespace CTR {

class Pad;

class PadStatus;

class GyroscopeLowCalibrateParam;

class Direction;

class Accelerometer;

class AccelerometerStatus;

class AccelerationFloat;

class TouchPanelStatus;

class Gyroscope;

class PadReader {
public:
    PadReader(nn::hid::CTR::Pad&);

    UNK_RETURN NormalizeStick(short);

    UNK_RETURN ReadLatest(nn::hid::CTR::PadStatus*);
};

UNK_RETURN GetPad();

namespace detail {

namespace Ipc {

UNK_RETURN GetGyroscopeLowRawToDpsCoefficient(float*);

UNK_RETURN GetGyroscopeLowCalibrateParam(nn::hid::CTR::GyroscopeLowCalibrateParam*);

UNK_RETURN DisableAccelerometer();

UNK_RETURN EnableAccelerometer();

UNK_RETURN DisableGyroscopeLow();

UNK_RETURN EnableGyroscopeLow();

UNK_RETURN GetIPCHandles(nn::Handle*, nn::Handle*, nn::Handle*, nn::Handle*, nn::Handle*, nn::Handle*);

} // Ipc

UNK_RETURN CalculateAccelerationTightly(short, short, short, short);

} // detail

UNK_RETURN OrthonormalizeDirection(nn::hid::CTR::Direction&, float);

class AccelerometerReader {
public:
    AccelerometerReader(nn::hid::CTR::Accelerometer&);

    ~AccelerometerReader();

    UNK_RETURN Transform(nn::hid::CTR::AccelerometerStatus*);

    UNK_RETURN Read(nn::hid::CTR::AccelerometerStatus*, int*, int);

    UNK_RETURN ResetAxisRotationMatrix();

    UNK_RETURN SetAxisRotationMatrix(nn::math::MTX34);

    UNK_RETURN ConvertToAcceleration(nn::hid::CTR::AccelerationFloat*, int, nn::hid::CTR::AccelerometerStatus const*);

    UNK_RETURN DisableAxisRotation();

    UNK_RETURN ReadLatest(nn::hid::CTR::AccelerometerStatus*);
};

namespace TouchPanelReader {

UNK_RETURN ReadLatest(nn::hid::CTR::TouchPanelStatus*);

} // TouchPanelReader

UNK_RETURN GetAccelerometer();

class GyroscopeStatus {
public:
    GyroscopeStatus();
};

class GyroscopeReader {
public:
    GyroscopeReader(nn::hid::CTR::AccelerometerReader*, nn::hid::CTR::Gyroscope&);

    ~GyroscopeReader();

    UNK_RETURN ReadLocal(nn::hid::CTR::GyroscopeStatus*, int*, int);

    UNK_RETURN Reset();

    UNK_RETURN ReviseDirection_Acceleration(nn::hid::CTR::Direction&, nn::math::VEC3 const&);

    UNK_RETURN CalculateGyroscopeAxisStatus(float*, int*, float*, int, float, int*);

    UNK_RETURN InitializeCalibrationData();

    UNK_RETURN ResetAxisRotationMatrix();

    UNK_RETURN ResetZeroDriftMode();

    UNK_RETURN CalculateDirection();

    UNK_RETURN ReadLatest(nn::hid::CTR::GyroscopeStatus*);
};

UNK_RETURN GetTouchPanel();

UNK_RETURN GetGyroscope();

UNK_RETURN Initialize();

class HidDevices {
public:
    ~HidDevices();

    UNK_RETURN Initialize(char const*);
};

} // CTR

} // hid

} // nn

