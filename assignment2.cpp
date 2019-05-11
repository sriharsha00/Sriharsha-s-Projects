#include <iostream>
using namespace std;

class CounterType {
    public: 
        void setCount(int num) {num1 = num;}
        int getCount() {return num1;}
        void incCount();
        void decCount();

    private:
        int num1;    
};

void CounterType::incCount() {
    ++num1;
}

void CounterType::decCount() {
    if (num1 <= 0) {
        num1 = 0;
        cout << "Invalid Operation" << endl;
    }

    else {
        --num1;
    }
}

int main()
{
CounterType ctr;
ctr.setCount(1); // Set count to 1
cout << ctr.getCount() << endl; // Outputs count
ctr.incCount(); // Increments count
cout << ctr.getCount() << endl; // Verify increment worked correctly
ctr.decCount(); // Decrement count
ctr.decCount(); // Decrement count
cout << ctr.getCount() << endl; // Verify decrement worked correctly
ctr.decCount(); // Decrement count // Should print Invalid Operation
return 0;

}
