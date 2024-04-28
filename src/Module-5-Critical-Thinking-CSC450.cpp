#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


void appendToFile(const std::string& filename, const std::string& userInput) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << userInput;
        file.close();
        std::cout << "Data appended successfully to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}


void reverseFile(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file " << inputFilename << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)),
                         std::istreambuf_iterator<char>());
    inputFile.close();

    std::reverse(content.begin(), content.end());

    std::ofstream outputFile(outputFilename);
    if (outputFile.is_open()) {
        outputFile << content;
        outputFile.close();
        std::cout << "Reversed content written to " << outputFilename << std::endl;
    } else {
        std::cerr << "Unable to open file " << outputFilename << " for writing" << std::endl;
    }
}

int main() {
    const std::string inputFilename = "CSC450_CT5_mod5.txt";
    const std::string outputFilename = "CSC450-mod5-reverse.txt";

    std::string userInput;
    std::cout << "Enter data to append to file: ";
    std::getline(std::cin, userInput);

    appendToFile(inputFilename, userInput);
    reverseFile(inputFilename, outputFilename);

    return 0;
}
