#include "FEString.h"

#include <cstring>
#include <string>

using std::cin;
using std::cout;

int FEString::num_strings = 0;

int FEString::HowMany()
{
    return num_strings;
}

FEString::FEString(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

FEString::FEString()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

FEString::FEString(const FEString& st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

FEString::~FEString()
{
    --num_strings;
    delete[] str;
}

FEString& FEString::operator=(const FEString& st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

FEString& FEString::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char& FEString::operator[](int i)
{
    return str[i];
}

const char& FEString::operator[](int i) const
{
    return str[i];
}

bool operator<(const FEString& st1, const FEString& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const FEString& st1, const FEString& st2)
{
    return st2 < st1;
}

bool operator==(const FEString& st1, const FEString& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const FEString& st)
{
    os << st.str;
    return os;
}

istream& operator>>(istream& is, FEString& st)
{
    char temp[FEString::CINLIM];
    is.get(temp, FEString::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

void FEString::stringlow()
{
    // TODO: fill this part
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

void FEString::stringup()
{
    // TODO: fill this part
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}

int FEString::scan(char c)
{
    // TODO: fill this part
	int ct = 0;
	char * ps = str;
	while (*ps)
	{
		if (*ps++ == c)
			++ct;
	}
	return ct;
}

FEString operator+(const char* s1, FEString& st1)
{
    char* str = new char[80];
    std::strcpy(str, s1);
    std::strcat(str, st1.str);

    return FEString(str);
}

FEString FEString::operator+(const FEString& st)
{
    int length = st.length() + len;
    char* cpy = new char[length + 2];
    std::strcpy(cpy, str);
    std::strcat(cpy, st.str);
    FEString b(cpy);

    return b;
}
