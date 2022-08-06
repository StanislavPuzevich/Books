//Напишите программу.удаляющую из файла все гласные буквы.Например, фраза Once upon а time! 
//принимает вид nc pn tm !.Удивительно часто результат остается вполне удобочитаемым; проверьте это на
//своих друзьях.

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

template<typename T, typename... Args>
inline constexpr bool is_one_of = (std::is_same_v<T, Args> || ...);

template<typename T>
typename std::enable_if<is_one_of<T, std::ifstream, std::ofstream>, void>::type
check_open(T& file, std::string name)
{
    if (!file.is_open())
    {
        std::cerr << "File " << name << " can't be open!" << std::endl;
        exit(1);
    }
}

int main()
{
    std::vector<char> vec = { 'a','e','i','o','u','y' };
    std::vector<std::string> result;
    std::string file_name;
    std::cout << "Enter the file name: ";
    std::getline(std::cin, file_name);

    std::ifstream is(file_name);
    check_open(is, file_name);

    int i = 1;
    std::string buffer;
    std::istringstream ss;
    while (std::getline(is, buffer))
    {
        ss.clear();
        ss.str(buffer);
        buffer.clear();
        std::string temp1;
        std::string temp2;
        while (ss >> temp1)
        {
            for (char i : temp1)
            {
                if (std::find(vec.begin(), vec.end(), tolower(i)) == vec.end())
                    temp2 += i;
            }
            temp2 += " ";
        }
        result.push_back(temp2);
    }

    std::ofstream of(file_name);
    check_open(of, file_name);

    for (std::string s : result)
        of << s << '\n';

    return 0;
}