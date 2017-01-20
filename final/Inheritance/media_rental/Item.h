//
// Created by prenga on 11/15/16.
//

#pragma once

#include <iostream>
#include <deque>

using namespace std;
using namespace chrono;

class Item {
private:
    Item() {};
protected:
    time_t timestamp = 0;
    string title = "";
    int max_days = 7;
    double overcharge = 0.5;
    string type = "Media";
    static int counter;
    const int product_number = 0;
    deque<int> waitlist;
    int member_id = 0;
public:
    Item(string title, string type, int product_number) : title(title),
                                                          type(type),
                                                          product_number(product_number)
    {
        if (product_number > counter) {
            counter = product_number+1;
        }
    };

    Item(string title, string type) : title(title),
                                      type(type),
                                      product_number(counter)
    {
        counter ++;
    };

    int get_member() const {
        return member_id;
    };

    int get_product_number() const {
        return product_number;
    };

    string get_title() const {
        return title;
    };

    bool is_available() const {
        return !bool(timestamp);
    };

    bool checkout(int id, time_t ts=0) {
        if (is_available()) {
            timestamp = ts ? ts : system_clock::to_time_t(system_clock::now());
            member_id = id;
            return true;
        }

        waitlist.push_back(id);
        cout << *this << " is unavailable. Member has been added to waitlist." << endl;
        return false;
    }; //if timestamp is null, rentable, else add to waitlist

    bool checkin() {
        timestamp = 0;
        member_id = 0;
        if (waitlist.size()) {
            return true;
        };
        return false;
    }; //if waitlist isn't empty, rent_item to next person, else timestamp == null

    int next_in_line() {
        int next = waitlist.front();
        waitlist.pop_front();
        return next;
    };

    bool is_late() const {
        return (time_rented() - max_days) > 0;
    };

    double late_fee(bool b=false) const {
        if (is_late()) {
            int days_late = time_rented() - max_days;
            if (b) days_late -= 1;
            double fee = days_late * overcharge; // consider money class
            return fee;
        }
        return 0;
    };

    int to_days(float seconds) const {
        return int(seconds / 86400); //86400 seconds in a day
    };

    int time_rented() const {
        time_t now = system_clock::to_time_t(system_clock::now());
        time_t t = timestamp ? timestamp : system_clock::to_time_t(system_clock::now());
        time_t elapsed_seconds = now - t;
        int elapsed_days = to_days(elapsed_seconds);
        return elapsed_days;
    };

    virtual string report() const = 0;

    friend ostream& operator << (ostream& out, const Item& item) {
        out << item.title << '(' << item.type << ')';
        return out;
    };
};

int Item::counter = 100;
