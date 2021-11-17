#include <iostream>
#include <string>
using namespace std;

class Human 
{
public:
    Human(string name)
    {
        this->name = name;
    }

    void print_name() 
    {
        cout << "My name: " << name << endl;
    }

    virtual void print_info() const = 0;

    virtual ~Human() {};


protected:
    string name;
};

class Student : public Human 
{
public:
    Student(string name, string subject) : Human(name) 
    {
        this->subject = subject;
    }

    void print_info() const override
    {
        cout << "My subject: " << subject << endl;
    }

protected:
    string subject;
};

class Teacher : public Student
{
public:
    Teacher(string name, string profession, string subject) : Student(name,subject)
    {
        this->profession = profession;
    }

    void print_info() const override
    {
        cout << "My profession: " << profession << " my subject: " << subject << endl;
    }

private:
    string profession;
};


int main()
{
    Teacher Yosef("Yosef", "Lecturer", "Math");
    Student Max("Max", "Ukrainian philology");

    Max.print_name();
    Max.print_info();

    Yosef.print_name();
    Yosef.print_info();
}