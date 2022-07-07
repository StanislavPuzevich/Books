//6. Определите класс Roman int для хранения римских цифр(как чисел
//	типа int) с операторами << и >> .Включите в класс Roman_int функцию
//	as_int(), возвращающую значение типа int, так.чтобы, если объект
//	r имеет тип Roman int, мы могли написать cout << "Римское " << r
//	<< 11 раано 11 << r.as_int() << ' \n'; .

#include <iostream>
#include <unordered_map>

class Roman_int
{
public:
	char simb;
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

	int as_int();
};

int Roman_int::as_int()
{
	if (!rom_val.count(simb)) return -1;
	return rom_val[simb];
}

std::istream& operator>>(std::istream& in, Roman_int& obj)
{
	in >> obj.simb;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Roman_int& obj)
{
	out << obj.simb;
	return out;
}

int main()
{
	Roman_int r;

	std::cout << "Please, enter the Roman numeral:" << std::endl;
	std::cin >> r;

	// Result
	std::cout << "Roman numeral  '" << r << "' is equal to " << r.as_int() << std::endl;
	if(r.as_int() == -1) std::cout << "There is no such Roman numeral!" << std::endl;

	return 0;
}
