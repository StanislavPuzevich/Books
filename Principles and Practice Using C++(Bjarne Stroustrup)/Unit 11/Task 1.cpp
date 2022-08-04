//1. Напишите программу.читающую текстовый файл и записывающую
//его содержимое в новый файл в нижнем регистре.

#include <iostream>
#include <istream>
#include <fstream>
#include <string>

int main()
{
    std::string file_name;

    std::cout << "Enter the file name for reading: ";
    std::getline(std::cin, file_name);

    std::ifstream is;
    is.open(file_name);
    if (!is.is_open())
    {
        std::cerr << "File " << file_name << " can't open!" << std::endl;
        exit(1);
    }

    file_name.clear();
    std::cout << "Enter the file name for writing: ";
    std::getline(std::cin, file_name);

    std::ofstream of;
    of.open(file_name);
    if (!of.is_open())
    {
        std::cerr << "File " << file_name << " can't open!" << std::endl;
        exit(1);
    }

    char ch;
    std::string buf;
    while (!is.eof())
    {
        is >> ch;
        ch = std::tolower(ch);
        of << ch;
    }

    return 0;
}
