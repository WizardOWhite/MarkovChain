#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>

class MarkovChain
{
public:
    void CreateMarkovChain(std::fstream& inputFile, int keyLength);
    std::string GenerateMarkovSentences(int keyLength, int outputWordLength);
private:
    std::map<std::string, std::vector<std::string>> prefixSuffixDictionary;
};
