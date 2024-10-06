#pragma once

#include <non_matchings.h>
#include <nn/Handle.h>

namespace nn {

namespace fslow {

template <typename T1, typename T2>
class LowPath {
};
// nn::fslow::LowPath<char const*, wchar_t const*>

} // fslow

namespace fs {

class PositionBase;

class WriteOption;

class Transaction;

class Attributes;

namespace detail {

class FileSystemBase;

class FileBase {
public:
    UNK_RETURN TryGetSize(long long*) const;

    UNK_RETURN TryWrite(int*, void const*, unsigned int, bool);

    UNK_RETURN TrySeek(long long, nn::fs::PositionBase);

    UNK_RETURN TryRead(int*, void*, unsigned int);

    UNK_RETURN TrySetPosition(long long);

    UNK_RETURN TrySetSize(long long);
};

UNK_RETURN RegisterGlobalFileSystemBase(nn::fs::detail::FileSystemBase&);

} // detail

namespace CTR {

namespace MPCore {

namespace detail {

class IFile;

class IArchive;

class FileServerArchive {
public:
    ~FileServerArchive();

    class File {
    public:
        ~File();

        UNK_RETURN TryGetSize(long long*) const;

        UNK_RETURN TryWrite(int*, long long, void const*, unsigned int, bool);

        UNK_RETURN TryRead(int*, long long, void*, unsigned int);

        UNK_RETURN Close();

        UNK_RETURN TrySetSize(long long);
    };

    UNK_RETURN GetIpcObject() const;

    UNK_RETURN OpenFile(nn::fs::CTR::MPCore::detail::IFile**, nn::fslow::LowPath<char const*, wchar_t const*> const&, unsigned int);

    UNK_RETURN DeleteObject();
};

namespace RomFsArchive {

class File {
public:
    ~File();

    UNK_RETURN TryGetSize(long long*) const;

    UNK_RETURN TryWrite(int*, long long, void const*, unsigned int, bool);

    UNK_RETURN TryRead(int*, long long, void*, unsigned int);

    UNK_RETURN Close();

    UNK_RETURN TrySetSize(long long);
};

UNK_RETURN OpenFile(nn::fs::CTR::MPCore::detail::IFile**, nn::fslow::LowPath<char const*, wchar_t const*> const&, unsigned int);

namespace RomFsStorage {

UNK_RETURN ReadBytes(long long, void*, unsigned int);

} // RomFsStorage

UNK_RETURN Initialize(nn::fs::CTR::MPCore::detail::IFile*, unsigned int, unsigned int, void*, unsigned int, bool);

} // RomFsArchive

UNK_RETURN OpenRom(nn::fs::CTR::MPCore::detail::IArchive**, unsigned int, unsigned int, void*, unsigned int, bool);

namespace {

UNK_RETURN QueryOptimalBucketCount(unsigned int);

} // (anonymous namespace)

UNK_RETURN OpenSpecialArchiveRaw(nn::fs::CTR::MPCore::detail::IArchive**, unsigned int);

class ContentRomFsArchive {
public:
    ContentRomFsArchive();

    ~ContentRomFsArchive();

    UNK_RETURN AllocateBuffer();

    UNK_RETURN DeleteObject();
};

class ArchiveTableEntry {
public:
    ArchiveTableEntry();
};

UNK_RETURN RegisterArchive(char const*, nn::fs::CTR::MPCore::detail::IArchive*);

namespace UserFileSystem {

UNK_RETURN CloseFile(void*);

UNK_RETURN TrySetFileSize(void*, long long);

UNK_RETURN TryGetFileSize(long long*, void const*);

UNK_RETURN TryWriteFile(int*, void*, long long, void const*, unsigned int, bool);

UNK_RETURN TryReadFile(int*, void*, long long, void*, unsigned int);

UNK_RETURN TryOpenFile(void**, wchar_t const*, unsigned int);

UNK_RETURN Initialize(nn::Handle);

} // UserFileSystem

template <typename T>
UNK_RETURN FindArchive(T const*);
// FindArchive<wchar_t>

} // detail

} // MPCore

} // CTR

class FileInputStream {
public:
    ~FileInputStream();

    UNK_RETURN GetSize() const;

    UNK_RETURN Seek(long long, nn::fs::PositionBase);

    UNK_RETURN Read(void*, unsigned int);
};

UNK_RETURN MountRom(unsigned int, unsigned int, void*, unsigned int, bool);

UNK_RETURN Unmount(char const*);

namespace ipc {

namespace File {

UNK_RETURN SetSize(long long);

UNK_RETURN GetSize(long long*);

UNK_RETURN Write(int*, long long, void const*, unsigned int, nn::fs::WriteOption);

UNK_RETURN Close();

UNK_RETURN Read(int*, long long, void*, unsigned int);

} // File

namespace FileSystem {

UNK_RETURN OpenFile(nn::Handle*, nn::fs::Transaction, unsigned long long, unsigned int, unsigned char const*, unsigned int, unsigned int, nn::fs::Attributes);

UNK_RETURN OpenFileDirectly(nn::Handle*, nn::fs::Transaction, unsigned int, unsigned int, unsigned char const*, unsigned int, unsigned int, unsigned char const*, unsigned int, unsigned int, nn::fs::Attributes);

UNK_RETURN FormatSaveData(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool);

UNK_RETURN CloseArchive(unsigned long long);

UNK_RETURN OpenArchive(unsigned long long*, unsigned int, unsigned int, unsigned char const*, unsigned int);

UNK_RETURN Initialize();

} // FileSystem

} // ipc

UNK_RETURN FormatSaveData(unsigned int, unsigned int, bool);

UNK_RETURN MountSaveData(char const*);

UNK_RETURN Initialize();

class FileStream {
public:
    ~FileStream();
};

} // fs

} // nn

