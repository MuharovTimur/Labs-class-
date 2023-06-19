#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Money
{
 private:
    long rubles;
    int kopecks;
 public:
    Money();
    Money(long, int);
    Money(const Money&);
    ~Money();
    
    void setrub(long);
    void setkop(int);
    long getrub();
    int getkop();
    
    Money &operator =(const Money&);
    Money operator/(const Money&);
    Money operator*(const Money&);
    
    friend istream &operator >>(istream&in, Money&m);
    friend ostream &operator <<(ostream&out, const Money&m);
    friend fstream& operator>>(fstream& fin, Money& p);
	friend fstream& operator <<(fstream& fout, const Money& p);
};

int make_file(const char* f_name)
{
    fstream stream(f_name, ios::out | ios::trunc);
    if (!stream)
        return -1;
    int n;

    Money p;
    cout << "Kolvo ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        stream << p << "\n";
    }

    stream.close();

    return n;
}
int print_file(const char* f_name)
{
    fstream stream(f_name, ios::in);
    if (!stream)
        return -1;

    Money p;
    int i = 0;

    while (stream >> p)
    {
        cout << p << "\n";
        i++;
    }

    stream.close();
    return i;
}
int del_file(const char* f_name, int k)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream)
        return -1;

    int i = 0;
    Money p;
    while (stream >> p)
    {
        if (stream.eof())
            break;
        i++;

        if (i != k)
            temp << p;
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return i;
}
int add_file(const char* f_name, int k, Money pp)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream)
        return -1;

    Money p;
    int i = 0, l = 0;
    while (stream >> p)
    {
        if (stream.eof())break;
        i++;

        if (i == k)
        {
            temp << pp;
            l++;
        }
        temp << p;
    }
    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return l;
}
int add_end(const char* f_name, Money pp)
{
    fstream stream(f_name, ios::app);
    if (!stream)
        return -1;

    stream << pp;
    return 1;
}
int change_file(const char* f_name, int k, Money pp)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream)
        return -1;

    Money p;
    int i = 0, l = 0;
    char x;

    while (stream >> p)
    {
        if (stream.eof())
            break;
        i++;
        if (i == k)
        {
            cout << p << " - is changing... Continue[y/n]?\n";
            cin >> x;

            if (x == 'n' || x == 'N')
                break;

            temp << pp;
            l++;
        }
        else temp << p;
    }
    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return l;
}