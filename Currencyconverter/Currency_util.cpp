#include "Currency_util.h"

void display_menu()
{
	std::cout << std::endl;
	std::cout << "A - Add Currency" << std::endl;
	std::cout << "C - Convert Currency" << std::endl;
	std::cout << "D - Display Currency" << std::endl;
	std::cout << "Q - Quit" << std::endl;
}


void add_currency(std::vector<Currency>& currency)
{
	std::unique_ptr<Currency> new_currency = std::make_unique<Currency>();
	std::cin >> *new_currency;

	if (new_currency->check_validity(currency))
	{
		currency.push_back(*new_currency);
		std::cout << "\nCurrency added!" << std::endl;
	}
	else
	{
		std::cout << std::endl << new_currency->get_name() << " already added!" << std::endl;
	}
}


void convert_currency(std::vector<Currency>& currency)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string from{};
	std::string to{};
	int pos1{};
	int pos2{};
	display_info(currency);

	bool result1 = false;

	while (result1 == false)
	{
		from = currency_from();
		result1 = find_position(currency, from);
		if (result1 != false)
		{
			pos1 = get_position(currency, from);
		}

	}

	bool result2 = false;

	while (result2 == false)
	{
		to = currency_to();
		result2 = find_position(currency, to);
		if (result2 != false)
		{
			pos2 = get_position(currency, to);
		}
	}

	std::string line{};
	double amount{};
	std::cout << "\nWhat amount? ";
	while (std::getline(std::cin, line))
	{
		{
			std::stringstream ss(line);
			if (ss >> amount)
			{
				if (ss.eof())
				{
					break;
				}
			}
			std::cout << "Error! Please Re-enter ";
		}
	}
	std::cout << std::endl;
	std::cout << amount << currency.at(pos1) << " is equal to "
		<< calculate_conversion(currency.at(pos1), currency.at(pos2), amount) << currency.at(pos2) << std::endl;
	std::cout << std::endl;
}


std::string currency_from()
{
	std::string from{};
	std::cout << "\nWhat do you want to convert? ";
	std::getline(std::cin, from);
	return from;
}


std::string currency_to()
{
	std::string to{};
	std::cout << "\nTo what? ";
	std::getline(std::cin, to);
	return to;
}





bool find_position(const std::vector<Currency>& currency, const std::string name)
{
	if (std::find(currency.begin(), currency.end(), name) != currency.end())
	{
		return true;
	}
	std::cout << "Currency not found" << std::endl;
	return false;
}


int get_position(const std::vector<Currency>& currency, const std::string& name)
{
	int position{};
	for (auto item : currency)
	{
		if (name == item.get_name())
		{
			break;
		}
		position++;
	}
	return position;
}


void display_info(const std::vector<Currency>& currency)
{
	int i = 0;
	std::cout << "=========================" << std::endl;
	for (auto item : currency)
	{
		std::cout << item.get_name() << std::endl;
	}
	std::cout << "=========================" << std::endl;
}


void quit()
{
	std::cout << "You quit" << std::endl;
}


void unknown()
{
	std::cout << "Invalid choice" << std::endl;
}

