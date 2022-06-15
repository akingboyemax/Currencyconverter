#pragma once
#include "Currency.h"

void display_menu();
void add_currency(std::vector<Currency>& currency);
void convert_currency(std::vector<Currency>& currency);
std::string currency_from();
std::string currency_to();
bool find_position(const std::vector<Currency>& currency, const std::string name);
int get_position(const std::vector<Currency>& currency, const std::string& name);
void display_info(const std::vector<Currency>& currency);
void quit();
void unknown();
