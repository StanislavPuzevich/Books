//10. Напишите функцию vector<string> split(const string & s).возвращающую вектор подстрок аргумента s, разделенных пробельными символами.

#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& s)
{
    std::vector<std::string> result;
    std::istringstream is;
    std::string temp;
    is.str(s);

    while (is >> temp)
        result.push_back(temp);

    return result;
}

int main()
{
    std::string str;
    std::vector<std::string> result;

    std::cout << "Enter the string: ";
    std::getline(std::cin, str);

    result = split(str);
    for (std::string i : result)
        std::cout << i << std::endl;

    return 0;
}