#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

double distance(double latitude, double longitude) { //calculates the distance from CLT to other cities.
            const double con = (M_PI/180.0);
            double R = 3959;
            double phi = ((latitude * con) - (35.2060 * con));
            double lambda = ((longitude * con) + (80.8290 * con));
            double a = pow(sin(phi / 2), 2) + ((cos(latitude * con) * cos(35.2060 * con)) * pow(sin(lambda/2), 2));
            double c = 2 * atan2(sqrt(a), sqrt(1-a));
            double d = R * c;
            return d;
}

class Location {
    private: 
    double lat; //latitude
    double lon; //longitude
    double dist;
    string city1;
    string state1;
    
    public: 
    Location(string city, string state, double latitude, double longitude) : city1{city} , state1{state}, lat{latitude}, lon{longitude}, dist{distance(latitude, longitude)} {}
    //Created a constructor and initialized the variables into private variables. 
    double GetDistance() {return dist;} // returns distance
    string GetCity() {return city1;} //returns city
    string GetState() {return state1;} //returns state
};

bool ascend(Location l1, Location l2) { //Created a function to ascend the distance in ordered fashion
    return l1.GetDistance() < l2.GetDistance();
}

int main() {
    stringstream oss;
    ifstream ifs;
    ofstream ofs;
    double distance;
    double longitude;
    double latitude;
    string city;
    string state;
    string name, latitude1, longitude1;
    vector<Location> v1;

    ifs.open("cities.txt");
    if (!ifs.is_open()) {
        cout << "Error opening a file" << endl;
    }

        while(!ifs.eof()) {
          getline(ifs,name);  
          stringstream oss(name);  //stored the name from from file operator into stringstream
          getline(oss, city, ','); //read a string until delimeter and then stores into the variable. 
          getline(oss, state, ',');
          getline(oss, latitude1, ',');
          latitude = stod(latitude1); //converts the string into double. 
          getline(oss, longitude1, ',');
          longitude = stod(longitude1);
          Location l(city, state, latitude, longitude); //used a constructor to store city, state, latitude, longitude while in loop. 
          v1.push_back(l); //From using constructor, I pushed into the vector. 
        } 

        sort(v1.begin(), v1.end(), ascend); //This is a sort function of the vector
        ofs.open("dist_clt.txt");//opening a file, so I can write into the file. 
        for(int i = 0; i < v1.size(); i++) {
         ofs << v1.at(i).GetCity() << "," << v1.at(i).GetState() << " " << v1.at(i).GetDistance() << endl;
        } //writing a file using a file operator using a loop. 
    ifs.close();
    ofs.close();
    cout << "Successfully finished!" << endl;
}    