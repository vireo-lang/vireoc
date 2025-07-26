/**
 * @file Main.cpp
 * @brief Mostly the CLI, also sets up some stuff.
 * @author Mario Rosell
 * @copyright Copyright (c) 2025, Mario Rosell
 * @since 0.0.1
 **/

#include "Declspec.hpp"
#include "Logging.hpp"
#include <iostream>
#include <expected>
#include <exception>

#if (!defined(__GNUC__) && !defined(__clang__) && !defined(_MSC_VER))
#pragma warning "Unknown compiler. Speed might vary."
#endif

#include "../external/cxxopts.hpp"

/**
 * @brief Namespace with CLI-related stuff.
 * @since 0.0.1
 * @author Mario Rosell
 * @date 26th July 2025
 **/
namespace CLI
{

/**
 * @brief										Sets up the CLI with <cxxopts.hpp>.
 * @author									Mario Rosell
 * @arg argc								The argument count
 * @arg argv								The argument _vector_ (array of C strings: char[] *)
 * @return cxxopts::Options The created object
 **/
cxxopts::Options
CreateCLI (int argc, char* argv[])
{
	cxxopts::Options opts ("vireo", "The Vireo language CLI");

	opts.add_options () ("h,help", "Show this help message.") (
	  "v,version", "Shows the installed version of the program.") (
	  "o,out", "Sets the OUTPUT file. The input flag must be passed.\
			 Defaults to a.out.",
	  cxxopts::value<std::string> ()) ("i,in", "Sets the INPUT file.",
	                                   cxxopts::value<std::string> ()) (
	  "s,asm", "Outputs assembly language source instead of binaries.") (
	  "b,bytecode", "Outputs LLVM bytecode instead of binaries.") (
	  "O,obj", "Outputs an object file instead of a binary.") (
	  "n,noexec", "Checks the syntax of a file, withot compiling it.");

	try
	{
		auto res{ opts.parse (argc, argv) };

		if (res.count ("help"))
		{
			std::cout << opts.help () << std::endl;
			exit (0);
		}
	}
	catch (const std::exception& e)
	{
		Logging::Log (LogKinds::Fatal, "failed to parse CLI options.");
	}

	return opts;
}
}

/**
 * @brief					Main function.
 * @arg argc			The argument count.
 * @arg argv			The argument vector (array of C strings).
 * @return int		0 indicates success, nonzero inidicates failure.
 */
int
main (int argc, char* argv[])
{
	DECLSPEC (DS_UNUSED) auto cli = CLI::CreateCLI (argc, argv);
}

/* vim: set ts=2 sw=2 sts=2 noet tw=80: */
