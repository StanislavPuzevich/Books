//Напишите программу, заменяющую знаки пунктуации пробелами.
//Считайте таковыми точку(.), точку с запятой(; ).запятую(, ), вопросительный знак(? ), дефис(-), одинарные кавычки('). Не изменяйте
//    символы, находящиеся между парами двойных кавычек(").Например.строка " - don't use the as-if rule ." должна принять вид
//    "don t use the as if rule".

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<char> vec{ '.',';',',','?','-',39 };
    std::string str;

    std::cout << "Enter the string: ";
    std::getline(std::cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 39 && str[i + 1] == 't') continue;
        if (std::find(vec.begin(), vec.end(), str[i]) != vec.end())
        {
            if ((i > 0) && (str[i - 1] == '"' && str[i + 1] == '"'))
                continue;
            str[i] = ' ';
        }
    }

    std::cout << "Result: " << str << std::endl;

    return 0;
}