#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Cd {
private:
	char * performers;
	char * label;
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd() {};
	virtual ~Cd();
	virtual void Report() const;
	virtual Cd & operator=(const Cd & d);
};
Cd & Cd::operator=(const Cd & d) {
	int len = 0;

	len = strlen(d.performers);
	performers = new char[len + 1];
	strcpy(performers, d.performers);

	len = strlen(d.label);
	label = new char[len + 1];
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
inline void Cd::Report() const {
	cout << performers << ',' << label << ',' << selections << ',' << playtime << endl;
}
Cd::Cd(char * s1, char * s2, int n, double x) {
	int len = 0;
	len = strlen(s1);
	performers = new char[len + 1];
	strcpy(performers, s1);
	len = strlen(s2);
	label = new char[len + 1];
	strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd::~Cd() {
	delete[]performers;
	delete[]label;
}
class Classic :public Cd {
private:
	char * work1;
	char * work2;
public:
	Classic() {};
	Classic(char * s1, char * s2, char*s3, char*s4, int n, double x);
	virtual ~Classic();
	virtual void Report()const;
	virtual Classic & operator=(const Classic & d);
};
inline void Classic::Report()const {
	cout << work1 << ", " << work2 << ',';
	Cd::Report();
}
Classic::Classic(char * s1, char * s2, char*s3, char*s4, int n, double x) :Cd(s3, s4, n, x) {
	int len = 0;
	len = strlen(s1);
	work1 = new char[len+1];
	strcpy(work1, s1);
	len = strlen(s2);
	work2 = new char[len+1];
	strcpy(work2, s2);
}
Classic::~Classic() {
	delete[]work1;
	delete[]work2;
}
Classic & Classic::operator=(const Classic & d) {
	int len = 0;

	len = strlen(d.work1);
	work1 = new char[len + 1];
	strcpy(work1, d.work1);

	len = strlen(d.work2);
	work2 = new char[len + 1];
	strcpy(work2, d.work2);

	Cd::operator=(d);
	return *this;
} 
void Bravo(const Cd & disk) {

	disk.Report();
}
int main() {
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat", "Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	return 0;
}