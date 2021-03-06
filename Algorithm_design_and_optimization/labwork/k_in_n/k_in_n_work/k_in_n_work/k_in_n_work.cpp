#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<random>
#include<ctime>
using namespace std;
std::ofstream fout("data");
int comp(int*b, int l) {
	l++;
	for (int p = l;; p++) {
		if (b[p] != -1) {
			return p;
		}
	}
}
void search(int* a, int k, int i) {
	for (int t = 0; t < k; t++) {
		for (int m = 0;; m++) {
			if (a[m] != -1 && a[m] > a[comp(a, m)]) {
				a[m] = -1;
				break;
			}
		}
	}
}

void givearandom(int a) {
	
	for (int i = 0; i < a; i++) {
		int b = rand() % 10;
		fout << b << ' ';
	}
	
}


int main() {
	{
		int T = 1;
		srand(time(0));
		fout << T << endl;
		for (int i = 0; i < T; i++) {
			int a = rand() % 100000;
			fout << a << endl;
			givearandom(a);
			int m = rand() % a;
			fout << endl << m << endl;
		}
		fout.close();
	}
	{
		ifstream fin("data");
		ofstream fout("res.txt");
		int T;
		fin >> T;
		for (int round = 0; round < T; round++) {
			int n; int k;
			int line[100000];
			fin >> n;
			for (int i = 0; i < n; i++) {
				fin >> line[i];
			}
			fin >> k;
			int t0 = clock();
			search(line, k, n);
			int t1 = clock();
			fout << round + 1 << ":  " << n << ' ' << k << ' ' << t1 - t0 << endl;
			int flag = 1;
			int t = 0;
			for (t = 0; t < n; t++) {
				if (line[t] != 0 && line[t] != -1) {
					break;
				}
			}
			for (; t < n; t++) {
				if (line[t] != -1) {
					fout << line[t] << ' ';
				}
			}
			fout << endl;
		}
		fin.close();
		fout.close();
	}
	return 0;
}