#include <iostream>
using namespace std;

   class CounterType {
       public:
        void setCount(int num) {number = num;}
        void incCount();
        void decCount();
        int getCount() const {return number;}

        private:
         int number;  
   }; 

   void CounterType::incCount() {
       ++number;
   }

   void CounterType::decCount() {
        if (number <= 0) {
            number = 0;
            cout << "Invalid Operation" << endl; 
        }
        else {
            --number;
        }
   }
   int main() 
   {
       CounterType ctr;
       ctr.setCount(1);
       cout << ctr.getCount() << endl;
       ctr.incCount();
       cout << ctr.getCount() << endl;
       ctr.decCount();
       ctr.decCount();
       cout << ctr.getCount() << endl;
       ctr.decCount();
       cout << ctr.getCount() << endl;       
      return 0;
   }