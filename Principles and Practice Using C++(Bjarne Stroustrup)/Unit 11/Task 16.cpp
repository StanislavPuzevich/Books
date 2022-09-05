//16. Напишите программу, считывающую из файла числа, разделенные пробельными символами, 
//и выводящую их в порядке возрастания по одному числу в строке. Каждое число должно быть записано только один раз, 
//если обнаружится дубликат, то необходимо вывести количество таких дубликатов в строке.
//Например, результат обработки ввода 7 5 5 7 3 11 7 5 должен иметь следующий вид:
//  3
//  5 3
//  7 2
//  117

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>

void counter_func(std::string& fn)
{
    std::vector<int> vec;

    std::ifstream ifs(fn);
    if (!ifs.is_open())
    {
        std::cerr << "File not opened!" << std::endl; exit(-1);
    }

    while (!ifs.eof())
    {
        int num;
        ifs >> num;
        vec.push_back(num);
    }

    std::sort(vec.begin(), vec.end());

    fn.clear();
    std::cout << "Enter the file name for output: ";
    std::getline(std::cin, fn);
    std::ofstream ofs(fn);
    if (!ofs.is_open())
    {
        std::cerr << "File not opened!" << std::endl; exit(-1);
    }

    std::unordered_map<int, int> mp;
    for (auto i : vec)
        mp[i]++;
    for (auto i : mp)
        ofs << i.first << '\t' << i.second << std::endl;
}

int main()
{
    std::string file_name;
    std::cout << "Enter the file name for input: ";
    std::getline(std::cin, file_name);

    counter_func(file_name);

    std::cout << "The program has been successfully completed!" << std::endl;

    return 0;
}
