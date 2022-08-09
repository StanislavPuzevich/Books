//7. Модифицируйте программу из предыдущего упражнения, чтобы она
//заменяла сокращения don ' t словами do not, can ' t - cannot и т.д.;
//дефисы внутри слов не трогайте(таким образом, мы получим строку
//" do not use the as-if rule "); переведите все символы в нижний регистр

#include <iostream>
#include <vector>
#include <sstream>

int main()
{
    std::vector<char> vec{ '.',';',',','-','?',39};
    std::ostringstream os;
    std::istringstream is;
    std::string str;

    std::cout << "Enter the string: ";
    std::getline(std::cin, str);
    is.str(str);
    
    bool flag;
    std::string temp;
    while (is >> temp)
    {
        flag = true;
        std::string new_word;
        for (char& ch : temp)
            ch = tolower(ch);
        if (temp == "don't") { new_word = "do not"; flag = false; }
        else if (temp == "can't") { new_word = "can not"; flag = false; }
        else if (temp == "could't") { new_word = "could not"; flag = false; }
        else if (temp == "won't") { new_word = "will not"; flag = false; }

        if (flag)
        {
            for (int i = 0; i < temp.length(); i++)
            {
                if (std::find(vec.begin(), vec.end(), temp[i]) != vec.end())
                {
                    if (i > 0 && temp[i] == '-' && temp[i - 1] >= 'a' && temp[i + 1] <= 'z') continue;
                    if (i > 0 && temp[i - 1] == '"' && temp[i + 1] == '"')continue;
                    temp[i] = ' ';
                }
            }
            new_word = temp;
        }

        os << new_word << " ";
    }

    temp = os.str();
    std::cout << "Result: " << temp << std::endl;

    return 0;
}