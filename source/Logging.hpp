/**
 * @file Logging.hpp
 * @brief Logging utilities
 * @author Mario Rosell
 * @date 26th July 2025
 **/

#pragma once

#include <iostream>
#include "Declspec.hpp"

const std::string ANSI_RESET = "\x1b[0m";
const std::string ANSI_RED = "\x1b[31m";
const std::string ANSI_YELLOW = "\x1b[33m";
const std::string ANSI_CYAN = "\x1b[36m";
const std::string ANSI_GREEN = "\x1b[32m";

/**
 * @brief		The different types of messages allowed by the logger.
 * @author	Mario Rosell
 */
enum class LogKinds
{
	Abort, /// < Fatal, unexpected, unrecoverable error.
	Fatal, /// < Fatal, kind of expected, somewhat recoverable error.
	Error, /// < Regular, recoverable error.
	Warn,  /// < Warning. Have little to none value most of the time.
	Mesg,  /// A message, mostly no importance at all
	Debug, //
};

namespace Logging
{

/**
 * @brief				Log a message.
 * @arg kind		The kind of log
 * @arg msg			The message
 * @author			Mario Rosell
 */
void
Log (LogKinds kind, std::string msg)
{
	std::string final_str;

	switch (kind)
	{
		case LogKinds::Abort:
			final_str = ANSI_RED + "abort: " + ANSI_RED + msg;
			abort ();
		case LogKinds::Fatal:
			final_str = ANSI_RED + "fatal: " + ANSI_RESET + msg;
			exit (1);
		case LogKinds::Error:
			final_str = ANSI_RED + "error: " + ANSI_RESET + msg;
		case LogKinds::Warn:
			final_str = ANSI_YELLOW + "warning: " + ANSI_RESET + msg;
		case LogKinds::Mesg:
			final_str = ANSI_CYAN + "message: " + ANSI_RESET + msg;
		case LogKinds::Debug:
			final_str = ANSI_GREEN + "debug: " + ANSI_RESET + msg;
	}

	std::cout << final_str << std::endl;
}
}
