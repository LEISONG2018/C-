#pragma once

// base class
class Option {
private:
    float price;

public:
    Option(float p);
    Option(const Option& option);
    Option();
    ~Option(){};
	virtual void printInfo() const;
    Option& operator=(const Option& option);
};
