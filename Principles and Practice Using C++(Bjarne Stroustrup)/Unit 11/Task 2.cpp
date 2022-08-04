//2. Напишите программу, которая для данного имени файла и слова выводит все строки файла, содержащие это слово, вместе с номерами
//строк.Указание: getline() .

#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::string file_name;
    std::string search_string;

    std::cout << "Enter the file name for reading: ";
    std::getline(std::cin, file_name);
    std::cout << "Enter the string to search for: ";
    std::getline(std::cin, search_string);

    std::ifstream is(file_name);
    if (!is.is_open())
    {
        std::cerr << "File " << file_name << " can't open!" << std::endl;
        exit(1);
    }

    int i = 1;
    std::string buf;
    std::istringstream ss;
    while (std::getline(is, buf))
    {
        ss.clear();
        ss.str(buf);
        std::string temp;

        while (ss >> temp)
            if (temp == search_string)
                std::cout << "string " << i << ": " << buf << std::endl;

        i++;
    }
   
    return 0;
}
