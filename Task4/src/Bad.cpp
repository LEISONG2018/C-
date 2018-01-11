#include "Bad.h"

#include <cstring>

using std::cout;


/*class Bad {
private:
    char* str;
    int len;
	static int num_strings;
	static const int CINLIM = 80;

public:
    Bad(const char* s);
    Bad();
    ~Bad();

    friend std::ostream& operator<<(std::ostream& os,
        const Bad& st);
};*/



Bad::Bad(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);

}

Bad::Bad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "c++");

}

Bad::Bad(const Bad & st)
{

	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

Bad::~Bad()
{
    cout << "\"" << str << "\" object deleted, ";
	
    delete[] str;
}


Bad & Bad::operator=(const Bad & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

/*Bad & Bad::operator=(const char * s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}*/

std::ostream& operator<<(std::ostream& os, const Bad& b)
{
    os << b.str;
    return os;
}
