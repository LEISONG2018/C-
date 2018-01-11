#include "Option.h"

#include <iostream>

// TODO: define base class methods



/*class Option {
private:
    float price;

public:
    Option(float p);
    Option(const Option& option);
    Option();
    ~Option(){};
    void printInfo() const;
    Option& operator=(const Option& option);
};*/


Option::Option(float p) :price(p) {};
Option::Option(const Option& option) 
{
	price = option.price;
};

Option::Option() {};

void Option::printInfo() const
{
    std::cout << "price = " << this->price << std::endl;
}

Option& Option::operator=(const Option& option)
{
    this->price = option.price;

    return *this;
}
