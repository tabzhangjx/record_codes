// leap.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;

	int a = 0;

	cin >> a;

	if (a % 4 == 0)
		if (a % 100 != 0)
				cout << "Y";
		else
			if (a % 400 == 0)
			cout << "Y";
		    else
			cout << "N";
	else
		cout << "N";
    return 0;
}

