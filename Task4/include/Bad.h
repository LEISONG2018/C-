#pragma once

#include <iostream>

class Bad {
private:
    char* str;
    int len;

public:
    Bad(const char* s);
    Bad();
	Bad(const Bad &);
    ~Bad();

    friend std::ostream& operator<<(std::ostream& os,
        const Bad& st);
	Bad & operator=(const Bad &);
	//Bad & operator=(const char *);
};
