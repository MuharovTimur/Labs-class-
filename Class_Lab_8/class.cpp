#include <iostream>
#include <string>
#include "class.h"
using namespace std;

Dialog::Dialog(void) : List()
{
	EndState = 0;
}

Dialog::~Dialog(void){}

void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-?/qam";
	string s;
	string param;
	char code;
	cout << "Enter command: ";
	cin >> s; code = s[0];
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmName; break;
		case 'q': event.command = cmQuit; break;
		case '/': event.command = cmGet; break;
		}

		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else 
		event.what = evNothing;
}
int Dialog::Execute()
{
	TEvent event;
	do 
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());

	return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0)
		return 0;
	else 
		return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

void Dialog::EndExec()
{
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		default:
			List::HandleEvent(event);

		case cmMake:
			cout << "Enter size of group: " << endl;
			cin >> size;
			beg = new Object * [size];
			cur = 0;
			ClearEvent(event);
			break;

		case cmAdd:
			Add();
			ClearEvent(event);
			break;

		case cmDel:Del();
			ClearEvent(event);
			break;

		case cmShow:Show();
			ClearEvent(event);
			break;
			
		case cmName:Name();
			ClearEvent(event);
			break;

		case cmQuit:EndExec();
			ClearEvent(event);
			break;
		};
	};
}





Object::Object()
{
    
}

Object::~Object()
{
    
}





Person::Person()
{
    name=" ";
    age=0;
}

Person::Person(string new_name, int new_age)
{
    name=new_name;
    age=new_age;
}

Person::Person(const Person &pers)
{
    name=pers.name;
    age=pers.age;
}

Person::~Person()
{
    
}

void Person::set_name(string NAME)
{
    name=NAME;
}

void Person::set_age(int AGE)
{
    age=AGE;
}

string Person::GetName()
{
    return name;
}

int Person::get_age()
{
    return age;
}

Person&Person::operator=(const Person&p)
{
    if(&p==this)
    return *this;
    name=p.name;
    age=p.age;
    return *this;
}

void Person::Show()
{
    cout << "Имя:" << name << endl;
    cout << "Возраст:" << age << endl;
}

void Person::Input()
{
    cout << "Имя:";
    cin >> name;
    cout << endl;
    cout << "Возраст:";
    cin >> age;
    cout << endl;
}





Emloyee::Emloyee():Person()
{
    salary=0;
    job=" ";
}

Emloyee::Emloyee(string new_name, int new_age,float new_salary,string new_job):Person(new_name, new_age)
{
    salary=new_salary;
    job=new_job;
}

Emloyee::Emloyee(const Emloyee &eml)
{
    name=eml.name;
    age=eml.age;
    salary=eml.salary;
    job=eml.job;
}

Emloyee::~Emloyee()
{
    
}

void Emloyee::set_salary(float SALARY)
{
    salary=SALARY;
}

void Emloyee::set_job(string JOB)
{
    job=JOB;
}

float Emloyee::get_salary()
{
    return salary;
}

string Emloyee::get_job()
{
    return job;
}

Emloyee&Emloyee::operator=(const Emloyee&e)
{
    if(&e==this)
    return *this;
    name=e.name;
    age=e.age;
    salary=e.salary;
    job=e.job;
    return *this;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "Name = " << GetName() << endl;
			break;
		}
	}
}

void Emloyee::Show()
{
    cout << "Имя:" << name << endl;
    cout << "Возраст:" << age << endl;
    cout << "Зарплата:" << salary << endl;
    cout << "Работа:" << job << endl;
}

void Emloyee::Input()
{
    cout << "Имя:";
    cin >> name;
    cout << endl;
    cout << "Возраст:";
    cin >> age;
    cout << endl;
    cout << "Зарплата:";
    cin >> salary;
    cout << endl;
    cout << "Должность:";
    cin >> job;
    cout << endl;
}





List::List(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

List::List()
{
	beg = new Object * [0];
	cur = 0;
	size = 0;
}

List::~List(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

void List::Add()
{
	Object* p;

	cout << "1.Person" << endl;
	cout << "2.Emloyee" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Person* a = new (Person);
		a->Input();
		p = a;

		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (y == 2)
		{
			Emloyee* b = new Emloyee;
			b->Input();
			p = b;

			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else 
			return;
}

void List::Show()
{
	if (cur == 0) 
		cout << "Empty" << endl;

	Object** p = beg;

	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

void List::Name()
{
	if (cur == 0) 
		return;

	string name = "";
	int a;
	cout << "Number: " << endl;
	cin >> a;
	Object** p = beg;
	p = p + a - 1;
	name = (*p)->GetName();

	cout << "Name: " << name << endl;
}

int List::operator ()()
{
	return cur;
}

void List::Del()
{
	if (cur == 0)
		return;
	cur--;
}

void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}
