#include <iostream>
using namespace std;


const int max_n = 1000;
const int max_c = 10000;
int weight[max_n] = { 23,52,64,12,76,3,8,98,35,76 };
int value[max_n] = { 34,64,67,85,24,5,35,64,3,5 };
int bag[max_c];
bool visited[10] = { 0,0,0,0,0,0,0,0,0,0 };

void Select(int n, int c)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = c; j >= weight[i]; j--)
		{
			if (bag[j - weight[i]] + value[i] > bag[j])
				bag[j] = bag[j - weight[i]] + value[i];
		}
	}
	cout << n << " : " << c << " : " << bag[c] << endl;
}


int main()
{
	/*int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i] >> value[i];
	}
	Select(n, w);*/
	for (int i = 0; i < max_c; i++) {
		bag[i] = 0;
	}
	Select(10, 300);
	for (int i = 0; i < max_c; i++) {
		bag[i] = 0;
	}
	Select(10, 30);
	for (int i = 0; i < max_c; i++) {
		bag[i] = 0;
	}
	Select(10, 20);
	for (int i = 0; i < max_c; i++) {
		bag[i] = 0;
	}
	Select(10, 50);
	for (int i = 0; i < max_c; i++) {
		bag[i] = 0;
	}
	Select(10, 237);
	for (int i = 0; i < max_c; i++) {
		bag[i] = 0;
	}
	Select(10, 196);
	return 0;
}