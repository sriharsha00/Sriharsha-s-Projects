#ifndef CART_H
#define CART_H

/* This is a header file of cart class. This header file includes cart class definitions */

#include "item.h"
#include <vector>

class GroceryCart {
    public:
        void insertItem(Item); // inserts a item into this function by using push_back function. 
        void deleteItem(Item); // deletes a item into this function by using erase function. 
        int getItemCount();    // get cart count by using size function.      
        bool isCartEmpty();    // returns size = 0 if cart is empty.  
        double calcTotalCost(); // calculates the total cost of the cart object.  
        friend bool operator==(GroceryCart& cart3, GroceryCart& cart4); // comapres if cart 3 and 4 are equal by using bool statement. 
        double getSize(); // gets the size of the item for specific cart. 
        Item getItemAt(double); // getting the item from item class for the comparision of cart 3 and 4. 

    private:
        double count;
        double cost;
        std::vector<Item> cart;    
};

#endif