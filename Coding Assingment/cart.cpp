#include <iostream>
#include "cart.h"
#include "item.h"
#include <vector>
using namespace std;
// This is class defintions from "cart.h" header file. 
void GroceryCart::insertItem(Item it) {
 cart.push_back(it); // inserting a item from calling item class   
}

void GroceryCart::deleteItem(Item it) {
    int i;
    for (i = 0; i < cart.size(); i++) {
        if (cart.at(i).getDescription() == it.getDescription()) { 
           cart.erase(cart.begin() + i); // deleting a item from the cart by calling data memeber from the Item class(getDescription()). 
        }    
    }
}

int GroceryCart::getItemCount() {
    count = cart.size();
    return count; // returning a item count of the specific cart object. 
}

bool GroceryCart::isCartEmpty() {
    
    return cart.size()==0;
}
// calculates total cost for the specific cart by calling public data memeber(getCost) from Item class
double GroceryCart::calcTotalCost() {
    double i;
    double sum = 0;
    for (i = 0; i < cart.size(); ++i) {
       sum = sum + cart.at(i).getCost(); 
    }
    return sum;
}
// compares if two carts are identical by calling public data memeber(getSize) from Item class 
 bool operator==( GroceryCart& cart3, GroceryCart& cart4){
    for (int i = 0; i < cart3.getSize(); ++i) {
        if (cart3.getItemAt(i).getDescription()!= cart4.getItemAt(i).getDescription()) {
             return false;   
        }

      else {
        return true;
      }  

    }
}

double GroceryCart::getSize() {
    return cart.size(); // returns size for the comparision for cart 3 and 4
}

Item GroceryCart::getItemAt(double i) {
    return cart.at(i); // returns description for the comparision of cart 3 and 4
}