#pragma once

#include <non_matchings.h>

namespace nn {

namespace cfg {

namespace CTR {

UNK_RETURN Finalize();

namespace detail {

UNK_RETURN GetConfig(void*, unsigned int, unsigned int);

UNK_RETURN Finalize();

namespace IpcUser {

UNK_RETURN GetConfig(void*, unsigned int, unsigned int);

} // IpcUser

UNK_RETURN Initialize();

} // detail

UNK_RETURN GetLanguage();

UNK_RETURN Initialize();

} // CTR

} // cfg

} // nn

