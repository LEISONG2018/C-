#pragma once

#include "Option.h"

#include <string>

/*class Option {
private:
	float price;

public:
	Option(float p);
	Option(const Option& option);
	Option();
	~Option() {};
	void printInfo() const;
	Option& operator=(const Option& option);
};*/




// derived class
class EuropeanOption : public Option {
private:
    std::string expiration_date;
	float price;

public:
    //TODO: fill this part
	EuropeanOption(std::string date ,float p);
	EuropeanOption();
	~EuropeanOption() {};
	EuropeanOption(const EuropeanOption& option);
	void printInfo() const override;
	//EuropeanOption& operator=(const Option&option);
};
