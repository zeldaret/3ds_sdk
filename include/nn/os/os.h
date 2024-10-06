#pragma once

#include <non_matchings.h>
#include <nn/fnd/fnd.h>
#include <nn/Handle.h>
#include <nn/Result.h>

namespace nn {

namespace os {

struct StaticBufferTranslationDescriptor {
};

struct IPCStaticBuffer {
    StaticBufferTranslationDescriptor translationDescriptor;
    void* ptr;
};

struct ThreadLocalInfo {
    char data[0x80];
    char ipcCommand[0x100];
    IPCStaticBuffer ipcStaticBuffers[0x10];
};

class StackMemoryBlock;

class MemoryBlock;

class MemoryBlockBase;

class ArbitrationType;

class ResetType;

class Semaphore {
public:
    ~Semaphore();
};

class Thread {
public:
    ~Thread();

    class AutoStackManager;

    UNK_RETURN SleepImpl(nn::fnd::TimeSpan);

    class TypeInfo {
    public:
        template<typename T>
        UNK_RETURN Destroy(void*);
        // Destroy<nn::os::ThreadPool*>(void*)
        // Destroy<mw::mo::helper::FsReader*>(void*)
        // Destroy<mw::mo::helper::PlayerGeneric*>(void*)
        // Destroy<void (*)()>(void*)
        // Destroy<unsigned int>(void*)
        // Destroy<int>(void*)

        template <typename T>
        UNK_RETURN Invoke(void (*)(unsigned int), void const*);
        // Invoke<nn::os::ThreadPool*>(void (*)(unsigned int), void const*)
        // Invoke<mw::mo::helper::FsReader*>(void (*)(unsigned int), void const*)
        // Invoke<mw::mo::helper::PlayerGeneric*>(void (*)(unsigned int), void const*)
        // Invoke<void (*)()>(void (*)(unsigned int), void const*)
        // Invoke<unsigned int>(void (*)(unsigned int), void const*)
        // Invoke<int>(void (*)(unsigned int), void const*)

        template <typename T1, typename T2>
        UNK_RETURN Copy(void const*, void*);
        // Copy<nn::os::ThreadPool*, nn::os::ThreadPool*>(void const*, void*)
        // Copy<mw::mo::helper::FsReader*, mw::mo::helper::FsReader*>(void const*, void*)
        // Copy<mw::mo::helper::PlayerGeneric*, mw::mo::helper::PlayerGeneric*>(void const*, void*)
        // Copy<void (*)(), void (*)()>(void const*, void*)
        // Copy<unsigned int, int>(void const*, void*)
        // Copy<int, int>(void const*, void*)
    };

    UNK_RETURN TryInitializeAndStartImplUsingAutoStack(nn::os::Thread::TypeInfo const&, void (*)(unsigned int), void const*, unsigned int, int, int);

    UNK_RETURN TryInitializeAndStartImpl(nn::os::Thread::TypeInfo const&, void (*)(unsigned int), void const*, unsigned int, int, int, bool);

    UNK_RETURN CallDestructorAndExit(void*);

    UNK_RETURN SetAutoStackManager(nn::os::Thread::AutoStackManager*);

    UNK_RETURN NoParameterFunc(void (*)());

    UNK_RETURN ThreadStart(unsigned int);
};

namespace detail {

UNK_RETURN Switch(nn::os::StackMemoryBlock*, nn::os::StackMemoryBlock*);

UNK_RETURN Switch(nn::os::MemoryBlock*, nn::os::MemoryBlock*);

UNK_RETURN AllocateFromMemoryBlockSpace(nn::os::MemoryBlockBase*, unsigned int);

UNK_RETURN InitializeSharedMemory();

UNK_RETURN FreeToMemoryBlockSpace(nn::os::MemoryBlockBase*);

UNK_RETURN InitializeStackMemory();

} // detail

class Mutex {
public:
    ~Mutex();
};

class Event {
    ~Event();
};

namespace {

class WaitMultipleObjectsArgs;

UNK_RETURN WaitMultipleImplWithAlloca(nn::os::WaitMultipleObjectsArgs*, int, nn::Result (*)(nn::os::WaitMultipleObjectsArgs*, nn::Handle*));

UNK_RETURN WaitMultipleImpl(nn::os::WaitMultipleObjectsArgs*, nn::Handle*);

class DefaultAutoStackManager {
public:
    ~DefaultAutoStackManager();

