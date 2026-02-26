/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "LogLevels.hpp"

namespace Forradia
{
    class Logger
    {
      public:
        Logger();

        ~Logger();

        void Log(std::string_view message, LogLevels logLevel,
                 const std::source_location &location = std::source_location::current());

      private:
        constexpr static LogLevels k_logLevel{LogLevels::Info};
        inline static const std::string k_logFileName{"log.txt"};
        std::ofstream m_logFile;
    };

    void Log(std::string_view message, LogLevels logLevel,
             const std::source_location &location = std::source_location::current());
}