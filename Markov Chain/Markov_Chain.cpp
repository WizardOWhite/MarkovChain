#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::fstream inputFile;
    
    std::string prefix;
    std::string suffix;
    std::string fileText;
    std::string outputText;
    std::string buffer;
    int spacePos;
    int randomNumber;
    
    int keyLength;
    int outputWordLength;
    
    std::map<std::string, std::vector<std::string>> prefixSuffixDictionary;

    inputFile.open("inputfile.txt");
    if(!inputFile.is_open())
    {
        printf("Failed to open file.");
        exit(1);
    }

    std::cout << "Input desired key length: " << std::endl;
    std::cin >> keyLength;

    std::cout << "Input desired output length: " << std::endl;
    std::cin >> outputWordLength;

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
        spacePos = prefix.find_first_of(" ", 0);
        prefix = prefix.substr(spacePos + 1, prefix.size() - spacePos);
        prefix += " " + suffix;
    }
    inputFile.close();

    randomNumber = rand() % prefixSuffixDictionary.size();
    auto iterator = prefixSuffixDictionary.begin();
    std::advance(iterator, randomNumber);
    prefix = iterator->first;
    outputText = prefix;
    for(int i = 0; i < outputWordLength - keyLength; i++)
    {
        if(prefixSuffixDictionary[prefix].empty())
            break;
        auto vector = prefixSuffixDictionary[prefix];
        suffix = vector.at(rand() % vector.size());
        outputText += " " + suffix;
        spacePos = prefix.find_first_of(" ", 0);
        prefix = prefix.substr(spacePos + 1, prefix.size() - spacePos);
        prefix += " " + suffix;
    }
    std::cout << std::endl << std::endl << outputText;
    
    return 0;
}
