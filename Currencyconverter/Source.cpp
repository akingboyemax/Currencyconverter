#include<iostream>
#include "Currency_util.h"

int main()
{
	Currency dollar{ "Dollars", 1 };
	Currency pound{ "Pounds",1.21 };
	Currency euro{ "Euros", 1.05 };
	Currency diram{ "Dirams", 0.27 };
	Currency naira{ "Naira", 0.0024 };

	std::vector<Currency>currency{ dollar, pound, euro, diram, naira };

	char selection;
	do
	{
		display_menu();
		std::cout << "\nWhat do you want to do? ";
		std::cin >> selection;
		selection = std::toupper(selection);

		switch (selection)
		{
		case 'A':
			add_currency(currency);
			break;
		case 'C':
			convert_currency(currency);
			break;
		case 'D':
			display_info(currency);
			break;
		case 'Q':
			quit();
			break;
		default:
			unknown();
		}
	} while (selection != 'Q');
}
