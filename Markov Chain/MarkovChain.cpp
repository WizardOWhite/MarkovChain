#include "MarkovChain.h"

void MarkovChain::CreateMarkovChain(std::fstream inputFile, int keyLength)
{
    std::string prefix;
    std::string suffix;
    std::string buffer;
    int spacePos;
    for(int i = 0; i < keyLength; i++)
    {
        inputFile >> buffer;
        prefix += buffer + " ";
    }
    prefix = prefix.substr(0, prefix.size() - 1);

    while(inputFile >> suffix)
    {
        prefixSuffixDictionary[prefix].push_back(suffix);
        std::cout << "Prefix: " << prefix << " || Suffix: " + suffix << std::endl;
        prefix += " " + suffix;
        spacePos = prefix.find_first_of(" ", 0);
        prefix = prefix.substr(spacePos + 1, prefix.size() - spacePos);
    }
    inputFile.close();
}

std::string MarkovChain::GenerateMarkovSentences(int keyLength, int outputWordLength)
{
    int spacePos;
    int randomNumber;
    randomNumber = rand() % prefixSuffixDictionary.size();
    auto iterator = prefixSuffixDictionary.begin();
    std::advance(iterator, randomNumber);
    std::string prefix = iterator->first;
    std::string outputText = prefix;
    for(int i = 0; i < outputWordLength - keyLength; i++)
    {
        if(prefixSuffixDictionary[prefix].empty())
            break;
        std::string suffix = prefixSuffixDictionary[prefix].at(rand() % prefixSuffixDictionary[prefix].size());
        outputText += " " + suffix;
        prefix += " " + suffix;
        spacePos = prefix.find_first_of(" ", 0);
        prefix = prefix.substr(spacePos + 1, prefix.size() - spacePos);
    }
    return outputText;
}
