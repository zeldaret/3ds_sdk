#pragma once

#include <non_matchings.h>
#include <nn/fs/fs.h>

namespace nn {

namespace dbm {

namespace RomPathTool {

class RomEntryName;

class PathParser {
public:
    PathParser();

    UNK_RETURN GetAsDirectoryName(nn::dbm::RomPathTool::RomEntryName*) const;

    UNK_RETURN IsDirectoryPath() const;

    UNK_RETURN GetAsFileName(nn::dbm::RomPathTool::RomEntryName*) const;

    UNK_RETURN GetNextDirectoryName(nn::dbm::RomPathTool::RomEntryName*);

    UNK_RETURN Initialize(wchar_t const*);
};

UNK_RETURN GetParentDirectoryName(nn::dbm::RomPathTool::RomEntryName*, nn::dbm::RomPathTool::RomEntryName const&, wchar_t const*);

} // RomPathTool

template <typename T1, typename T2, typename T3, typename T4>
class HierarchicalRomFileTableTemplate {
public:
    class DirectoryEntry;

    class EntryKey;

    class FileEntry;

    class RomEntryKey;

    UNK_RETURN GetDirectoryEntry(unsigned int*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::DirectoryEntry*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::EntryKey const&) const;

    UNK_RETURN FindPathRecursive(nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::EntryKey*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::DirectoryEntry*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::EntryKey*, bool, wchar_t const*) const;

    UNK_RETURN GetGrandparent(unsigned int*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::EntryKey*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::DirectoryEntry*, unsigned int, nn::dbm::RomPathTool::RomEntryName, wchar_t const*) const;

    template <typename E1, typename E2, typename E3, typename E4, typename E5>
    class EntryMapTable {
    public:
        UNK_RETURN Get(unsigned int*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::FileEntry*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::EntryKey const&) const;
        
        UNK_RETURN GetByPosition(nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::RomEntryKey*, nn::dbm::HierarchicalRomFileTableTemplate<T1, T2, T3, T4>::DirectoryEntry*, void*, unsigned int*, unsigned int) const;
    };
    // EntryMapTable<nn::fs::CTR::MPCore::detail::RomFsArchive::RomFsStorage, nn::fs::CTR::MPCore::detail::RomFsArchive::RomFsStorage, nn::dbm::HierarchicalRomFileTableTemplate::RomEntryKey, nn::dbm::HierarchicalRomFileTableTemplate::EntryKey, nn::dbm::HierarchicalRomFileTableTemplate::FileEntry>
    // EntryMapTable<nn::fs::CTR::MPCore::detail::RomFsArchive::RomFsStorage, nn::fs::CTR::MPCore::detail::RomFsArchive::RomFsStorage, nn::dbm::HierarchicalRomFileTableTemplate::RomEntryKey, nn::dbm::HierarchicalRomFileTableTemplate::EntryKey, nn::dbm::HierarchicalRomFileTableTemplate::DirectoryEntry>
};
// HierarchicalRomFileTableTemplate<nn::fs::CTR::MPCore::detail::RomFsArchive::RomFsStorage, nn::fs::CTR::MPCore::detail::RomFsArchive::RomFsStorage, nn::fs::CTR::MPCore::detail::RomFsArchive::RomFsStorage, nn::fs::CTR::MPCore::detail::RomFsArchive::RomFsStorage>

} // dbm

} // nn

