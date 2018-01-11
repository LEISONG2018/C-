#include <iostream>

#include "Bad.h"

using std::cout;

void pass_by_ref(Bad& b)
{
    cout << "Bad passed by reference: \n";
    cout << "        \"" << b << "\"" << std::endl;
}

void pass_by_val(Bad b)
{
    cout << "Bad passed by value: \n";
    cout << "        \"" << b << "\"" << std::endl;
}

int main()
{
    using std::endl;
    {
        cout << "Starting an inner block." << endl;
		//pass with pointer
        Bad first("aaa");
        Bad second("bbb");
        Bad third("ccc");
		
        cout << "first: " << first << endl;
        cout << "second: " << second << endl;
        cout << "third: " << third << endl
             << endl;


		//pass with reference object
        pass_by_ref(first);
        cout << "first: " << first << endl;


        pass_by_val(second);//pass with pointer 
        cout << "second: " << second << endl
             << endl;



        cout << "Initialize one object to another: \n";
        Bad fourth = third;
        cout << "fourth: " << fourth << endl
             << endl;

        cout << "Assign one object to another: \n";
        Bad fifth;
        fifth = first;
        cout << "fifth: " << fifth << endl
             << endl;

        cout << "Exiting the block!" << endl;
    }
    cout << "End of main()" << endl;

    std::cin.get();

    return 0;
}
