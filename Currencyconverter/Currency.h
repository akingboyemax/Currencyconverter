#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>


class Currency
{
	friend std::ostream& operator<< (std::ostream& os, Currency& currency);
	friend std::istream& operator>>(std::istream& is, Currency& currency);
	friend double calculate_conversion(Currency& from, Currency& to, double amount);
private:
	std::string name;
	double value;
public:
	Currency(std::string name = "None", double value = 0.0);
	bool operator<(const Currency& rhs) const;
	bool operator==(const Currency& rhs) const;
	std::string get_name()const
	{
		return name;
	}
	~Currency() = default;
	bool check_validity(const std::vector<Currency>& currency);
};