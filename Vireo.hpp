#pragma once

#include "Logging.hpp"
#include <array>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cxxopts.hpp>
#include <fstream>
#include <iostream>

#define USE(X) ((void)X)

/**************
 **** DATA ****
 **************/

#define MAXBUF 8192
#define VER "0.0.1 devel"

/********************
 **** STRUCTURES ****
 ********************/

namespace vireoc {

class Compiler {
  private:
    const std::string _filename;
    const std::unique_ptr<std::array<char, MAXBUF>> _contents;

    const std::string *_out_fname;

    uint32_t _line;
    uint32_t _col;

  public:
    Compiler(const std::string fname, const std::string *out_fname)
        : _filename(fname),
        _contents(std::make_unique<std::array<char, MAXBUF>>()),
        _out_fname(out_fname), _line(0),
        _col(0) {
        std::ifstream file(this->_filename);

        if (!file.is_open()) {
            log(LogLevel::Error, "Failed to open file %s", this->_filename.c_str());
            exit(EXIT_FAILURE);
        }

        if (file.fail()) {
            log(LogLevel::Error, "Stream failed (fail bit or bad bit set)\n");
            exit(EXIT_FAILURE);
        }
    };
};

class Lexer;
class Parser;
class Codegen;
} // namespace vireoc

/*******************
 **** FUNCTIONS ****
 *******************/

int main(int argc, char **argv);
