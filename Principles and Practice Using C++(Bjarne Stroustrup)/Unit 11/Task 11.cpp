// 11. Напишите функцию vector<string> split(const string& s, const string& w), 
// возвращающую вектор подстрок аргумента s, разделенных пробельными символами, при условии, что в качестве пробельного 
// символа могут использоваться как "обычные" пробельные символы, так и символы из строки w

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s, const std::string& w)
{
    std::string buf;
    std::vector<std::string> result;

    for (char i : s)
    {
        if (i == ' ' || (w.find(i) != std::string::npos))
        {
            if (!buf.empty())
                result.push_back(buf);
            buf.clear();
            continue;
        }
        buf += i;
    }

    return result;
}

int main()
{
    std::string w = ",!-";
    std::string s;
    std::vector<std::string> res;

    std::cout << "Enter the string: " << std::endl;
    std::getline(std::cin, s);
    res = split(s, w);

    std::cout << "Result: " << std::endl;
    for (std::string i : res)
        std::cout << i << std::endl;

    return 0;
}