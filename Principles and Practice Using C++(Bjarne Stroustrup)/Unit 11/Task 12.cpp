//12. Измените порядок следования символов в текстовом файле. Например, строка asdfghjkl примет вид lkjhgfdsa. 
// Предупреждение: не существует реально хорошего, переносимого и эффективного способа чтения файла в обратном направлении.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void revers_file_data(const std::string& fn )
{
    std::vector<std::string> result;

    std::ifstream ifs(fn);
    if (!ifs.is_open())
    { std::cerr << "File not opened!" << std::endl; exit(-1);}

    while (!ifs.eof())
    {
        std::string temp;
        std::getline(ifs, temp);

        for (int i = 0, j = temp.length() - 1; i < j; i++, j--)
            std::swap(temp[i], temp[j]);

        result.push_back(temp);
    }

    std::ofstream ofs(fn, std::ios::out);
    if (!ofs.is_open())
    { std::cerr << "File not opened!" << std::endl; exit(-1);}

    for (int i = result.size() - 1; i >= 0; i--)
        ofs << result[i] << std::endl;
}

int main()
{
    std::string file_name;
    std::cout << "Enter the file name: ";
    std::getline(std::cin, file_name);

    revers_file_data(file_name);

    std::cout << "The program has been successfully completed!" << std::endl;

    return 0;
}
