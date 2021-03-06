#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

/* Game with 4 different types of creatures: humans, cyberdemons, balrogs, 
and elves. We will be simulating a match between them */
/* Rules */
/* 1 - Every creature inflicts damage that is a random number r, where 0 < 
r <= strength */
/* 2 - Balrogs, and Cyberdemons have a 5% chance of inflicting a demonic 
attack, which is an additional 50 damage points */
/* 3 - Elves have a 10% chance to inflict a magical attack that doubles 
the normal amount of damange */

class Creature
{
  protected:
    string description;
    int strength;        //How much maximum damage can the creature inflict
    int hitpoints;       //How much damage can it sustain before dying
    int damagesustained; /* records the damage sustained by the creature. 
Starts out with zero. Creature dies when damagesustained >= hitpoints*/

  public:
    string getDescription() { return description; }
    int getDamagesustained() { return damagesustained; }
    void setDamagesustained(int d) { damagesustained = d; }
    virtual int attack() = 0; /*Creature attacks. Each dervied class will 
implement the appropriate attack*/
};

/* To do - Code up Humans, Cyberdemons, Balrogs, and Elves classes all 
derived from Creature class with appropriate attack() methods */
// You can put all the code in this one file for this assignment.

class Humans : public Creature
{
public:
    Humans(string description1, int strength1, int hitpoints1, int d1) // this is a constructor for the Humans
    {
        srand(time(0));
        description = description1; // setting the description
        strength = strength1; // setting the strength
        hitpoints = hitpoints1; //setting the hitpoints
        damagesustained = d1; //setting the damage
    }

    virtual int attack()
    {
        int damage;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        damage = rand() % strength + 1; //damage is randomly generated by using the strength 
        return damage;// by randomly generated the damage, it is being set into damageustained. 
    }
};

class Cyberdemons : public Creature
{
public:
    Cyberdemons(string description1, int strength1, int hitpoints1, int d) // this is a constructor for the Cyberdemons
    {
        srand(time(0));
        description = description1;
        strength = strength1;
        hitpoints = hitpoints1;
        damagesustained = d;
    }
    virtual int attack()
    {
        int damage;
        std::this_thread::sleep_for (std::chrono::milliseconds(1000));
        damage = rand() % strength + 1; //randomly generated the damage. 
        if (rand() % 100 < 5) //generating the damage by 5% inflicting an attack.
        {
            damage = damage + 50; // if 5% inflicting a damage, the the damage will increase. 
        }
        return damage;
    }
};

class Balrogs : public Creature
{
  public:
    Balrogs(string description1, int strength1, int hitpoints1, int d) // this is a consturctor for Balrogs
    {
        srand(time(0));
        description = description1;
        strength = strength1;
        hitpoints = hitpoints1;
        damagesustained = d;
    }
    virtual int attack()
    {
        int damage;
        std::this_thread::sleep_for (std::chrono::milliseconds(1000));
        damage = rand() % strength + 1;
        if (rand() % 100 < 5) // same steps described for Cyberdemons
        {
            damage = damage + 50;
        }
        return damage;
    }
};
    class Elves : public Creature
    {
    public:
        Elves(string description1, int strength1, int hitpoints1, int d) // this is a constructor for Elves. 
        {
            srand(time(0));
            description = description1;
            strength = strength1;
            hitpoints = hitpoints1;
            damagesustained = d;
        }
        virtual int attack()
        {
            int damage;
            std::this_thread::sleep_for (std::chrono::milliseconds(1000));
            damage = rand() % strength + 1;
            if (rand() % 100 < 10) //generating the damage by 10% inflicting an attack. 
            {
                damage = damage * 2; // if 10% inflicting an attack, the damage will double. 
            }
            return damage;
        }
    };

    int main()
    {
        string match(Creature * c1, Creature * c2);
        Humans *hum = new Humans("human", 100, 100, 0); // Description,
        //strength, hitpoints
        Cyberdemons *cyb = new Cyberdemons("cyberdemon", 200, 100, 0);
        Balrogs *bal = new Balrogs("balrog", 50, 200, 0);
        Elves *elv = new Elves("elves", 200, 200, 0);
        cout << "And the winner between humans and cyberdemons is..." << match(hum, cyb) << endl;
        cout << "And the winner between balrogs and elves is..." << match(bal, elv) << endl;
        cout << "And the winner between cyberdemons and balrogs is..." << match(cyb, bal) << endl;
        return 0;
    }

string match(Creature* c1, Creature* c2) {
// Round 1
c1->setDamagesustained(0);
c2->setDamagesustained(0);
c1->setDamagesustained(c2->attack());
c2->setDamagesustained(c1->attack());
std::this_thread::sleep_for (std::chrono::milliseconds(1000));
// Round 2
c1->setDamagesustained(0);
c2->setDamagesustained(0);
c1->setDamagesustained(c2->attack());
c2->setDamagesustained(c1->attack());
std::this_thread::sleep_for (std::chrono::milliseconds(1000));
// Round 3
c1->setDamagesustained(0);
c2->setDamagesustained(0);
c1->setDamagesustained(c2->attack());
c2->setDamagesustained(c1->attack());
std::this_thread::sleep_for (std::chrono::milliseconds(1000));
// Winner!
if (c1->getDamagesustained() <= c2->getDamagesustained())
return c1->getDescription();
else
return c2->getDescription();
}
