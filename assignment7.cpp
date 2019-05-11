#include <iostream>
using namespace std;

int sumDigits(int n);

int main() {
    cout << sumDigits(1) << endl; // Should print 1
    cout << sumDigits(123) << endl; // Should print 6
    cout << sumDigits(57496) << endl; // Should print 31
    cout << sumDigits(777) << endl; // Should print 21
    return 0;

}

int sumDigits(int n) {
    int sum = 0;
    if(n == 0) { //base case if n is set equal to 0. 
      sum = 0;  
    }

    else {
      sum = n % 10 + sumDigits(n / 10); //case if n is not equal to 0. The number keeps dividing recursively until it is 0.   
        //After the number id divided, the number is taken a modulo and from there, the sum is taken into place.     
    }

    return sum;
}