// bank account.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <cstring>
using namespace std;

class account {
private:
	
	string name;
	string accountnumber;
	int balance;

public:

	account(string & str, string &str2, int a);
	void deposite();
	void withdraw();

};
account::account(string & str, string &str2, int a = 0) {
	cin >> a;
	name = str;
	accountnumber = str2;
	balance = a;
	cout << a << endl;
}
void account::deposite() {
	int a = 0;
	cin >> a;
	balance = balance + a;
	cout << balance << endl;
}
void account::withdraw() {
	int a = 0;
	cin >> a;
	if (balance >= a) {
		cout << balance - a;
	}
	else {
		cout << "no enough balance!";
	}
}
int main()
{
	string s1 = "no name";
	string s2 = "xxx";
	account p1(s1, s2);
	p1.deposite();
	p1.withdraw();
    return 0;
}

