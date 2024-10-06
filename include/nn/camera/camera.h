#pragma once

#include <non_matchings.h>

namespace nn {

namespace camera {

namespace CTR {

class CameraSelect;

namespace detail {

namespace Camera {

UNK_RETURN Activate(nn::camera::CTR::CameraSelect);

UNK_RETURN GetActivatedCamera(nn::camera::CTR::CameraSelect*);

UNK_RETURN SetSleepCamera(nn::camera::CTR::CameraSelect);

UNK_RETURN GetSleepCamera(nn::camera::CTR::CameraSelect*);

} // Camera

UNK_RETURN ArriveApplication();

UNK_RETURN LeaveApplication();

} // detail

} // CTR

} // camera

} // nn

