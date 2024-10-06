#pragma once

#include <non_matchings.h>
#include <nn/hid/hid.h>

namespace nn {

namespace hidlow {

namespace CTR {

namespace AccelerometerLifoRing {

UNK_RETURN ReadData(nn::hid::CTR::AccelerometerStatus*, int, int*, long long*, int*);

} // AccelerometerLifoRing

namespace TouchPanelLifoRing {

UNK_RETURN ReadData(nn::hid::CTR::TouchPanelStatus*, int, int*, long long*, int*);

} // TouchPanelLifoRing

namespace PadLifoRing {

UNK_RETURN ReadData(nn::hid::CTR::PadStatus*, int, int*, long long*, int*);

} // PadLifoRing

} // CTR

UNK_RETURN GatherStartAndSelect(nn::hid::CTR::PadStatus*);

UNK_RETURN ClampStickMinimum(short*, short*, int, int, int, int);

UNK_RETURN ClampStickCircle(short*, short*, int, int, int, int);

UNK_RETURN ClampStickCross(short*, short*, int, int, int, int);

} // hidlow

} // nn

