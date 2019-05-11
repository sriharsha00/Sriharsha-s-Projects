#ifndef ITEM_H
#define ITEM_H

/* This is a header file of item class. This is a declerations of the item class */

#include <string>
using namespace std;

class Item{
public:
    Item(string ItemDescription, double cost); // creating a constructor based on given description and cost. 
    Item(); // creating a default constructor if no agruments are given. 
    void setDescription (string ItemDescription); // sets the description of the item. 
    void setCost (double cost); // sets the cost of the item. 
    string getDescription(); // returns description by using an accessor. 
    double getCost(); // returns cost by using an accessor
    friend ostream &operator<<(ostream &output, Item& it4); // creating a overloading operator "<<" by using a friend. 
private:
    string description;
    double rate;
};

#endif