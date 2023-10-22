#include <fstream>
#include <iostream>
#include <string>

#include "MarkovChain.h"

int main()
{
    std::fstream inputFile;
    std::string outputText;
    std::string inputFileName;

    int keyLength;
    int outputWordLength;

    std::cout << "Enter input file name: " << std::endl;
    std::cin >> inputFileName;

    std::cout << "Input desired key length: " << std::endl;
    std::cin >> keyLength;

    std::cout << "Input desired output length: " << std::endl;
    std::cin >> outputWordLength;

    inputFile.open(inputFileName);
    if(!inputFile.is_open())
    {
        printf("Failed to open file.");
        exit(1);
    }

    if(keyLength > outputWordLength || keyLength < 1 || outputWordLength < 1)
    {
        printf("Invalid inputs. Exiting program.");
        exit(1);
    }

    MarkovChain mc;
    mc.CreateMarkovChain(inputFile, keyLength);
    inputFile.close();
    outputText = mc.GenerateMarkovSentences(keyLength, outputWordLength);
    std::cout << std::endl << std::endl << outputText;
    
    return 0;
}
