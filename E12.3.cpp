#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Stock
{
private:
	char * company;
	int shares;
	double share_val;
	double total_val;
	void set_tot(int a , double b);
public:
	Stock();
	Stock(const char * co, long n, double pr);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	friend ostream & operator<<(ostream & os, const Stock & b);
	const Stock & topval(const Stock & s) const;
};
Stock::Stock()
{
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
	int len;
	len = strlen(co);
	company = new char[len + 1];
	//company = (char *)co;
	strcpy(company, co);
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else {
		shares = n;
	}
	share_val = pr;
	set_tot(shares, share_val);
	int a = 11;
}

Stock::~Stock()
{
	delete[]company;
}

void Stock::buy(const long num, const double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot(shares ,share_val);
	}
}

void Stock::sell(const long num, const double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot(shares, share_val);
	}
}

void Stock::update(const double price)
{
	share_val = price;
	set_tot(shares, share_val);
}

ostream & operator<<(ostream & os,const Stock & b)
{
	using std::ios_base;
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	os << "Company: ";
	os << b.company;
	os << "  Shares: " << b.shares << '\n';
	os << "  Share Price: $" << b.share_val;
	cout.precision(2);
	os << "  Total Worth: $" << b.total_val << '\n';
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
	return os;
}

inline void Stock::set_tot(int a, double b) {
	total_val = a * b; 
}

const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

int main() {
		const int STKS = 4;
		Stock stocks[STKS] = {
			Stock("NanoSmart", 12, 20.0),
			Stock("Boffo Objects", 200, 2.0),
			Stock("Monolithic Obelisks", 130, 3.25),
			Stock("Fleep Enterprises", 60, 6.5)
		};
		std::cout << "Stock holdings:\n";
		int st;
		for (st = 0; st < STKS; st++) {
			cout << stocks[st];
		}
		const Stock * top = &stocks[0];
		for (st = 1; st < STKS; st++) {
			top = &top->topval(stocks[st]);
		}
		std::cout << "\nMost valuable holding:\n";
		cout << *top;
		int a = 0;
	return 0;
}