// piecewise function.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;

	int x = 0;
	int y = 0;

	cin >> x;

	if (x > 0)
		y = 3 * x + 1;
	else
		if (x < 0)
			y = (x*x) - 1;
		else
			y = 0;


	cout << y;
    return 0;
}

