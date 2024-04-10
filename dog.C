#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <span>

int main(int argc, char** argv)
{
    if (argc  != 2) {
        return 1;
    }

    std::span<char*> args = std::span(argv, size_t(argc));

    std::string fileName = args[1];

    std::fstream fs;
    fs.open(fileName, std::fstream::in);

    if (fs.fail()) 
    {
        std::cout << "dog: " << fileName << ": No such file or directory" << std::endl;
        return 1;
    }  

    fs.seekg(0, fs.end);
    long length = fs.tellg();
    fs.seekg(0, fs.beg);

    for (int i = 0; i < length; i++) 
    {
        std::cout << (char)fs.get();
    }

    fs.close();

    return 0;
}