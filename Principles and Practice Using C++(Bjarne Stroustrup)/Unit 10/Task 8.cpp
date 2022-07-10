//8. Напишите программу, принимающую на вход имена двух файлов и
//создающую новый файл, в котором за содержимым первого файла
//следует содержимое второго; иначе говоря, программа должна конкатенировать два файла

#include <iostream>
#include <string>
#include <fstream>

void enter_file_name(std::string& str1, std::string& str2)
{
	std::getline(std::cin, str1);
	std::getline(std::cin, str2);
}

void close_program(const std::string& str)
{
	std::cerr << "File '" << str << "' didn't open!" << std::endl;
	exit(-1);
}

void file_concatenation(std::ifstream& if1, std::ifstream& if2, std::ofstream& of)
{
	std::string str;
	while (!if1.eof())
	{
		if1 >> str;
		of << str << std::endl;
	}

	while (!if2.eof())
	{
		if2 >> str;
		of << str << std::endl;
	}

	if1.close();
	if2.close();
	of.close();
}

int main()
{
	std::string file_name1, file_name2, res_file_name;
	std::cout << "Please enter 2 file(*txt) names: " << std::endl;
	enter_file_name(file_name1, file_name2);

	std::cout << "Please enter new file name: " << std::endl;
	std::getline(std::cin, res_file_name);

	std::ifstream if1(file_name1);
	if (!if1.is_open())
		close_program(file_name1);

	std::ifstream if2(file_name2);
	if (!if2.is_open())
		close_program(file_name2);

	std::ofstream of(res_file_name);
	if (!of.is_open())
		close_program(res_file_name);

	file_concatenation(if1, if2, of);

	std::cout << "Program has been completed, please check the results!" << std::endl;

	return 0;
}
