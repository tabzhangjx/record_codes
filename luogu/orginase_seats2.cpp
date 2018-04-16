#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct seats{
	int number;
	int nums;
}lx[1001], ly[1001];

bool compare(const seats &a, const seats &b){
	return a.nums > b.nums;
}

int main()
{
	int M, N, K, L, D, i, nx = 0, ny = 0;
	int x[2000], y[2000], x2[2000], y2[2000];
	int ax[1000], ay[1000];

	cin >> M >> N >> K >> L >> D;
	for (i = 0; i < 1000; i++) {
		ax[i] = ay[i] = 0;
		lx[i].nums = lx[i].number = 0;
		ly[i].nums = ly[i].number = 0;
	}
		
	for (i = 0; i < D; i++)
	{
		cin >> x[i] >> y[i] >> x2[i] >> y2[i];
		if (x[i] == x2[i]) {
			ly[min(y[i], y2[i])].nums++;
			ly[min(y[i], y2[i])].number = min(y[i], y2[i]);
		}
		if (y[i] == y2[i]) {
			lx[min(x[i], x2[i])].nums++;
			lx[min(x[i], x2[i])].number = min(x[i], x2[i]);
		}
	}
	sort(lx, lx + M, compare);
	sort(ly, ly + N, compare);
	for (i = 0; i < K; i++)
	{
		ax[nx] = lx[i].number;
		nx++;
	}
	for (i = 0; i < L; i++)
	{
		ay[ny] = ly[i].number;
		ny++;
	}
	sort(ax, ax + nx);
	sort(ay, ay + ny);
	for (i = 0; i < nx; i++)
		cout << ax[i] << ' ';
	cout << '\n';
	for (i = 0; i < ny; i++)
		cout << ay[i] << ' ';
}