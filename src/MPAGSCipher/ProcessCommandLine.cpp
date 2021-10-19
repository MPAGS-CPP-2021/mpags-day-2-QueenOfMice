#include "ProcessCommandLine.hpp"

std::tuple<bool, bool, std::string, std::string> processCommandLine(const std::vector<std::string> &args) {
    /* deduce in/out file names, and help/version number requests from command line arguments 

    const std::vector<std::string> &args: command line arguments

    return: tuple in following order: 
        help requested (bool), version requested (bool), infile (string&), outfile (string&)
    */

    bool helpRequested = false;
    bool versionRequested = false;
    std::string inputFile = "";
    std::string outputFile = "";

    //- ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    for (std::size_t i{1}; i < args.size(); ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
        } else if (args[i] == "--version" || args[i] == "-v") {
            versionRequested = true;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == args.size() - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                exit(1);
            } else {
                // Got filename, so assign value and advance past it
                inputFile = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == args.size() - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                exit(1);
            } else {
                // Got filename, so assign value and advance past it
                outputFile = args[i + 1];
                ++i;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            exit(1);
        }
    }
    assert((inputFile != "") && "No input file provided. Use -i option to specify.");
    assert((outputFile != "") && "No output file provided. Use -o option to specify.");

    return std::make_tuple(helpRequested, versionRequested, inputFile, outputFile);
}

void provideHelp() {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [-v/--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return
        // with 0 used to indicate success
        exit(0);
}

void provideVersion() {
        std::cout << "1.0.0" << std::endl;
        exit(0);
}