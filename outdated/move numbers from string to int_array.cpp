// move numbers from string to int_array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	char str[10001] = { '\0' }; char tem[101] = { '\0' }; int ary[1000]; int i = 0; int j = 0; int k = 0; int t = 0;
	cin.getline(str, 1000);
	while (str[i] != '\0') {
		while (isdigit(str[i])) {
			tem[j] = str[i];
			i++; j++; t++;
		}j = 0;
		while (t != 0) {

		}
	}
	return 0;
}

