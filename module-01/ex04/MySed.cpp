#include "MySed.hpp"

void replaceInFile(const std::string& filename,
    const std::string& first,
    const std::string& second)
{
    if (filename.empty() || first.empty() || second.empty()) {
        std::cerr << "Invalid input" << std::endl;
        return;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Failed to open the input file" << std::endl;
        return;
    }

    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile) {
        std::cerr << "Failed to create the output file" << std::endl;
        inFile.close();
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t position = 0;
        while ((position = line.find(first, position)) != std::string::npos) {
            std::string before = line.substr(0, position);
            std::string after = line.substr(position + first.length());
            
            line = before + second + after;
            position += second.length();
        }

        outFile << line << std::endl;
    }

    inFile.close();
    outFile.close();
}