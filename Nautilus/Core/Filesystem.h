#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#pragma once

#ifndef _CORE_FILESYSTEM_H_
    #define _CORE_FILESYSTEM_H_

#include "PCH.h"

namespace Nt
{
    struct NT_API Node
    {
        std::string name;
        bool isDirectory;
        Node* parent;
    };

    using NodeMap = std::unordered_map<std::string, std::unique_ptr<Node>>;

    struct NT_API File :
        public Node
    {
        std::string contents;
    };

    struct NT_API Directory :
        public Node
    {
        NodeMap children;
    };

    class NT_API Filesystem
    {
    public:
        NT_CLASS_DEFAULTS(Filesystem)
        Filesystem(void);
        Filesystem(std::string root);

        void Rescan(void);
        void CreateDirectory(const std::string& path);
        void CreateFile(const std::string& path);
        std::string ListContents(const std::string& path);
        void ChangeDirectory(const std::string& path);
        std::string GetCurrentDirectory();
        void Write(const std::string& path, const std::string& contents);
        std::string Read(const std::string& path);
        void Remove(const std::string& path);

    private:
        std::unique_ptr<Directory> m_root;
        Directory* m_current;

        Node* ResolvePath(const std::string& path);
        void SyncFromDisk(Directory* dir);
    };
} // namespace Nt

#endif // _CORE_FILESYSTEM_H_
