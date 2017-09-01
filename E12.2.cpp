// E12.2.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
	string str;
public:
	String();
	String(char *a);
	String operator+(const String & b);
	friend String operator+(char *a,String & b);
	void stringlow();
	void stringup();
	int has(const char a);
	friend ostream & operator<<(ostream&os, const String & b);
	friend istream & operator>>(istream&is, String & b);
	bool operator==(String &b);
};
String::String() {}
String::String(char *a) {
	str = a;
}
String String::operator+(const String &b) {
	int i = 0; int j = 0; char m[100] = { '\0' }; char n[100] = { '\0' };
	while (isalnum(str[i]) || str[i] == ' ' || str[i] == ':' || str[i] == '.' || str[j] == '+') {
		m[i] = str[i];
		i++;
	}
	while (isalnum(b.str[j]) || b.str[j] == ' ' || b.str[j] == ':' || b.str[j] == '.'||b.str[j]=='+') {
		n[j] = b.str[j];
		j++;
	}
	strcat(m, n);
	str = m;
	int a = 0;
	return *this; 
}
String operator+(char *a, String & b) {
	string sss; char temp[100] = { '\0' }; char temp1[100] = { '\0' };
	int i = 0; char *m = a;
	while (isalnum(*m) || *m == ' ' || *m == ':' || *m == '.' || *m == '+') {
		temp[i] = *m;
		i++; m++;
	}i = 0;
	sss = temp;
	while (b.str[i] != '\0') {
		temp1[i] = b.str[i];
		i++;
	}
	strcat(temp, temp1);
	b.str = temp;
	return b;
};
inline void String::stringlow() {
	int i = 0;
	while (isalnum(str[i]) || str[i] == ' ' || str[i] == ':' || str[i] == '.' || str[i] == '+') {
		if (isalpha(str[i])) {
			tolower(str[i]);
			i++;
		}
		else {
			i++;
		}
	}
}
inline void String::stringup() {
	int i = 0;  char m[100] = { '\0' };
	while (isalnum(str[i]) || str[i] == ' ' || str[i] == ':' || str[i] == '.' || str[i] == '+') {
		m[i] = str[i];
		if (isalpha(m[i])) {
			m[i] = toupper(m[i]);
			i++;
		}
		else {
			i++;
		}
	}
	str = m;
	int g = 0;
}
inline int String::has(const char a) {
	int i = 0; int  n = 0;
	while (isalnum(str[i]) || str[i] == ' ' || str[i] == ':' || str[i] == '.' || str[i] == '+') {
		if (str[i] == a) {
			n++; i++;
		}
		else {
			i++;
		}
	}
	return n;
}
ostream & operator<<(ostream&os, const String & b) {
	int i = 0;
	while (isalnum(b.str[i]) || b.str[i] == ' ' || b.str[i] == ':' || b.str[i] == '.' || b.str[i] == '+') {
			os << b.str[i];
			i++;
	}
	return os;
}
istream & operator >> (istream&is, String & b) {
	char sss[100] = { '\0' };
	char chi;
	cin >> chi;
	sss[0] = chi;
	cin.get(sss + 1, 100);
	int i = 0;
	b.str = sss;
	return is;
}
inline bool String::operator==(String&b) {
	int i = 0; bool flag;
	while (1) {
		if (str[i] == '\0'&&b.str[i] == '\0') {
			flag = true;
			return flag;
		}
		else if (str[i] == b.str[i]) {
			i++;
		}
		else if (str[i] != b.str[i]) {
			flag = false;
			return flag;
		}
	}
}
int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "The string\n" << s2 << "\ncotains " << s2.has('A') << " 'A' characters in it.\n";
	s1 = "red";
	String rgb[3] = { String(s1),String("green"),String("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans) {
		ans.stringlow();
		for (int i = 0; i < 3; i++) {
			if (ans == rgb[i]) {
				{
					cout << "That's right!\n";
					success = true;
					break;
				}
			}
		}
		if (success) {
			break;
		}
		else {
			cout << "Try again!\n";
		}
	}
	cout << "Bye\n";
	return 0;
}