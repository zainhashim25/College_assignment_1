//ZAIN HASHIM 21051870
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
class Student
{
    char name[30];
    int rollNo;
    int total;

public:
    void input(void)
    {
        cout << "Enter name,roll number,total marks out of 500: ";
        cin >> name >> rollNo >> total;
    }

    void output(void)
    {
        cout << "Student details:\n";
        cout << "Name:" << name << "\nRoll Number:" << rollNo << "\nTotal:" << total;
    }
};
float vol(int r, int h)
{
    return (3.14 * r * r * h);
}
float vol(int l, int b, int h)
{
    return (l * b * h);
}
float vol(int a)
{
    return ((4/3) * 3.14 * a * a * a);
}
class power
{
public:
    inline int square(int n)
    {
        return n * n;
    }
    inline int cube(int n)
    {
        return n * n * n;
    }
};
class Book
{
private:
    string name, Author;
    double price;

public:
    Book() {}
    Book(string n, string a, double p)
    {
        name = n;
        Author = a;
        price = p;
    }
    void inputDetails(string n, string a, double p)
    {
        name = n;
        Author = a;
        price = p;
    }
    string getName()
    {
        return name;
    }
    string getAuthor()
    {
        return Author;
    }
    double getPrice()
    {
        return price;
    }
    void printBook()
    {
        cout << "The book name is:" << name;
        cout << "\nThe book author is:" << Author;
        cout << "\nThe book price is:" << price << endl;
    }
    friend void display_4(int x);
};
void display_4(int x)
{
    string name, Author;
    double price;
    Book arr[x];
    for (int i = 0; i < x; i++)
    {
        cout << "Enter the book name " << i + 1 << endl;
        cin >> name;
        cout << "Enter the author \n";
        cin >> Author;
        cout << "Enter the book price\n";
        cin >> price;
        arr[i].inputDetails(name, Author, price);
    }
    for (int i = 0; i < x; i++)
    {
        cout << "\nDetails of book " << (i + 1) << "are:\n";
        arr[i].printBook();
    }
}
class Time
{
private:
    int hours;
    int minutes;
public:
    Time()
    { // default constructor
        hours = 0;
        minutes = 0;
    }
    Time(int h, int m = 0)
    { // parameterized constructor
        hours = h;
        minutes = m;
    }
    void display_5()
    {
        hours = hours + (minutes / 60);
        minutes = minutes % 60;
        cout << "TIME:  ";
        cout << hours << ":" << minutes << endl;
    }
};
class shape
{
public:
    virtual void area_6() = 0;
};
class circle : public shape
{
    float r;
public:
    void area_6()
    {
        cout << "\nEnter radius : ";
        cin >> r;
        cout << "\nArea of circle : " << (3.14 * r * r);
    }
};
class rectangle : public shape
{
    int l, b;
public:
    void area_6()
    {
        cout << "\nEnter length : ";
        cin >> l;
        cout << "\nEnter breadth : ";
        cin >> b;
        cout << "\nArea of rectangle : " << l * b;
    }
};
class triangle : public shape
{
    int h, b;
    float a;
public:
    void area_6()
    {
        cout << "\nEnter height : ";
        cin >> h;
        cout << "\nEnter breadth : ";
        cin >> b;
        a = 0.5 * h * b;
        cout << "\nArea of triangle : " << a;
    }
};
class Complex
{
private:
    int real, img;
public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    friend ostream &operator<<(ostream &out, const Complex &c);
    friend istream &operator>>(istream &in, Complex &c);
    Complex operator++()
    {
        ++real;
        return real;
    }
    Complex operator++(int)
    {
        real++;
        return real;
    }
};
ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.real;
    out << "+" << c.img << "i" << endl;
    return out;
}
istream &operator>>(istream &in, Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter imaginary Part ";
    in >> c.img;
    return in;
}
class Base
{
    int x;
public:
    virtual void fun() = 0;
    int getX() { return x; }
};
// This class inherits from Base and implements fun()
class Derived : public Base
{
    int y;
public:
    void fun() { cout << "fun() called"; }
};
void file_9()
{
    char Zain[30], ch;
    fstream fp;
    cout << "Enter the Name of File: ";
    gets(Zain);
    fp.open(Zain, fstream::in);
    if (!fp)
    {
        cout << "\nError Occurred!";
    }
    cout << "\nContent of " << Zain << ":-\n";
    while (fp >> noskipws >> ch)
        cout << ch;
    fp.close();
    cout << endl;
}
int main()
{
    int n, s;
    cout << "\n1.CLASS AND OBJECT\n2.FUNCTION OVERLOADING\n3.INLINE FUNCTION\n";
    cout << "4.FRIEND FUNCTION\n5.CONSTRUCTORS AND DESTRUCTORS\n6.INHERITANCE\n";
    cout << "7.OPERATOR OVERLOADING\n8.VIRTUAL FUNCTION\n9.FILE HANDLING\n";
    cout << "ENTER YOUR CHOICE: ";
    cin >> s;
    switch (s)
    {
        case 1: Student std;
                std.input();
                std.output();
            break;
        case 2: int r1, h1, l1, b1, h2, r2;
                cout << "Enter radius and height of a cylinder:";
                cin >> r1 >> h1;
                cout << "Enter length ,breadth and height of cuboid:";
                cin >> l1 >> b1 >> h2;
                cout << "Enter radius of sphere: ";
                cin >> r2;
                cout << "Volume of cylinder is " << vol(r1, h1);
                cout << "\nVolume of cuboid is " << vol(l1, b1, h2);
                cout << "\nVolume of sphere is " << vol(r2);
            break;
        case 3: int n, r3;
                power p;
                cout << "\nEnter a no: \n";
                cin >> n;
                r3 = p.square(n);
                cout << "\nSquare of " << n << " = " << r3 << endl;
                r3 = p.cube(n);
                cout << "\nCube of " << n << " = " << r3 << endl;
            break;
        case 4: int x;
                cout << "Enter the number of books\n";
                cin >> x;
                display_4(x);
            break;
        case 5: 
            {
                int hours, mins;
                cout << "Enter the value of hours :" << endl;
                cin >> hours;
                cout << "Enter the value of minutes :" << endl;
                cin >> mins;
                Time time1(hours, mins);
                time1.display_5();
            }
            break;
        case 6:
            {
                circle c;
                c.area_6();
                rectangle r6;
                r6.area_6();
                triangle t;
                t.area_6();
            }
            break;
        case 7: 
            {   
                Complex c1;
                cin >> c1;
                cout << "The complex object is ";
                cout << c1;
                cout << " Post Increamented value is:" << c1++;
                cout << " Pre Increamented value is:" << ++c1;
            }
            break;
        case 8: 
            {   
                Base *b;
                Derived d;
                b = &d;
                b->fun();
            }
            break;
        case 9: 
            {
                file_9();
            }
            break;
    }
    return 0;
}
