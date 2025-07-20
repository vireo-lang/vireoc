#include "Vireo.hpp"

int main(int argc, char **argv) {
    try {
        cxxopts::Options options("vireoc", "vireoc -- The Vireo compiler");

        options.add_options()("h,help", "Show help")("v,ver", "Print version")(
            "i,in", "Set input file", cxxopts::value<std::string>())(
            "o,out", "output file", cxxopts::value<std::string>());

        auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            return EXIT_SUCCESS;
        }

        if (result.count("ver")) {
            std::cout << "`vireoc` version " << VER << std::endl;
            return EXIT_SUCCESS;
        }

        std::string in, out;

        if (result.count("in"))
            in = result["in"].as<std::string>();

        if (result.count("out"))
            out = result["out"].as<std::string>();
        else
            out = "a.out";

       if (!in.empty()) {
           vireoc::Compiler comp(in, &out);
           log(LogLevel::Info, "Input %s, output: %s", in.c_str(), out.c_str());
       }

       if (in == out) {
           log(LogLevel::Error, "Input and output files are the same.\n");
       }

    } catch (const std::exception &e) {
        log(LogLevel::Error, "Failed to parse command line options.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
