//15. Напишите программу, считывающую из файла числа, разделенные пробельными символами, 
//и выводящую в другой файл числа, используя научный формат и точность, равную восьми, в четырех полях по двадцать символов в строке.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

void revers_words_in_line(std::string& fn )
{
    std::vector<double> vec;

    std::ifstream ifs(fn);
    if (!ifs.is_open())
    { std::cerr << "File not opened!" << std::endl; exit(-1);}

    while (!ifs.eof())
    {
        double num;
        ifs >> num;
        vec.push_back(num);
    }

    fn.clear();
    std::cout << "Enter the file name for output: ";
    std::getline(std::cin, fn);
    std::ofstream ofs(fn);
    if (!ofs.is_open())
    { std::cerr << "File not opened!" << std::endl; exit(-1);}

    for (int i = 0; i < vec.size(); i++)
    {
        ofs << std::setw(20) << std::setprecision(8) << std::scientific << vec[i];
        if ((i + 1) % 4 == 0)
            ofs << std::endl;
    }
}

int main()
{
    std::string file_name;
    std::cout << "Enter the file name for input: ";
    std::getline(std::cin, file_name);

    revers_words_in_line(file_name);

    std::cout << "The program has been successfully completed!" << std::endl;

    return 0;
}