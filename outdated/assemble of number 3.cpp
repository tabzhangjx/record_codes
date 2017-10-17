#include <iostream>
//#include <ctime>
using namespace std;
int main()
{
	time_t start, end, time;
	int i, j = 1;
	int n, k; cin >> n >> k; int *p = new int[k]; int *a = p; int *b = p + k - 1;
	/*start = clock();*/
	for (i = 0; i < k; a++, i++) { *a = n - i; };
	while (b >= p) {
		while (*b >= j&& *(p + k - 1) > 0) {
			for (a = p; a < p + k; a++) {
				cout << *a;
			}
			(*b)--; cout << endl;
		}
		b--; j++;
		if (*b > j&&b >= p)
			(*b)--;
		else
			continue;
		while (b + 1 < p + k) {
			(*(b + 1)) = (*(b)) - 1;
			b++; j--;
		}
	}
	/*end = clock();
	time = end - start;*/
	delete[]p;
	/*cout << time / 1000.0;
	system("pause");*/
    return 0;
}