#include <iostream>
#include <string>
using namespace std;
class Person {
private:
string name;
int age;
public:
Person() : name{"no name"}, age{-1} {}
Person(string name, int age) : name{name}, age{age} {}
string getName() const {return name;}
void setName(string name) {name = name;}
int getAge() const {return age;}
void setAge(int age) {age = age;}
string dailyAction() {return "sleep";}
virtual string whoamI() {return name + " " + to_string(age);}
};
// Student is a derived class
class Student : public Person { // Student inherits from Person base class
private:
int id;
public:
Student() : Person(), id(-1) {} // Call base class constructor first
Student(string name, int age, int id) : Person{name, age}, id{id} {}
int getId() const {return id;}
void setId(int id) {id = id;}
string dailyAction() {return "study and sleep";} //Overrides base 
virtual string whoamI() {return getName() + " " + to_string(getAge()) + " " + to_string(id);}
};
void identify1(Person p);
void identify2(Person *p);
int main()
{
Person neighbhor{"Alice", 30};
identify1(neighbhor);
Student compEstudent{"Bob", 19, 8001};
identify1(compEstudent);
identify2(&neighbhor);
identify2(&compEstudent);
Student* eeStudent = new Student{"Carol", 21, 8002};
cout << eeStudent << endl;
identify2(eeStudent);
identify2(eeStudent);
}
void identify1(Person p) // Dervied classes are sliced!
{
cout << p.whoamI() << endl;
}
void identify2(Person* p) // Polymorphism with dynamic binding of whoamI()
{
cout << p->whoamI() << endl;
}