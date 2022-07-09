//6   Определите класс Roman int для хранения римских цифр(как чисел типа int) с операторами << и >> .
// Включите в класс Roman_int функцию as_int(), возвращающую значение типа int, так.чтобы, 
// если объект r имеет тип Roman int, мы могли написать 
// cout << "Римское " << r << 11 раано 11 << r.as_int() << ' \n'; .

#include <iostream>
#include <unordered_map>
#include <string>

void error();

struct Solution							// A completely banal solution :(	   
{
	int number;
	std::string roman;
	std::unordered_map<char, int> rom_val
	{
		{ 'I', 1},
		{ 'V', 5},
		{ 'X', 10},
		{ 'L', 50},
		{ 'C', 100},
		{ 'D', 500},
		{ 'M', 1000}
	};
	std::unordered_map<char, int> val_rom
	{
		{ 1   ,'I'},
		{ 5   ,'V'},
		{ 10  ,'X'},
		{ 50  ,'L'},
		{ 100 ,'C'},
		{ 500 ,'D'},
		{ 1000,'M'}
	};

	int convert_from_Roman_to_int();
	std::string convert_from_int_to_Roman(int num);
};

int Solution::convert_from_Roman_to_int()
{
	if (rom_val.count(roman[0]))
		number = rom_val[roman[0]];
	else error();

	for (int i = 1; i < roman.length(); i++)
	{
		if (rom_val.count(roman[i]))
		{
			if (number < rom_val[roman[i]])
				number = rom_val[roman[i]] - number;
			else
				number += rom_val[roman[i]];
		}
		else error();
	}

	return number;
}

std::string Solution::convert_from_int_to_Roman(int num)
{
	roman.clear();
	roman = "";
	int del = 1000;
	while (num > 0)
	{
		while (del > 0 && num / del)
		{
			if (num / del == 9)
			{
				roman += val_rom[del];
				roman += val_rom[del * 10];
				num %= del;
			}
			else if (num / del == 4)
			{
				roman += val_rom[del];
				roman += val_rom[del * 5];
				num %= del;
			}
			else if (num > (del * 5))
			{
				roman += val_rom[del * 5];
				num -= del * 5;
			}
			else
			{
				roman += val_rom[del];
				num -= del;
			}
		}
		del /= 10;
	}
	return roman;
}

void error()
{
	std::cout << "The program cannot recognize the characters you entered!" << std::endl;
	exit(-1);
}

char menu()
{
	char ch;

	std::cout << "Please select an action: " << std::endl
		<< "Press '+' to add" << std::endl
		<< "Press '-' to subtract" << std::endl
		<< "Press '*' to multiply" << std::endl
		<< "Press '/' to divide" << std::endl;
	std::cin >> ch;

	return ch;
}

int main()
{
	Solution s;
	int n1, n2, res = 0;

	std::cout << "Please enter 2 numbers in Roman format: " << std::endl;
	std::getline(std::cin, s.roman);
	n1 = s.convert_from_Roman_to_int();
	std::getline(std::cin, s.roman);
	n2 = s.convert_from_Roman_to_int();

	char answ;
	while (true)
	{
		switch (menu())
		{
		case '+': res = n1 + n2; break;
		case '-': res = n1 - n2; break;
		case '*': res = n1 * n2; break;
		case '/': res = n1 / n2; break;
		default: res = 0;
		}
		std::string str_res = s.convert_from_int_to_Roman(res);
		std::cout << "Result: " << str_res << std::endl;
		std::cout << "Do you want to continue(y/n)?" << std::endl;
		std::cin >> answ;
		if (answ == 'n') break;
	}

	return 0;
}