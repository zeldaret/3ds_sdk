#pragma once

#include <non_matchings.h>
#include <nn/math/math.h>

namespace nn {

namespace ulcd {

namespace CTR {

class StereoCamera {
public:
    StereoCamera();

    ~StereoCamera();

    UNK_RETURN GetParallax(float) const;

    UNK_RETURN CalculateMatricesReal(nn::math::MTX44*, nn::math::MTX34*, nn::math::MTX44*, nn::math::MTX34*, float, float, nn::math::PivotDirection);

    UNK_RETURN SetBaseFrustum(nn::math::MTX44 const*);

    UNK_RETURN SetBaseCamera(nn::math::MTX34 const*);

    UNK_RETURN Initialize();
};

namespace {

class Direction;

UNK_RETURN GetLookPose(nn::math::MTX34 const*, nn::math::VEC3*, nn::ulcd::CTR::Direction*);

} // (anonymous namespace)

} // CTR

} // ulcd

} // nn

