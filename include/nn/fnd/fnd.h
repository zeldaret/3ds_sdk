#pragma once

#include <non_matchings.h>

namespace nn {

namespace fnd {

class HeapBase {
public:
    ~HeapBase();

    UNK_RETURN FillMemory32(unsigned int, unsigned int, unsigned int);
};

namespace detail {

class NNSFndList;

class ExpHeapImpl;

class NNSiFndExpHeapHead;

class NNSiFndExpHeapMBlockHead;

class NNSiMemRegion;

UNK_RETURN InitList(nn::fnd::detail::NNSFndList*, unsigned short);

UNK_RETURN UseMarginOfAlignmentForHeap(nn::fnd::detail::ExpHeapImpl*, bool);

UNK_RETURN AllocUsedBlockFromFreeBlock(nn::fnd::detail::NNSiFndExpHeapHead*, nn::fnd::detail::NNSiFndExpHeapMBlockHead*, void*, unsigned int, unsigned short);

UNK_RETURN NNSi_FndInitHeapHead(nn::fnd::detail::ExpHeapImpl*, unsigned int, void*, void*, unsigned short);

UNK_RETURN NNSi_FndFinalizeHeap(nn::fnd::detail::ExpHeapImpl*);

UNK_RETURN SetAllocModeForHeap(nn::fnd::detail::ExpHeapImpl*, unsigned short);

UNK_RETURN SetGroupIDForHeap(nn::fnd::detail::ExpHeapImpl*, unsigned short);

UNK_RETURN GetNextListObject(nn::fnd::detail::NNSFndList const*, void const*);

UNK_RETURN RemoveListObject(nn::fnd::detail::NNSFndList*, void*);

UNK_RETURN AppendListObject(nn::fnd::detail::NNSFndList*, void*);

UNK_RETURN FindContainHeap(nn::fnd::detail::NNSFndList*, void const*);

UNK_RETURN RecycleRegion(nn::fnd::detail::NNSiFndExpHeapHead*, nn::fnd::detail::NNSiMemRegion const*);

UNK_RETURN AllocFromHeap(nn::fnd::detail::ExpHeapImpl*, unsigned int, int);

UNK_RETURN DestroyHeap(nn::fnd::detail::ExpHeapImpl*);

UNK_RETURN FreeToHeap(nn::fnd::detail::ExpHeapImpl*, void*);

UNK_RETURN CreateHeap(nn::fnd::detail::ExpHeapImpl*, void*, unsigned int, unsigned short);

} // detail

template <typename T>
class UnitHeapTemplate {
public:
    ~UnitHeapTemplate();

    UnitHeapTemplate(unsigned int, unsigned int, unsigned int, int, unsigned int);

    UNK_RETURN Allocate();

    UNK_RETURN Free(void*);
};
// UnitHeapTemplate<nn::os::LockPolicy::Object<nn::os::CriticalSection> >

template <typename T>
class ExpHeapTemplate {
public:
    ~ExpHeapTemplate();
};
// ExpHeapTemplate<nn::os::LockPolicy::NoLock>

namespace UnitHeapBase {

UNK_RETURN Initialize(unsigned int, unsigned int, unsigned int, int, unsigned int);

} // UnitHeapBase

namespace ExpHeapBase {

class AllocationMode;

UNK_RETURN Finalize();

UNK_RETURN Allocate(unsigned int, int, unsigned char, nn::fnd::ExpHeapBase::AllocationMode, bool);

UNK_RETURN Free(void*);

UNK_RETURN Initialize(unsigned int, unsigned int, unsigned int);

} // ExpHeapBase

class TimeSpan;

} // fnd

} // nn

