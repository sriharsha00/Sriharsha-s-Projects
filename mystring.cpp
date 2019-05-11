#include <iostream>
#include "mystring.h"

MyString::MyString() {
  str = nullptr;  // creates a string array with size 0. 
}

MyString::~MyString() { // This is a descrutor of the string array. This is done by using delete keyword. 
    cout << "Destroyed Vector" << endl;
    delete[] str;
}

MyString::MyString(const char* s) { 
        len = 0;
        while (s[len] != '\0') { // In this step, the length is counted of the characters until it hit the null character. 
        len++;  
        }

        str = new char[len];
        for (int i = 0; i < len; i++) { // After the length is counted, the "s" array is filled with characters is now copied to string array. 
            str[i] = s[i];
        }


}
    

MyString::MyString(MyString& s) { // This is a copy constructor of copying the original object into new object. 
    len = s.len; // This is a shallow copy of copying orginial object, "s"'s length into new object. 
    str = new char[s.len];
    for (int i = 0; i < s.len; i++) { // This is a deep copy of copying the originial object's array into new object. 
        str[i] = s.str[i];
    }
}

ostream& operator<<(ostream& os, MyString& s) { // This is "<<" operator by using operator overloading. In this step, the object's array is outputting by using "<<."
    for (int i = 0; i < s.len; i++) {
        os << s.str[i];
    }
    return os;
}

MyString& MyString::operator=(MyString& s) { // This is a copy assignment operator of copying the original object's array into new object. 
    delete[] str;
    str = new char[s.len];
    str = s.str;
    len = s.len;
    for (int i = 0; i < s.len; i++) {
        str[i] = s.str[i];
    }
    return *this;
}

MyString& MyString::operator+(MyString& s) { // This is a addition operator of adding two objects' array. This is done by creating a whole new array of adding new lengths and run through the array using for loop. 
    char* c = new char[len + s.len];
    
    for (int i = 0, j = 0; i < len + s.len; i++) {
        if (i < len) {
            c[i] = str[i];
        }
        else {
            
            c[i] = s.str[j];
            j++;
        }
    }
    
    MyString *res = new MyString(c); // This is a copy constructor of the res object that is copying the c object. 
    return *res;
} 