    UNK_RETURN FreeStack(void*);

    UNK_RETURN Construct(unsigned int);

    UNK_RETURN Destruct(void*, bool);

    UNK_RETURN InvokeOnOtherStack(unsigned int, void (*)(void*), void*, unsigned int);
};

} // (anonymous namespace)

namespace ARM {

namespace detail {

UNK_RETURN SaveThreadLocalRegionAddress();

} // detail

UNK_RETURN SpinWaitCpuCycles(int);

} // ARM

UNK_RETURN SetDefaultAutoStackManager();

namespace InterCoreCriticalSection {

UNK_RETURN EnterImpl();

} // InterCoreCriticalSection

UNK_RETURN SetupHeapForMemoryBlock(unsigned int);

UNK_RETURN GetDeviceMemoryAddress();

UNK_RETURN InitializeMemoryBlock(unsigned int, unsigned int);

UNK_RETURN InitializeAlarmSystem(int);

UNK_RETURN SetDeviceMemorySize(unsigned int);

UNK_RETURN GetDeviceMemorySize();

namespace AddressSpaceManager {

UNK_RETURN Allocate(nn::os::MemoryBlockBase*, unsigned int, unsigned int);

UNK_RETURN Switch(nn::os::MemoryBlockBase*, nn::os::MemoryBlockBase*);

UNK_RETURN Free(nn::os::MemoryBlockBase*);

} // AddressSpaceManager

namespace ThreadLocalStorage {

UNK_RETURN ClearAllSlots();

} // ThreadLocalStorage

UNK_RETURN GetUsingMemorySize();

namespace SharedMemoryBlock {

UNK_RETURN Finalize();

UNK_RETURN AttachAndMap(nn::Handle, unsigned int, bool);

} // SharedMemoryBlock

UNK_RETURN GetAppMemorySize();

namespace WaitableCounter {

UNK_RETURN Initialize();

} // WaitableCounter

class CriticalSection {
public:
    ~CriticalSection() {}

    UNK_RETURN EnterImpl();

    UNK_RETURN Leave();

    UNK_RETURN Enter();

    class ScopedLock {
    public:
        ScopedLock(nn::os::CriticalSection&);

        ~ScopedLock();
    };

    s32 mLockVariable;
    struct ThreadLocalInfo* mThreadLocalInfo;
    s32 mLockCount;
};

class MemoryBlock {
public:
    ~MemoryBlock();

    UNK_RETURN Finalize();

    UNK_RETURN Initialize(unsigned int);
};

UNK_RETURN GetHeapSize();

class WaitObject {
public:
    UNK_RETURN WaitMultiple(int*, nn::os::WaitObject**, int, bool, long long);
};

class ThreadPool {
public:
    UNK_RETURN ExecuteThreadFunc(nn::os::ThreadPool*);

    UNK_RETURN WaitThreadFunc(nn::os::ThreadPool*);

    UNK_RETURN Initialize(void*, unsigned int, unsigned int, unsigned int*, int);
};

namespace LockPolicy {

template<typename T>
class Object {
public:
    class LockObject;

    class ScopedLock {
    public:
        ScopedLock(nn::os::LockPolicy::Object<T>::LockObject const&);

        ~ScopedLock();
    };
};
// Object<nn::os::CriticalSection>

} // LockPolicy

class LightEvent {
public:
    UNK_RETURN TryWait();

    UNK_RETURN Signal();

    UNK_RETURN Wait();

    UNK_RETURN ClearSignal();
};

UNK_RETURN Initialize();

} // os

} // nn

