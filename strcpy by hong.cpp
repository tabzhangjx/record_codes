#include "stdafx.h"
#include <iostream>
using namespace std;
#define Conn(x,y) x##y
int main()
{
	char* str = Conn("vgvdf", "advf");
	cout << str;
	return 0;
}
