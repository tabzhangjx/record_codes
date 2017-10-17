// E13.1.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
class Cd {
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd() {};
	virtual ~Cd() {};
	virtual void Report() const;
	virtual Cd & operator=(const Cd & d);
};
Cd & Cd::operator=(const Cd & d) {
	int i = 0;
	while (d.performers[i] != '\0') {
		performers[i] = d.performers[i];
		i++;
	}
	performers[i] = '\0'; i = 0;
	while (d.label[i] != '\0') {
		label[i] = d.label[i];
		i++;
	}
	label[i] = '\0'; i = 0;
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
inline void Cd::Report() const{
	cout << performers << ',' << label << ',' << selections << ',' << playtime << endl;
}
Cd::Cd(char * s1, char * s2, int n, double x) {
	int i = 0; char *b = s1; char *c = s2;
	while (isalnum(*b) || (*b == ' ')) {
		performers[i] = *b;
		i++; b++;
	}
	performers[i] = '\0';
	i = 0;
	while (isalnum(*c)) {
		label[i] = *c;
		i++; c++;
	}
	label[i] = '\0';
	i = 0;
	selections = n;
	playtime = x;
}
class Classic :public Cd {
private:
	char work1[100];
	char work2[100];
public:
	Classic() {};
	Classic(char * s1, char * s2, char*s3, char*s4, int n, double x);
	virtual ~Classic() {};
	virtual void Report () const;
	virtual Classic & operator=(const Classic & d);
};
inline void Classic::Report() const{
	cout << work1 << ", " << work2 << ',';
	Cd::Report();
}
Classic::Classic(char * s1, char * s2, char*s3, char*s4, int n, double x) :Cd(s3, s4, n, x) {
	int i = 0; char *b = s1; char *c = s2;
	while (isalnum(*b) || (*b == ' ')) {
		work1[i] = *b;
		i++; b++;
	}
	work1[i] = '\0';
	i = 0;
	while (isalnum(*c) || (*c == ' ')) {
		work2[i] = *c;
		i++; c++;
	}
	work2[i] = '\0';
	i = 0;
}
Classic & Classic::operator=(const Classic & d)  {
	int i = 0;
	while (d.work1[i] != '\0') {
		work1[i] = d.work1[i];
		i++;
	}
	work1[i] = '\0'; i = 0;
	while (d.work2[i] != '\0') {
		work2[i] = d.work2[i];
		i++;
	}
	work2[i] = '\0'; i = 0;
    Cd::operator=(d);
	return *this;
}
void Bravo(const Cd & disk) {
	
	disk.Report();
}
int main(){
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