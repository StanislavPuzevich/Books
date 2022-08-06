//5. Напишите программу.считывающую строки и выводящую категории
//каждого символа в соответствии с правилами, описанными в разделе 11.6.
//Помните, что один и тот же символ может относиться к разным категориям(например, х - это и буквенный, и буквенно - цифровой символ).

#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "rus");
    std::string str;
    std::cout << "Enter the string: ";
    std::getline(std::cin, str);

    bool check;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0' && str[i + 1] == 'x' && ((i + 2) < str.length() && isxdigit(str[i + 2])))
        {
            std::cout << "Символ '" << str[i++] << "' является шеснадцатиричным." << std::endl;
            std::cout << "Символ '" << str[i++] << "' является шеснадцатиричным." << std::endl;
            while (i < str.length() && isxdigit(str[i]))
            {
                std::cout << "Символ '" << str[i] << "' является шеснадцатиричным." << std::endl;
                i++;
            }
            i--;
        }
        else if(isalpha(str[i]))
            std::cout << "Символ '" << str[i] << "' является буквой." << std::endl;
        else if(isdigit(str[i]))
            std::cout << "Символ '" << str[i] << "' является десятичным символом." << std::endl;
        else if(isspace(str[i]))
            std::cout << "Символ '" << str[i] << "' является пробельнымn символом." << std::endl;
        else if(iscntrl(str[i]))
            std::cout << "Символ '" << str[i] << "' является упраляющим символом." << std::endl;
        else
            std::cout << "Символ '" << str[i] << "' очень странный символ, он не попадает ни под одну из категорий." << std::endl;
    }

    return 0;
}