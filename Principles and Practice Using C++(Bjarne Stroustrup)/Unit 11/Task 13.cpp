//13. Измените порядок следования слов(определенных как строки,разделенные пробелами).
//Например, строка Norwegian Blue parrot примет вид parrot Blue Norwegian. Можете считать, что все строки из файла
//могут поместиться в памяти одновременно.

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void revers_words_in_line(const std::string& fn )
{
    std::vector<std::vector<std::string>> result;

    std::ifstream ifs(fn);
    if (!ifs.is_open())
    { std::cerr << "File not opened!" << std::endl; exit(-1);}

    while (!ifs.eof())
    {
        std::string s;
        std::getline(ifs, s);

        std::istringstream isstr;
        isstr.str(s);
        std::vector<std::string> line;
        s.clear();

        while (isstr >> s)
            line.push_back(s);

        result.push_back(line);
    }

    std::ofstream ofs(fn, std::ios::out);
    if (!ofs.is_open())
    { std::cerr << "File not opened!" << std::endl; exit(-1);}

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = result[i].size() - 1; j >= 0; j--)
            ofs << result[i][j] << " ";
        ofs << std::endl;
    }
    
}

int main()
{
    std::string file_name;
    std::cout << "Enter the file name: ";
    std::getline(std::cin, file_name);

    revers_words_in_line(file_name);

    std::cout << "The program has been successfully completed!" << std::endl;

    return 0;
}