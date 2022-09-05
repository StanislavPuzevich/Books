//15. Напишите программу, считывающую из файла числа, разделенные пробельными символами, 
//и выводящую в другой файл числа, используя научный формат и точность, равную восьми, в четырех полях по двадцать символов в строке.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

void func(std::string& fn )
{
    std::ifstream ifs(fn);

    fn.clear();
    std::cout << "Enter the file name for output: ";
    std::getline(std::cin, fn);
    std::ofstream ofs(fn);
    if (!ofs.is_open() || !ifs.is_open())
    {
        std::cerr << "One of the files can't be opened!" << std::endl; exit(-1);
    }

    int i = 0;
    while (!ifs.eof())
    {
        double num;
        ifs >> num;
        ofs << std::setw(20) << std::setprecision(8) << std::scientific << num;
        if ((i + 1) % 4 == 0)
            ofs << std::endl;
        i++;
    }
}

int main()
{
    std::string file_name;
    std::cout << "Enter the file name for input: ";
    std::getline(std::cin, file_name);

    func(file_name);

    std::cout << "The program has been successfully completed!" << std::endl;

    return 0;
}
