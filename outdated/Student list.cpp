#include <iostream>
#include <string>
using namespace std;
class Base
{
private:
	string m_name;
public:
	string getName() { return m_name; };
	virtual void setSelection(int i);
};
void Base::setSelection(int i){}
class Student
{
private:
	string Id;
	string banji;
	string name;
	float  score1;
	float  score2;
	float  score3;
	float  totalscore;
public:
	friend std::ostream & operator<<(std::ostream & os, const Student & s);
	friend std::istream & operator >> (std::istream & os, Student & s);
	string getName() { return name; }
	string getBanji() { return banji; }
	string getId() { return Id; }
	float  getScore() { return totalscore; }
};
std::istream & operator >> (std::istream & os, Student & s)
{
	cout << "Id ";     cin >> s.Id;
	cout << "class ";  cin >> s.banji;
	cout << "name ";   cin >> s.name;
	cout << "score1 "; cin >> s.score1;
	cout << "score2 "; cin >> s.score2;
	cout << "score3 "; cin >> s.score3;
	s.totalscore = s.score1 + s.score2 + s.score3;
	return os;
}
std::ostream & operator<<(std::ostream & os, const Student & s)
{
	cout << s.Id << "," << s.banji << "," << s.name << "," << s.score1 << "," << s.score2 << "," << s.score3 << "," << s.totalscore << endl;
	return os;
}
class Nianji :public Base
{
private:
	Student stu[5];
	string Id;
	int  count;
public:
	Nianji();
	void input();
	void output();
	void select();
	void delete1();
	void order();
	void setSelection(int i);
};
void Nianji::select()
{
	string str;
	while (1) {
		int flag = 1;
		cin >> str;
		for (int i = 0; i < count; i++)
			if (stu[i].getId() == str || stu[i].getBanji() == str)
			{
				cout << stu[i];
				flag = 0;
			}
		if (flag) cout << " there is no eligible student \n";
		cout << "continue?\n";
		cin >> str;
		if (str == "no")    break;
	}
}
void Nianji::order()
{
	for (int i = count - 1; i > 1; i--)
		for (int j = 1; j < i; j++)
		{
			if (stu[j].getBanji() > stu[j + 1].getBanji())
			{
				stu[count] = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = stu[count];
			}
			else if ((stu[j].getBanji() == stu[j + 1].getBanji()) && (stu[j].getScore() < stu[j + 1].getScore()))
			{
				stu[count] = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = stu[count];
			}
		}
	for (int i = 0; i < count; i++)
		cout << stu[i];
}
void Nianji::delete1()
{
	string str;
	while (1) {
		cin >> str;
		for (int i = 0; i < count; i++)
			if (stu[i].getName() == str || stu[i].getId() == str)
			{
				stu[i] = stu[count - 1];
				count--;
			}
		for (int i = 0; i <count; i++)
		{
			cout << stu[i];
		}
		cout << "continue?\n";
		cin >> str;
		if (str == "no")    break;
	}
}
Nianji::Nianji()
{
	count = 0;
	std::streamsize prec = std::cout.precision(1);
	//std::cout.precision(prec);
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}
void Nianji::output()
{
	for (int i = 0; i < count; i++)
	{
		cout << stu[i];
	}
}
void Nianji::input()
{
	string str;
	while (1)
	{
		cin >> stu[count++];
		cout << "continue?\n";
		cin >> str;
		if (str == "no")    break;
	}
}
void Nianji::setSelection(int i)
{
	if (i == 1) input();
	else if (i == 5) output();
	else if (i == 3) select();
	else if (i == 4) order();
	else if (i == 2) delete1();
}
class Menu
{
private:
	string m_menu;
public:
	void setMenu(string menu);
	void showMenu();
	int getSelection();
	Menu(string menu);
	int run(Base *p);
};
void Menu::setMenu(string menu)
{
	m_menu = menu;
}
void Menu::showMenu()
{
	cout << m_menu;
}
int Menu::getSelection()
{
	int selection;
	cin >> selection;
	return selection;
}
Menu::Menu(string menu)
{
	setMenu(menu);
}
int Menu::run(Base *p)
{
	while (1)
	{
		int i;
		showMenu();
		switch (i = getSelection())
		{
		case 1: p->setSelection(i); break;
		case 2: p->setSelection(i); break;
		case 3: p->setSelection(i); break;
		case 4: p->setSelection(i); break;
		case 5: p->setSelection(i); break;
		case 6: return 0;
		}
	}
}
int main()
{
	Menu menu("1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input your option\n");
	Nianji  nianji;
	menu.run(&nianji);
	return 0;
}