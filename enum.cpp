#include <iostream>
#include <chrono>
#include <fstream>

#include "enum.hpp"

int main() 
{
    std::vector<uchar> charArray;
    int maxLen;
    std::string input;

    // Get character array from user
    std::cout << "Enter the character array (e.g. abc): ";
    std::cin >> input;
    for(char c : input) {
        charArray.push_back(c);
    }

    // Get max combination length
    do {
        std::cout << "Enter the maximum combination length\nDue to computational intensity, we limit the length to 5 characters for real-time demonstrations: ";
        std::cin >> maxLen;
    } while (maxLen <= 0 || maxLen > 5);

    Enumerator enumerator(maxLen, charArray);

    // Get preset from user
    std::cout << "Enter preset (e.g. aa): ";
    std::cin >> input;
    std::vector<uchar> presetArray(input.begin(), input.end());
    if (!enumerator.preset(presetArray)) {
        std::cerr << "Invalid preset. Exiting." << std::endl;
        return 1;
    }

    std::cout << "Max combinations: " << enumerator.getMaxCombinations() << std::endl;

    // Ask user if they want to redirect output to a file
    std::string filename;
    std::ofstream outFile;
    std::cout << "Do you want to redirect output to a file? (y/n): ";
    char choice;
    std::cin >> choice;
    if(choice == 'y' || choice == 'Y') {
        std::cout << "Enter filename: ";
        std::cin >> filename;
        outFile.open(filename);
        if(!outFile) {
            std::cerr << "Error: Unable to create or open the file. Output will be displayed on the console." << std::endl;
        } else {
            std::cout << "Output will be redirected to " << filename << std::endl;
        }
    } else {
        std::cout << "Output will be displayed on the console." << std::endl;
    }

    // Measure time
    auto start = std::chrono::high_resolution_clock::now();

    std::string combination;
    while(!(combination = enumerator.next()).empty()) {
        if(outFile) {
            outFile << combination << std::endl;
        } else {
            std::cout << combination << std::endl;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken: " << elapsed.count() << " seconds." << std::endl;

    if(outFile) {
        outFile.close();
        std::cout << "Combinations saved to " << filename << std::endl;
    }

    return 0;
}