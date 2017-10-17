// E14.3.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
using namespace std;

template <class t1,class t2>
class worker {
private:
	t1 fullname;
	t2 id;
protected:
	virtual void data_();
	virtual void get_();
public:
	worker() :fullname("no one"), id(0L) {};
	worker(const t1 & s, t2 n) :fullname(s), id(n) {};
	virtual ~worker() = 0;
	virtual void set() = 0;
	virtual void show() const = 0;
};

class waiter :virtual public worker<string, long> {
private:
	int panache;
public:
	waiter() :worker(), panache(0) {};
	waiter(const string &s, long n, int p = 0) :worker(s, n), panache(p) {};
	waiter(const worker  & wk, int p = 0) :worker(wk), panache(p) {};
	void set();
	void show() const;
};

class singer :virtual public worker<string, long> {
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { vtypes = 7 };
	void data_() const;
	void get_();
private:
	static char * pv[vtypes];
	int voice;
public:
	singer() :worker(), voice(other) {};
	singer(const string &s, long n, int v = other) :worker(s, n), voice(v) {};
	singer(worker & wk, int v = other) :worker(wk), voice(v) {};
	void set_();
	void show() const;
};

class singingwaiter :public singer, public waiter {
protected:
	void data() const;
	void get_();
public:
	singingwaiter() {};
	singingwaiter(const string & s, long n, int p = 0, int v = other) :worker(s, n), waiter(s, n, p), singer(s, n, v) {};
	singingwaiter(const worker & wk, int p = 0, int v = other) :worker(wk), waiter(wk, p), singer(wk, v) {};
	singingwaiter(const waiter &wt, int v = other) :worker(wt), waiter(wt), singer(wt, v) {};
	singingwaiter(const singer & wt, int p = 0) :worker(wt), waiter(wt, p), singer(wt) {};
	void set_();
	void show() const;
};

worker<string, long>::~worker() {};

void worker<string, long>::data_() {
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void worker<string, long>::get_() {
	getline(cin, fullname);
	cout << "Enter waiter`s ID：";
	cin >> id;
	while (cin.get != '\n')
		continue;
}

void waiter::set(){
	cout << "Enter waiter`s name: ";
	worker::get_();
	get_();
}

void waiter::show() const {
	cout << "Category: waiter\n";
	worker<string,long>::data_();
	data_;
}

int main()
{
    return 0;
}

