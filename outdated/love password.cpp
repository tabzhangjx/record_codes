// love password.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;

	int i = 1;
	int a = 0;


	while (i <= 3) {
		cout << "Enter Password",
			cin >> a;
		if (a == 525252)
			cout << "u r my milktea, will continue...";
		else
			i++, cout << endl;
	}
    return 0;
}

