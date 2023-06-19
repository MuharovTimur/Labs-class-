#pragma once
#include <iostream>
#include <string>
using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmName = 7;
const int cmMake = 6;
const int cmQuit = 101;

struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};





class Object
{
 public:
    Object();
    ~Object();
    virtual void Show()=0;
    virtual void Input()=0;
    virtual string GetName() = 0;
    virtual void HandleEvent(const TEvent& e) = 0;
};





class Person:public Object
{
 protected:
    string name;
    int age;
 public:
    Person();
    Person(string, int);
    Person(const Person&);
    virtual ~Person();
    
    void set_name(string);
    void set_age(int);
    string GetName();
    int get_age();
    
    Person &operator =(const Person&);
    
    virtual void HandleEvent(const TEvent& e);
    virtual void Show();
    virtual void Input();
};





class Emloyee:public Person
{
 protected:
    float salary;
    string job;
 public:
    Emloyee();
    Emloyee(string,int,float,string);
    Emloyee(const Emloyee&);
    ~Emloyee();
    
    void set_salary(float);
    void set_job(string);
    float get_salary();
    string get_job();
    
    Emloyee &operator =(const Emloyee&);
    
    void Show();
    void Input();
};





class List
{
public:
	List(int);
	List();
	~List(void);

	void Add();
	void Del();
	void Show();
	void Name();
	int operator()();
	virtual void HandleEvent(const TEvent& e);

protected:
	Object** beg;
	int size;
	int cur;
};






class Dialog :
	public List
{
public:
	Dialog(void);
	virtual ~Dialog(void);

	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();

protected:
	int EndState;
};
