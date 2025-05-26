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

#ifndef _CORE_FILESYSTEM_CPP_
    #define _CORE_FILESYSTEM_CPP_

#include "Filesystem.h"
#include "Logger.h"

namespace Nt
{
    Filesystem::Filesystem(void)
        : m_root(std::make_unique<Directory>())
    {
        m_root->name        = ".";
        m_root->isDirectory = true;
        m_root->parent      = nullptr;
        m_current           = m_root.get();

        if (!std::filesystem::exists(m_root->name))
            std::filesystem::create_directory(m_root->name);

        SyncFromDisk(m_root.get());
    }

    Filesystem::Filesystem(std::string root)
        : m_root(std::make_unique<Directory>())
    {
        m_root->name        = root;
        m_root->isDirectory = true;
        m_root->parent      = nullptr;
        m_current           = m_root.get();

        if (!std::filesystem::exists(m_root->name))
            std::filesystem::create_directory(m_root->name);

        SyncFromDisk(m_root.get());
    }

    void Filesystem::Rescan(void)
    {
        SyncFromDisk(m_root.get());
    }

    void Filesystem::CreateDirectory(const std::string& path)
    {
        if (m_current->children.count(path) != 0)
        {
            Logger::Error("Directory already exists: %s", path);
            return;
        }

        std::filesystem::create_directory(std::filesystem::path(m_current->name) / path);
        m_current->children[path]              = std::make_unique<Directory>();
        m_current->children[path]->name        = path;
        m_current->children[path]->isDirectory = true;
        m_current->children[path]->parent      = m_current;
    }

    void Filesystem::CreateFile(const std::string& path)
    {
        if (m_current->children.count(path) != 0)
        {
            Logger::Error("File already exists: %s", path);
            return;
        }

        std::ofstream ofs(std::filesystem::path(m_current->name) / path);

        if (!ofs.is_open())
        {
            Logger::Error("Failed to open file: %s", path);
            return;
        }

        m_current->children[path]              = std::make_unique<File>();
        m_current->children[path]->name        = path;
        m_current->children[path]->isDirectory = false;
        m_current->children[path]->parent      = m_current;
    }

    std::string Filesystem::ListContents(const std::string& path)
    {
        std::string result = "";

        for (const auto& [name, node] : m_current->children)
            result += (node->isDirectory ? "[DIR] " : "[FILE] ") + name + "\n";

        return result;
    }

    void Filesystem::ChangeDirectory(const std::string& path)
    {
        Node* node = ResolvePath(path);

        if (node == nullptr || !node->isDirectory)
        {
            Logger::Error("Invalid directory: %s", path);
            return;
        }

        m_current = NT_STATIC_CAST(Directory*, node);
    }

    std::string Filesystem::GetCurrentDirectory()
    {
        std::vector<std::string> names;
        const Node* node = m_current;

        while (node && node->parent)
        {
            names.push_back(node->name);
            node = node->parent;
        }

        std::string result = "/";

        for (auto it = names.rbegin(); it != names.rend(); ++it)
            result += (*it + "/");

        return result;
    }

    void Filesystem::Write(const std::string& path, const std::string& contents)
    {
        std::ofstream ofs(std::filesystem::path(m_current->name) / path);

        if (!ofs.is_open())
        {
            Logger::Error("Failed to open file: %s", path);
            return;
        }

        NodeMap::iterator it = m_current->children.find(path);

        if (it == m_current->children.end() || it->second->isDirectory)
        {
            Logger::Error("File not found or is a directory: %s", path);
            return;
        }

        NT_STATIC_CAST(File*, it->second.get())->contents = contents;
        ofs << contents;
    }

    std::string Filesystem::Read(const std::string& path)
    {
        std::ifstream ifs(std::filesystem::path(m_current->name) / path);

        if (!ifs.is_open())
        {
            Logger::Error("Failed to open file: %s", path);
            return "";
        }

        std::stringstream buffer;
        NodeMap::iterator it = m_current->children.find(path);

        if (it == m_current->children.end() || it->second->isDirectory)
        {
            Logger::Error("File not found or is a directory: %s", path);
            return "";
        }

        buffer << ifs.rdbuf();
        return buffer.str();
    }

    void Filesystem::Remove(const std::string& path)
    {
        std::filesystem::remove_all(std::filesystem::path(m_current->name) / path);

        if (m_current->children.erase(path) == 0)
        {
            Logger::Error("File or directory not found: %s", path);
            return;
        }
    }

    Node* Filesystem::ResolvePath(const std::string& path)
    {
        if (path.empty())
            return nullptr;

        Directory* dir = (path[0] == '/') ? m_root.get() : m_current;
        std::stringstream ss(path);
        std::string segment;
        Node* node     = dir;

        while (std::getline(ss, segment, '/'))
        {
            if (segment == ".")
                continue;
            else if (segment == "..")
            {
                if (node->parent)
                    node = node->parent;
                continue;
            }

            if (!node->isDirectory)
                return nullptr;

            NodeMap& children = NT_STATIC_CAST(Directory*, node)->children;

            if (children.count(segment) == 0)
                return nullptr;

            node = children[segment].get();
        }

        return node;
    }

    void Filesystem::SyncFromDisk(Directory* dir)
    {
        std::filesystem::path path = dir->name;

        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            const std::string name = entry.path().filename().string();

            if (entry.is_directory())
            {
                auto subdir         = std::make_unique<Directory>();
                subdir->name        = name;
                subdir->isDirectory = true;
                subdir->parent      = dir;

                Directory* raw      = subdir.get();
                dir->children[name] = std::move(subdir);

                SyncFromDisk(raw);
            }
            else if (entry.is_regular_file())
            {
                auto file         = std::make_unique<File>();
                file->name        = name;
                file->isDirectory = false;
                file->parent      = dir;

                std::ifstream ifs(entry.path());

                if (ifs.is_open())
                {
                    std::stringstream buffer;
                    buffer << ifs.rdbuf();
                    file->contents = buffer.str();
                }

                dir->children[name] = std::move(file);
            }
        }
    }
} // namespace Nt

#endif // _CORE_FILESYSTEM_CPP_
