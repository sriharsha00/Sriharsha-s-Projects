#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Name1 {
    private: 
        string lname, finame;
        int old;
    public:
        Name1(string firstname, string lastname, int age) : finame{firstname} , lname{lastname}, old{age} {} 
        void Print() {
            cout << lname << ", " << finame << old << endl;
        }   
};

int main() {
string name;
stringstream oss;
ifstream ifs;
string lastname;
string firstname, fullname;
string line;
int age,i;
string age1;
vector <Name1> v1;


ifs.open("name.txt");
/*ifs.open("name.txt");
if (!ifs.is_open()) {
    cout << "Error opening a file" << endl;
}

else {
    cout << "file was read" << endl;
}*/

while(!ifs.eof()) {
    getline(ifs, name);
    stringstream oss(name);
    getline(oss, firstname, ',');
    getline(oss, lastname, ',');
    getline(oss, age1, ',');
    age = stoi(age1);
    Name1 n1 (firstname, lastname, age);
    v1.push_back(n1);
    //cout << firstname << endl;
    //cout << lastname << endl;
    //cout << age << endl;
    //cout << firstname << lastname << age << endl;
}
sort(v1.begin(), v1.end());
for (int i = 0; i < v1.size(); i++) {
    v1.at(i).Print();
}

//cout << oss.str();
/*line = oss.str();
cout << lastname << "," << firstname << "," << age << endl;
cout << oss.str() << endl;
cout << line << endl;*/

 /*//New set of notes
cout << "Enter your fullname and age" << endl;
getline(cin,name);
cout << "Enter your fullnmame and age" << endl;
cin >> firstname;
cin >> lastname;
cin >> age;
oss.clear();
oss.str(name);
oss >> firstname;
oss >> lastname;
oss >> age;
//oss << lastname << ":" << first name << ":" << age << endl;
cout << lastname << "," << firstname << "," << age << endl;
cout << oss.str() << endl;*/

/*if (ifs.is_open()) {
    while(ifs >> firstname >> lastname >> age) {
        oss << lastname << firstname << age << endl;
    }
}
cout << oss.str();
ifs.close();*/

}
