#include "EuropeanOption.h"

#include <iostream>

// TODO: define derived class methods

EuropeanOption::EuropeanOption(std::string date,float p) :Option(p) 
{
	expiration_date = date;
	price = p;
};
EuropeanOption::EuropeanOption(const EuropeanOption& option) :Option(option) 
{
	expiration_date = option.expiration_date;
	price = option.price;
};//?

EuropeanOption::EuropeanOption() {};

void EuropeanOption::printInfo() const
{
    // TODO: fill this part 
	std::cout << "price = " << price << std::endl;
	std::cout << "Expiration Date: " << expiration_date << std::endl;
}
