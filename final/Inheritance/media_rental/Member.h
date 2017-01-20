//
// Created by prenga on 11/15/16.
//

#pragma once

#include <iostream>
#include "Item.h"
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

class Member
{
private:
    Member() {}
    string name = "";
    static int counter;
    int id = 0;
    int rented1 = 0;
    int rented2 = 0;
public:
    Member(string name, int id, bool is_premium, int rented1, int rented2=0) : name(name),
                                                                               id(id),
                                                                               is_premium(is_premium),
                                                                               rented1(rented1),
                                                                               rented2(rented2)
    {
        if (id > counter) {
            counter = id+1;
        }
    }

    Member(string name, bool is_premium) : name(name),
                                           is_premium(is_premium),
                                           id(counter)
    {
        counter++;
    }

    bool is_premium = false;

    string get_name() const {
        return name;
    }

    int member_id() const {
        return id;
    }

    void checkout(Item* item) {
        if (can_rent()) {
            if (item->checkout(id)) {
                renting(item->get_product_number(), true);
                cout << *this << " has successfully rented " << *item << '.' << endl;
            }
        } else {
            cout << *this << " is already renting maximum number of items.";
            if (!is_premium) {
                cout << " Suggest upgrading to premium.";
            }
            cout << endl;
        }
    };

    bool can_rent() const {
        return (!rented1 || (is_premium && !rented2));
    }

    void renting(int item_number, bool b = false) {
        if (b) {
            if (!rented1) { //register rental
                rented1 = item_number;
            } else {
                rented2 = item_number;
            }
        } else { //rental has been returned
            if (rented1 == item_number) {
                rented1 = 0;
            } else {
                rented2 = 0;
            }
        }
    };

    bool is_renting() const {
        return (rented1 || rented2);
    }

    void upgrade() {
        is_premium = true;
        cout << *this << " has been upgraded." << endl;
    }

    friend ostream& operator << (ostream& out, const Member& m) {
         out << m.name << '(' << m.id;
         if (m.is_premium) out << 'P';
         out << ')';
         return out;
     };
};

int Member::counter = 100;
