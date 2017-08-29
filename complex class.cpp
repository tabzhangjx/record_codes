// complex class.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
class complex_ {
private:
	int A, B;
public:
	complex_(int , int );
	complex_ operator+(const complex_ &);
	complex_ operator-(const complex_ &);
	complex_ operator*(const complex_ &);
	friend complex_ operator*(const int a,complex_ &);
	complex_ operator~();
	friend istream & operator >> (istream & is, complex_&b);
	friend ostream & operator << (ostream & os,const complex_&b);
};
complex_::complex_(int a = 0, int b = 0) {
	A = a;
	B = b;
}
complex_ complex_::operator+(const complex_&b) {
	complex_ c3;
	c3.A = A + b.A;
	c3.B = B + b.B;
	return c3;
}
complex_ complex_::operator-(const complex_&b) {
	complex_ c3;
	c3.A = A - b.A;
	c3.B = B - b.B;
	return c3;
}
complex_ complex_::operator*(const complex_&b) {
	complex_ c3;
	c3.A = A*b.A - B*b.B;
	c3.B = A*b.B + B*b.A;
	A = c3.A;
	B = c3.B;
	return c3;
}
complex_ operator*(const int a,complex_ & b) {
	b.A = a*b.A;
	b.B = a*b.B;
	return b;
}
complex_ complex_::operator~() {
	complex_ c3;
	c3.A = A;
	c3.B = -B;
	return c3;
}
istream & operator >> (istream & is, complex_&b){
	int jud;
	cout << "real:";
	cin >> jud;
	if (jud > 0) {
		b.A = jud;
		cout << "imaginary:";
		is >> b.B;
		return is;
	}
	else {
		return is;
	}
}
ostream & operator << (ostream & os,const complex_&b){
	os << "(" << b.A << "," << b.B << "i)";
	return os;
}
int main()
{
	complex_ a(3.0, 4.0);
	complex_ c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << "\n";
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	return 0;
}