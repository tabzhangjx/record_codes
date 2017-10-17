#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

ifstream fin("C:\\projecttxt\\result.txt", ios::binary);
ofstream fout("C:\\projecttxt\\result3.txt", ios::binary);

int main() {
	ostringstream texttemp;
	char temp;
	char temp1;
	while (texttemp&&fin.get(temp)) {
		texttemp.put(temp);
	}
	string text = texttemp.str();
	fout << text;
	fin.close();
	fout.close();
	fin.open("C:\\projecttxt\\result3.txt", ios::binary);
	fout.open("C:\\projecttxt\\result5", ios::binary);
	
	ostringstream texttemp1;
	while (texttemp1&&fin.get(temp1)) {
		texttemp1.put(temp1);
	}
	string text1 = texttemp1.str();
	fout << text1;
	fout.close();
	fout.open("C:\\projecttxt\\result4");
	fout << text1;
	return 0;
}
//void look(int (&p)[10][10], int i, int j) {
//	int t = 0;
//	
//}
//int main() {
//	int a[10][10] = { '\0' };
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			a[i][j] = i * 10 + j;
//		}
//	}
//	look(a, 5, 5);
//
//}