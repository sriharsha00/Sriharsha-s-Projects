#include <iostream>
#include <string>
using namespace std;

// This is an Item class definitions. 

#include "item.h"

Item::Item(string ItemDescription, double cost) {
    description = ItemDescription;
    rate = cost;
}

// Setting description as "Invalid item" and rate as "0.0" if no agruments given. 
Item::Item() { 
    description = "Invalid item";
    rate = 0.0;
}
// Setting description by calling private data member "string description".
void Item::setDescription(string ItemDescription) {
    description = ItemDescription;
}
// Setting cost by calling private data member "double rate"
void Item::setCost(double cost) {
    rate = cost;
}

string Item::getDescription() {
    return description; // returning description that already set by using void function. 
}

double Item::getCost() {
    return rate; // returning rate that already set by using void function
}

ostream &operator<<(ostream &output, Item& it4) {
    output<<it4.getDescription() << ":$" <<it4.getCost();
    return output; // using ostream to output item 4 without using accessors. 
} 