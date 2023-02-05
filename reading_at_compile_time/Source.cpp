//#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#define ABC 123456
#define str(s) #s 
#define xstr(s) str(s)

const char* text = {
#include "Text.txt"
};

std::string raw2regular_string(std::string const& some_txt)
{
    std::string return_str;
    std::istringstream iss(some_txt);
    std::string line;
    while (std::getline(iss, line))
    {
        std::cout << line << '\n';
        getchar();
    }

    return return_str;
}

int main() 
{
    //std::cout << text << std::endl;
    raw2regular_string(text);

    //std::cout << str(ABC) << " " << xstr(ABC) << std::endl;
}