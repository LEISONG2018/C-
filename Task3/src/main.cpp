#include <iostream>

#include "EuropeanOption.h"
#include "Option.h"

using namespace std;

void fun(const Option& option);

int main()
{
    Option option1(555.5);
    EuropeanOption option2 = EuropeanOption("01-01-2017", 666.6);

    cout << "\nUsing object directly: \n";
    option1.printInfo();
    option2.printInfo();

    cout << "\nUsing type Option * pointer to objects: \n";
    Option* option_p = &option1;
    option_p->printInfo();
    option_p = &option2;
    option_p->printInfo();

    cout << "\nCalling a function with a Option reference argument: \n";
    fun(option1);
    fun(option2);

    cout << "\nTesting assignment: \n";
    EuropeanOption option3;
    option3 = option2;
    option3.printInfo();
    return 0;
}

void fun(const Option& option)
{
    option.printInfo();
}
