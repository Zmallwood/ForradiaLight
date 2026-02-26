/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Logger.hpp"

namespace Forradia
{
    Logger::Logger() : m_logFile(k_logFileName, std::ios::out | std::ios::trunc)
    {
    }

    Logger::~Logger()
    {
        m_logFile.close();
    }

    void Logger::Log(std::string_view message, LogLevels logLevel,
                     const std::source_location &location)
    {
        auto ticks{SDL_GetTicks()};

        switch (logLevel)
        {
        case LogLevels::Info:
            m_logFile << "Info: ";
            break;
        case LogLevels::Warning:
            m_logFile << "Warning: ";
            break;
        case LogLevels::Error:
            m_logFile << "Error: ";
            break;
        default:
            m_logFile << "Unknown: ";
            break;
        }

        m_logFile << ticks << " " << location.file_name() << ":" << location.line() << " "
                  << message << std::endl;
    }

    void Log(std::string_view message, LogLevels logLevel, const std::source_location &location)
    {
        _<Logger>().Log(message, logLevel, location);
    }
}