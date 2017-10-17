#include<iostream>
using namespace std;
void assemble(int n = 0, int k = 0, int sum = 0) {
	if (k != 1) {
		sum = sum * 10 + n;
		assemble(n - 1, k - 1, sum);
	}
	if (k == 1) {
		sum = sum * 10 + 1;
		cout << sum;
	}
}
int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	assemble(n, k);
    return 0;
}