//Unit 10, task 11:
//Напишите программу.вычисляющую сумму всех целых чисел, хранящихся в текстовом файле и разделенных пробелами и словами.
//Например, строка "bears : 17 elephants 9 end" дает результат, равный 26.

//Description:
//my program counts the sum of ALL integers found in the file, separated by any character except "-".
//If the symbol "-" stands in front of an integer makes it negative, if the symbol "-" stands inside the number, 
//then the left part of the number is not read, the right part is calculated as negative.

//tested were:
// 
//case 1:
//	"wh 42 fr 53 gd -53gf rgr100"
// 
//case 2:
//  "1 2 3 4 5 6 7 8 9 - 10
//	11
//	12
//	13
//	14
//	-15"
// 
//case 3:
//	"26246-35"

#include <iostream>
#include <string>
#include <list>
#include <fstream>

void constr_of_numb(std::list<char>& buf, int& sum);

void open_file(std::ifstream& in)
{
	std::cout << "Please enter the file name: " << std::endl;
	std::string str;
	std::getline(std::cin, str);

	in.open(str);

	if (!in.is_open())
	{
		std::cerr << "File didn't open, try one more time!" << std::endl;
		exit(-1);
	}
}

int work_function(std::ifstream& in)
{
	int sum = 0;
	std::list<char> buf;
	char temp;
	in >> std::noskipws;
	while (!in.eof())
	{
		in >> temp;

		if ((temp > 47 && temp < 58) || temp == '-')
			buf.push_back(temp);

		else if (!buf.empty())
			constr_of_numb(buf, sum);
	}

	if (!buf.empty())
	{
		buf.pop_back();
		constr_of_numb(buf, sum);
	}

	return sum;
}

void constr_of_numb(std::list<char>& buf, int& sum)
{
	bool check_minus = false;
	bool ret_minus = false;
	int num = 0;

	if (buf.front() == '-')
	{
		check_minus = true;
		buf.pop_front();
	}

	while (!buf.empty())
	{
		if (buf.front() == '-')
		{
			num = 0;
			check_minus = true;
			buf.pop_front();
			continue;
		}
		num = num * 10 + (buf.front() - '0');
		buf.pop_front();
	}

	check_minus ? sum -= num : sum += num;
}

int main()
{
	std::ifstream in;
	open_file(in);

	std::cout << "Result: " << work_function(in) << std::endl;
	in.close();

	return 0;
}