#include <iostream>
#include <cstdio>
using namespace std;

void charArray()
{
    char carray[5];
    for(int i = 0; i < 5; ++i)
    {
        carray[i] = i + '0';
    }
}

int main()
{
    char ca[4];
    charArray();
    for(int i = 0; i < 4; ++i)
    {
        ca[i] = i + '0';
    }
    getchar();
    return 0;
}