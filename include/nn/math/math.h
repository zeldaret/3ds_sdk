#pragma once

#include <non_matchings.h>

namespace nn {

namespace math {

class MTX34;

class VEC3;

class PivotDirection;

UNK_RETURN SinFIdx(float);

class MTX44 {
public:
    UNK_RETURN SetupOrtho(float, float, float, float, float, float, nn::math::PivotDirection);
};

namespace ARMv6 {

UNK_RETURN VEC3TransformAsm(nn::math::VEC3*, nn::math::MTX34 const*, nn::math::VEC3 const*);

UNK_RETURN MTX34InverseAsm(nn::math::MTX34*, nn::math::MTX34 const*);

UNK_RETURN MTX44MultAsm(nn::math::MTX44*, nn::math::MTX44 const*, nn::math::MTX44 const*);

UNK_RETURN MTX44CopyAsm(nn::math::MTX44*, nn::math::MTX44 const*);

UNK_RETURN MTX34MultAsm(nn::math::MTX34*, nn::math::MTX34 const*, nn::math::MTX34 const*);

UNK_RETURN MTX34CopyAsm(nn::math::MTX34*, nn::math::MTX34 const*);

} // ARMv6

UNK_RETURN MTX44FrustumPivot(nn::math::MTX44*, float, float, float, float, float, float, nn::math::PivotDirection);

UNK_RETURN MTX44Identity(nn::math::MTX44*);

UNK_RETURN MTX34Identity(nn::math::MTX34*);

} // math

} // nn

