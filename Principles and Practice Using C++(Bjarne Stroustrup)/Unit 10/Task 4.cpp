#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <algorithm>

struct Reading
{
	int hour;
	double temperature;
	char suffix;
};

std::istream& operator>>(std::istream& in, Reading& obj)
{
	in >> obj.hour >> obj.temperature >> obj.suffix;
	return in;
}

int to_file(Reading& r)
{
	std::vector<char> str{ 'c', 'f' };
	std::ofstream ost("mydata.txt");
	if (ost.is_open())
	{
		for (int i = 0; i < 50; i++)
		{
			r.hour = rand() % 24;
			r.temperature = rand() % 100;
			r.suffix = str[rand() % 2];
			ost << r.hour << '\t' << r.temperature << '\t' << r.suffix << std::endl;
		}
		ost.close();
	}
	else return 1;

	return 0;
}

int from_file(Reading& r, std::vector<Reading>& vec)
{
	std::ifstream ist("mydata.txt");
	if (ist.is_open())
	{
		while (ist >> r)
		{
			if (r.suffix == 'c')
				r.temperature = r.temperature * 1.8 + 32;
			vec.push_back(r);
		}

		ist.close();
	}
	else return 1;

	return 0;
}

double arithmetic_mean(const std::vector<Reading>& vec)
{
	double arithm = 0;

	for (auto i : vec)
		arithm += i.temperature;

	return arithm / vec.size();
}

double median(std::vector<Reading>& vec)
{
	int size = vec.size();
	std::sort(vec.begin(), vec.end(), [](const Reading& a, const Reading& b) {return a.temperature > b.temperature; });

	if (size % 2)
		return vec[size / 2].temperature;

	return (vec[size / 2].temperature + vec[size / 2 - 1].temperature) / 2;
}

int main()
{
	srand (time(0));
	Reading r;
	std::vector<Reading> vec;

	if (to_file(r)) return 0;           // input values from the user to the file

	if (from_file(r, vec)) return 0;    // values from the file to the vector

	std::cout << "Arithmetic mean: " << arithmetic_mean(vec) << std::endl;
	std::cout << "Midiana of temperature valuse: " << median(vec) << std::endl;

	return 0;
}
