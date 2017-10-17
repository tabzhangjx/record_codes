//hanoi.cpp
//Solve the Hanoi problem
#include "stdafx.h"
#include <iostream>
using namespace std;
int cnt = 0;
void move(int n, char x, char z)
{
	cout << "#" << cnt << " move *" << n << " from " << x << " to " << z << "\n";
	cnt++;
}
void hanoi(int n, char x, char y, char z)
{
	if (n == 1) {
		move(1, x, z); 
	}
	else {
		hanoi(n - 1, x, z, y); 
		move(n, x, z); 
		hanoi(n - 1, y, x, z); 
	}
}
int main()
{
	int k;
	cout << "How many plates\n";
	cin >> k;
	hanoi(k, 'J', 'Y', 'T');
	return 0;
}
