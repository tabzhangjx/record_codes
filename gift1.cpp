/*
ID: tabzhan1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream fin("gift1.in");
ofstream fout("gift1.out");

struct people {
	string name;
	int wholemoney = 0;
	int getmoney = 0;
};

void give(int NP1, people *aa) {
	people *bb = aa;
	string temname;
	getline(fin, temname);
	int m, n;
	int temp;
	fin >> m >> n;
	for (int i = 0; i < NP1; i++) {
		if (aa->name == temname) {
			aa->wholemoney += m;
			if (n != 0) {
				temp = m / n;
				temp = m - temp*n;
				aa->getmoney += temp;
			}
			break;
		}
		else {
			aa++;
		}
	}
	aa = bb;
	string chi;
	getline(fin, chi);
	int qqq = 0;
	if (n == 0) {
		for (int i = 0; i < NP1; i++) {
			if (aa->name == temname) {
				aa->getmoney += m;
				break;
			}
			else {
				aa++;
			}
		}
		aa = bb;
	}
	else {
		string ttt;
		for (int i = 0; i < n; i++) {
			getline(fin, ttt);
			for (int i = 0; i < NP1; i++) {
				if (aa->name == ttt) {
					aa->getmoney += m / n;
					break;
				}
				else {
					aa++;
				}
			}
			aa = bb;
		}
	}
}

void show(int NP1, people * aa) {
	people *bb = aa;
	for (int i = 0; i < NP1; i++) {
		int t = aa->getmoney - aa->wholemoney;
		fout << aa->name << ' ' << t << endl;
		aa++;
	}
	aa = bb;
}

int main() {
	int NP;
	fin >> NP;
	string chi;
	getline(fin, chi);
	people *p = new people[NP];
	people *a = p;
	for (int i = 0; i < NP; i++) {
		getline(fin, a->name);
		a++;
	}
	a = p;
	for (int i = 0; i < NP; i++) {
		give(NP, a);
	}
	show(NP, a);
	delete[]p;
	return 0;
}