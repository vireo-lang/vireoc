#pragma once

#include "Vireo.hpp"
#include <cstdarg>
#include <cstdio>

enum class LogLevel { Info, Warn, Error };

void log(LogLevel level, const char *fmt, ...) {
    const char *color;
    const char *tag;

    switch (level) {
    case LogLevel::Info:
        color = "\x1b[34m";
        tag = "[INFO]";
        break;
    case LogLevel::Warn:
        color = "\x1b[33m";
        tag = "[WARNING]";
        break;
    case LogLevel::Error:
        color = "\x1b[31m";
        tag = "[ERROR]";
        break;
    }

    fprintf(stderr, "%s%s ", color, tag);

    va_list args;
    va_start(args, fmt);
        vfprintf(stderr, fmt, args);
    va_end(args);

    fprintf(stderr, "\x1b[0m\n");
}
