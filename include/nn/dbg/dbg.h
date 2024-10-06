#pragma once

#include <non_matchings.h>

namespace nn {

namespace dbg {

class BreakReason;

void Panic();

UNK_RETURN Break(nn::dbg::BreakReason);

} // dbg

} // nn

