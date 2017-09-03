#include <iostream>
using namespace std;
int *selecter; int i = 1;
class student {
private:
	int Id_;
	int class_;
	char name_[6];
	float score1_;
	float score2_;
	float score3_;
	float sumscore_;
public:
	void input();
	void output();
	student();
	~student();
	student operator=(student & b);
	int check(int *);
	friend bool compare(int *);
};
class grade {
private:
public:
	void create();
	void deleteone();
	void reorder();
	void select();
}grade1;
class menu {
private:
public:
	void start();
};
student::student() {
	student::Id_ = 0;
	student::class_ = 0;
};
student::~student() {};
student students[6];
inline void student::input() {
	char chi = '\0';
	cout << "Id "; cin >> Id_;
	cout << "class "; cin >> class_;
	cout << "name ";
	while (!isalpha(chi)) {
		cin >> chi;
	}cin.getline(name_+1, 6); name_[0] = chi;
	cout << "score1 "; cin >> score1_;
	cout << "score2 "; cin >> score2_;
	cout << "score3 "; cin >> score3_;
	sumscore_ = score1_ + score2_ + score3_;
}
inline void student::output() {
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(1);
	if (Id_ != 0) {
		int i = 0;
		cout << Id_ << "," << class_ << ",";
		while (isalnum(name_[i])) {
			cout << name_[i]; i++;
		}
		cout << "," << score1_ << ',' << score2_ << ',' << score3_ << ',' << sumscore_ << endl;
	}
	else {}
}
inline int student::check(int *a) {
	if (Id_ == *a || class_ == *a) {
		return 1;
	}
	else if (Id_ == 0) {
		return -1;
	}
	else {
		return 0;
	}
}
student student::operator=(student & b) {
	student trans;
	Id_ = b.Id_;
	class_ = b.class_;
	int temp = 0;
	while (temp < 6) {
		name_[temp] = b.name_[temp];
		temp++;
	}
	score1_ = b.score1_;
	score2_ = b.score2_;
	score3_ = b.score3_;
	sumscore_ = b.sumscore_;
	return trans;
}
bool compare(int * i) {
	int m = *i;
	if ((students[m].class_ > students[m + 1].class_) && students[m + 1].class_ != 0) {
		return true;
	}
	else {
		if (students[m].sumscore_ < students[m + 1].sumscore_ && students[m + 1].sumscore_ != 0) {
			return true;
		}
		else {
			return false;
		}
	}
}
inline void grade::create() {
	students[i - 1].input();
	i++;
}
inline void grade::deleteone() {
	int judgement = 0; cin >> judgement; int jud = -999; int i = 0;
	while (1) {
		jud = students[i].check(&judgement);
		if (jud == 1) {
			while (i <= 5) {
				students[i] = students[i + 1];
				i++;
			}
		}
		else if (jud == 0) {
			i++;
		}
		else {
			break;
		}
	}
	i = 0;
	while (i <= 5) {
		students[i].output();
		i++;
	}
}
inline void grade::reorder() {
	student temp; int i = 0; int n = 0;
	while (n <= 3) {
		while (i <= 4) {
			if (compare(&i)) {
				temp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = temp;
				i++;
			}
			else {
				i++;
			}
		}
		i = 0; n++;
	}
	i = 0;
	while (i <= 5) {
		students[i].output();
		i++;
	}
}
inline void grade::select() {
	int*option = selecter;
	if (*option == 1) {
		char chi;
		while (1) {
			grade1.create();
			cout << "continue?"; cout << endl;
			char temp[5] = { '\0' };
			while (1) {
				cin >> chi;
				if (isalpha(chi)) {
					break;
				}
			}
			temp[0] = chi; cin.get(temp + 1, 3);
			if (temp[0] == 'y'&&temp[1] == 'e'&&temp[2] == 's') {}
			else if (temp[0] == 'n'&&temp[1] == 'o') { break; }
			else { cout << "please enter the right option,now is equal to enter 'no'."; break; }
		}
	}
	else if (*option == 2) {
		char chi;
		while (1) {
			grade1.deleteone();
			cout << "continue?"; cout << endl;
			char temp[5] = { '\0' };
			while (1) {
				cin >> chi;
				if (isalpha(chi)) {
					break;
				}
			}
			temp[0] = chi; cin.get(temp + 1, 3);
			if (temp[0] == 'y'&&temp[1] == 'e'&&temp[2] == 's') {}
			else if (temp[0] == 'n'&&temp[1] == 'o') { break; }
			else { cout << "please enter the right option,now is equal to enter 'no'."; break; }
		}
	}
	else if (*option == 3) {
		int judgement; int i = 0; int jud; int flag = 0; char chi;
		while (1) {
			cin >> judgement;
			while (i <= 5) {
				jud = students[i].check(&judgement);
				if (jud == 1) {
					students[i].output();
					i++; flag = 1;
				}
				else if (jud == 0) {
					i++;
				}
				else if (jud == -1) {
					if (flag == 1) {
						break;
					}
					else if (flag == 0) {
						cout << "there is no eligible student ";
						break;
					}
				}
			}
			i = 0;
			cout << "continue?"; cout << endl;
			char temp[5] = { '\0' };
			while (1) {
				cin >> chi;
				if (isalpha(chi)) {
					break;
				}
			}
			temp[0] = chi; cin.get(temp + 1, 3);
			if (temp[0] == 'y'&&temp[1] == 'e'&&temp[2] == 's') {}
			else if (temp[0] == 'n'&&temp[1] == 'o') { break; }
			else { cout << "please enter the right option,now is equal to enter 'no'."; break; }
		}
	}
	else if (*option == 4) {
		grade1.reorder();
	}
	else if (*option == 5) {
		int i = 0;
		while (i <= 5) {
			students[i].output();
			i++;
		}
	}
}
inline void menu::start() {
	int option = 0;
	while (option != 6) {
		cout << "1.input" << endl << "2.delete" << endl << "3.select" << endl
			<< "4.order" << endl << "5.output" << endl << "6.quit" << endl << "please input your option" << endl;
		cin >> option;
		selecter = &option;
		grade1.select();
	}
}
int main()
{
	menu menu1;
	menu1.start();
	return 0;
}