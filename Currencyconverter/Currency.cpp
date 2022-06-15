#include "Currency.h"

Currency::Currency(std::string name, double value) : name{ name }, value{ value }
{}

std::ostream& operator<< (std::ostream& os, Currency& currency)
{
	os << " " << currency.name;
	return os;
}

std::istream& operator>>(std::istream& is, Currency& currency)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string name{};
	std::cout << "\nEnter the name ";
	std::getline(is, name);

	std::cout << "\nEnter the value ";
	std::string line;
	double value;
	while (std::getline(is, line))
	{
		std::stringstream ss(line);
		if (ss >> value)
		{
			if (ss.eof())
			{
				break;
			}
		}
		std::cout << "Error! Re - enter the value ";
	}
	currency = Currency{ name,value };
	return is;
}

double calculate_conversion(Currency& from, Currency& to, double amount)
{
	if (from.value < to.value)
	{
		double temp = to.value / from.value;
		amount /= temp;
	}
	else
	{
		double temp = from.value / to.value;
		amount *= temp;
	}
	return amount;
}

bool Currency::operator<(const Currency& rhs) const {
	return (this->name < rhs.name);
}

bool Currency::operator==(const Currency& rhs) const {
	return(this->name == rhs.name || this->value == rhs.value);
}

bool Currency::check_validity(const std::vector<Currency>& currency)
{
	for (auto item : currency)
	{
		if (this->name == item.get_name())
		{
			return false;
		}
	}
	return true;
}

