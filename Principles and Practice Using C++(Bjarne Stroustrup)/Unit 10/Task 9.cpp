//9. Напишите программу, принимающую на вход два файла, содержащие
// лексикографически упорядоченные слова, разделенные пробелами, и
// объедините их, сохранив упорядочение.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

void Sort_Concatenation(std::ifstream& if1, std::ifstream& if2, std::ofstream& of)
{
	std::vector<std::string> vec;
	std::string temp;
	while (!if1.eof())
	{
		if1 >> temp;
		vec.push_back(temp);
	}

	while (!if2.eof())
	{
		if2 >> temp;
		vec.push_back(temp);
	}

	std::sort(vec.begin(), vec.end());

	for (std::string i : vec)
		of << i;

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

	Sort_Concatenation(if1, if2, of);

	std::cout << "Program has been completed, please check the results!" << std::endl;

	return 0;
}
