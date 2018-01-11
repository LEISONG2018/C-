#pragma once

#include <iostream>

using std::istream;
using std::ostream;

class FEString {
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    FEString(const char* s);
    FEString();
    FEString(const FEString&);
    ~FEString();
    int length() const { return len; }

    FEString& operator=(const FEString&);
    FEString& operator=(const char*);
    char& operator[](int i);
    const char& operator[](int i) const;
    void stringlow();
    void stringup();

    int scan(char c);

    friend bool operator<(const FEString& st, const FEString& st2);
    friend bool operator>(const FEString& st1, const FEString& st2);
    friend bool operator==(const FEString& st, const FEString& st2);
    friend ostream& operator<<(ostream& os, const FEString& st);
    friend istream& operator>>(istream& is, FEString& st);

    friend FEString operator+(const char* s1, FEString& st1);
    FEString operator+(const FEString& st);

    static int HowMany();
};
