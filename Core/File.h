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

#ifndef _NT_CORE_FILE_H_
    #define _NT_CORE_FILE_H_

#include "Platform/Platform.h"

#include <string>
#include <filesystem>

namespace nt
{
    class NT_API FileReader
    {
    public:
        FileReader()                                   = default;
        FileReader(const std::string& filepath, const std::string& mode);
        ~FileReader();
        FileReader(const FileReader& other)            = default;
        FileReader& operator=(const FileReader& other) = default;

        // File reading methods
        std::string getExtension() const;
        std::string getPath() const;
        std::string getDirectory() const;
        std::string getFileName() const;
        bool read(void* buffer, size_t size);
        size_t read(void* buffer, size_t size, size_t count);

    private:
        std::string m_filepath;
        FILE* m_file;
    };

    class NT_API FileWriter
    {
    public:
        FileWriter()                                   = default;
        FileWriter(const std::string& filepath, const std::string& mode);
        ~FileWriter();
        FileWriter(const FileWriter& other)            = default;
        FileWriter& operator=(const FileWriter& other) = default;

        // File writing methods
        std::string getExtension() const;
        std::string getPath() const;
        std::string getDirectory() const;
        std::string getFileName() const;
        bool write(const void* buffer, size_t size);
        size_t write(const void* buffer, size_t size, size_t count);

    private:
        std::string m_filepath;
        FILE* m_file;
    };
} // namespace nt

#endif // _NT_CORE_FILE_H_
