// arith.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> std;


int main()
{
	using namespace std;
	float number1, number2;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Enter aa number:";
	cin >> number1;
	cout << "Enter a number:";
	cin >> number2;

	cout << number1 << endl << number2 << endl;
    return 0;
}

