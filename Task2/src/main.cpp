#include <iostream>

#include "FEString.h"

int main()
{
    using namespace std;

    FEString s1(" and I am a FE student.");
    FEString s2 = "Please enter your name: ";
    FEString s3;

    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string: \"" << s2 << "\" contains " << s2.scan('A') << " 'A' characters in it.\n";
    s1 = "red";
    FEString rgb[3] = { FEString(s1), FEString("green"), FEString("blue") };
    cout << "Enter the name of a primary color for mixing light: ";
    FEString ans;
    bool success = false;
    while (cin >> ans) {
        ans.stringlow();
        for (int i = 0; i < 3; i++) {
            if (ans == rgb[i]) {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";
    return 0;
}
