#include <iostream>
using namespace std;

class MyVector {
    private:
        int* arr;
        int cap;
        int size;
        int* arr1;

    public:
        MyVector() : arr(nullptr) {};
        void push(int ele);
        void erase(int index);  
        friend ostream& operator << (ostream& os, MyVector& vec);
        ~MyVector();
        void front(int i1); 
        void push_front(int n);    
};

int main() {
    MyVector vec;
    vec.push(1);
    vec.push(2);
    vec.push(10);
    vec.front(0);
    cout << vec;
    vec.erase(0); 
    cout << vec;
    vec.push_front(5);
    cout << vec;
}

void MyVector::front(int i) {
    cout << arr[i];
    cout << endl;
}

ostream& operator << (ostream& os, MyVector& vec) {
    for (int i = 0; i < vec.size; ++i) {
      os << vec.arr[i] << " ";  
    }
cout << endl;
}

MyVector::~MyVector() {
    cout << "Destroyed vector" << endl;
    delete[] arr;
}

void MyVector::push(int ele) {
    if (arr == nullptr) {
        cap = 2;
        arr = new int[cap];
        arr[0] = ele;
        size = 1;
    }

    else {
        if (size < cap) {
            arr[size] = ele;
            size++;
        }

        else {
            int* temp = arr;
            arr = new int[2 * cap];
            for (int i = 0; i < cap; ++i) {
                arr[i] = temp[i];
            }
        delete[] temp;
        cap = 2 * cap;
        arr[size] = ele;
        ++size;
        }
    }
}

// This is a erase method
void MyVector::erase(int index) {
    for (int i = 0; i < size; i++) {
        if (i != index + 2) {
            arr[i] = arr[i+1];
        }
    }
    size--;
}

void MyVector::push_front(int n) {
    int* temp1 = arr;
    int i;
    arr = new int[2 * cap];
    for(int i = 0; i < cap; i++) {
        arr[i] = temp1[i];
        arr[i + 1] = arr[i];
    }
    delete[] temp1;
     cap = 2 * cap;
     if(size < cap) {
        arr[size] = n;
        size++;
    }
}