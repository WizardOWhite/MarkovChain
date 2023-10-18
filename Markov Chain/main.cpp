#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "MarkovChain.h"

int main()
{
    std::fstream inputFile;
    std::string outputText;
    std::string inputFileName;

    int keyLength;
    int outputWordLength;
    
    MarkovChain mc;

    std::cout << "Enter input file name: " << std::endl;
    std::cin >> inputFileName;

    inputFile.open(inputFileName);
    if(!inputFile.is_open())
    {
        printf("Failed to open file.");
        exit(1);
    }

    std::cout << "Input desired key length: " << std::endl;
    std::cin >> keyLength;

    std::cout << "Input desired output length: " << std::endl;
    std::cin >> outputWordLength;

    if(keyLength > outputWordLength || keyLength < 1 || outputWordLength < 1)
    {
        printf("Invalid inputs. Exiting program.");
        exit(1);
    }

    mc.CreateMarkovChain(std::move(inputFile), keyLength);
    outputText = mc.GenerateMarkovSentences(keyLength, outputWordLength);
    std::cout << std::endl << std::endl << outputText;
    
    return 0;
}
