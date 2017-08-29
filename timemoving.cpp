/*
ID: tabzhan1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream fin("friday.in");
ofstream fout("friday.out");


int main() {
	int n;
	fin >> n;
	int day[8] = { 0 };
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	int theday = 1;
	for (int i = 1; i <= n; i++) {
		if ((i - 1 + 1900) % 400 == 0) {
			month[2] = 29;
		}
		else if ((i - 1 + 1900) % 100 == 0) {
			month[2] = 28;
		}
		else if ((i - 1 + 1900) % 4 == 0) {
			month[2] = 29;
		}
		else {
			month[2] = 28;
		}
		for (int j = 1; j <= 12; j++) {
			days = month[j];
			for (int k = 1; k <= days; k++) {
				if (theday == 8) {
					theday = theday - 7;
				}
				if (k == 13) {
					day[theday++]++;
				}
				else {
					theday++;
				}
			}
		}
	}
	fout << day[6] << ' ';
	fout << day[7];
	for (int i = 1; i < 6; i++) {
		fout << ' ' << day[i];
	}
	fout << endl;
	return 0;
}