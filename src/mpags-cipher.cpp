#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"


int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    //const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    // Process command line arguments 
    std::tie(helpRequested, versionRequested, inputFile, outputFile) = processCommandLine(cmdLineArgs);

    std::cout << inputFile << " " << outputFile << std::endl;

    // provide help if requested (or version number if requested) 
    if (helpRequested) {
        provideHelp();
    }
    if (versionRequested) {
        provideVersion();
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText = "";

    // Read in user input from stdin/file
    // Warn if input file not provided, and use input from cmd line instead
    // (note that I canged if not to if)
    if (inputFile.empty()) {
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not opened, using stdin\n";
        // loop over each character from user input
        while (std::cin >> inputChar) {
            // Uppercase alphabetic characters
            inputText += transformChar(inputChar);
        }
    }
    
    // if input file not empy, read input and transform
    std::ifstream in(inputFile);
    // if successful, transliterate
    if (in) {
        while (in.get(inputChar)) {
            inputText += transformChar(inputChar);
        }
    }

    // ceasar cipher
    inputText = runCaesarCipher(inputText, 5, true);

    // Warn if output file is not provided, and write to console instead
    // (note that I canged if not to if)
    if (outputFile.empty()) {
        std::cerr << "[warning] output to file ('" << outputFile
                  << "') not saved, using stdout\n";
        // Print out the transliterated text
        std::cout << inputText << std::endl;
        return 0;
    }

    // if output file is there, write to it
    std::ofstream outf(outputFile);
    if (outf) {
        outf << inputText;
    }

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}