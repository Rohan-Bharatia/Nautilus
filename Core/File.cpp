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

#ifndef _NT_CORE_FILE_CPP_
    #define _NT_CORE_FILE_CPP_

#include "File.h"

#include "Logger.h"

namespace nt
{
    FileReader::FileReader(const std::string& filepath, const std::string& mode) :
        m_filepath(filepath), m_file(fopen(filepath.c_str(), mode.c_str()))
    {
        if (!m_file)
        {
            fclose(m_file);
            Logger::error("Failed to open file: " + filepath);
        }
    }

    FileReader::~FileReader()
    {
        if (m_file)
            fclose(m_file);
        delete m_file;
    }
    std::string FileReader::getExtension() const
    {
        if (!m_file)
            return "";

        std::filesystem::path path(m_filepath.c_str());
        return path.extension().string();
    }
    std::string FileReader::getPath() const
    {
        if (!m_file)
            return "";

        std::filesystem::path path(m_filepath.c_str());
        return path.string();
    }

    std::string FileReader::getDirectory() const
    {
        if (!m_file)
            return "";

        std::filesystem::path path(m_filepath.c_str());
        return path.parent_path().string();
    }

    std::string FileReader::getFileName() const
    {
        if (!m_file)
            return "";

        std::filesystem::path path(m_filepath.c_str());
        return path.filename().string();
    }

    bool FileReader::read(void* buffer, size_t size)
    {
        if (!m_file)
        {
            Logger::error("File not opened");
            return false;
        }

        size_t bytesRead = fread(buffer, 1, size, m_file);
        if (bytesRead != size)
        {
            Logger::error("Failed to read file");
            return false;
        }

        return true;
    }

    size_t FileReader::read(void* buffer, size_t size, size_t count)
    {
        if (!m_file)
        {
            Logger::error("File not opened");
            return 0;
        }

        size_t bytesRead = fread(buffer, 1, size * count, m_file);
        return bytesRead;
    }

    FileWriter::FileWriter(const std::string& filepath, const std::string& mode) :
        m_filepath(filepath), m_file(fopen(filepath.c_str(), mode.c_str()))
    {
        if (!m_file)
        {
            fclose(m_file);
            Logger::error("Failed to open file: " + filepath);
        }
    }
    FileWriter::~FileWriter()
    {
        if (m_file)
            fclose(m_file);
        delete m_file;
    }

    std::string FileWriter::getExtension() const
    {
        if (!m_file)
            return "";

        std::filesystem::path path(m_filepath.c_str());
        return path.extension().string();
    }
    std::string FileWriter::getPath() const
    {
        if (!m_file)
            return "";

        std::filesystem::path path(m_filepath.c_str());
        return path.string();
    }

    std::string FileWriter::getDirectory() const
    {
        if (!m_file)
            return "";

        std::filesystem::path path(m_filepath.c_str());
        return path.parent_path().string();
    }

    std::string FileWriter::getFileName() const
    {
        if (!m_file)
            return "";

        std::filesystem::path path(m_filepath.c_str());
        return path.filename().string();
    }

    bool FileWriter::write(const void* buffer, size_t size)
    {
        if (!m_file)
        {
            Logger::error("File not opened");
            return false;
        }

        size_t bytesWritten = fwrite(buffer, 1, size, m_file);
        if (bytesWritten != size)
        {
            Logger::error("Failed to write to file");
            return false;
        }

        return true;
    }

    size_t FileWriter::write(const void* buffer, size_t size, size_t count)
    {
        if (!m_file)
        {
            Logger::error("File not opened");
            return 0;
        }

        size_t bytesWritten = fwrite(buffer, 1, size * count, m_file);
        return bytesWritten;
    }
} // namespace nt

#endif // _NT_CORE_FILE_CPP_
