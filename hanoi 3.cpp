// hanoi 3.cpp : �������̨Ӧ�ó������ڵ㡣
//��������������Լ�д�ģ�

#include "stdafx.h"
#include <iostream>;
using namespace std;
int s = 0;
void move(int n, char x, char y) {
	s++;
	cout << "# " << s << " move *" << n << " from " << x << " to " << y << endl;
}
void hanoi(int n, char j, char y, char t) {
	if (n == 1) {
		move(n, j, t);
	}
	else {
		hanoi(n - 1, j, t, y);
		move(n , j, t);
		hanoi(n - 1, y, j, t);
	}
}

int main()
{
	int i = 0; char a = 'j'; char b = 'y'; char c = 't';
	cin >> i;
	hanoi(i, a, b, c);
    return 0;
}

