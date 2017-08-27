#include "stdafx.h" 
#include <iostream>
using namespace std;
long long jiecheng(int n = 0,long long tep=1) {
	if (n != 1) {tep = jiecheng(n - 1, tep*n);}
	else {cout << tep;return 0;}}
int main()
{   int n = 0; cin >> n;jiecheng(n);
	return 0;}