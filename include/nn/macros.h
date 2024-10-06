#pragma once

#define GET_THREAD_LOCAL_STORAGE(r) __asm { mrc p15, 0, r, c13, c0, 3 }
