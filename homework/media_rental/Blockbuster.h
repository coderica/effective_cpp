//
// Created by prenga on 11/15/16.
//

#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Movie.h"
#include "Game.h"
#include "Audiobook.h"
#include "Member.h"

class Blockbuster
{
public:
    vector<Item*> inventory;
    vector<Member> members;

    Blockbuster() {
        load_games("games.txt");
        load_movies("movies.txt");
        load_audiobooks("audiobooks.txt");
        load_members("members.txt");
    }

    ~Blockbuster() {
        for (Item* item : inventory) {
            delete item;
        }
    }

    bool to_bool(const string s) const {
        return s != "false";
    }

    void load_members(string filename) {
        ifstream inFile(filename);
        if (inFile.fail()) cout << "Unable to open file" << endl;

        string line;
        while (getline(inFile, line)) {
            istringstream ss(line);

            string name;
            getline(ss, name, ',');

            string id;
            getline(ss, id, ',');

            string boolean;
            getline(ss, boolean, ',');
            bool is_premium = to_bool(boolean);

            string item_one="";
            string timestamp_one="";
            string item_two = "";
            string timestamp_two = "";

            if (getline(ss, item_one, ',')) {
                getline(ss, timestamp_one, ',');

                struct tm tm;
                strptime(timestamp_one.c_str(), "%m-%d-%Y", &tm);
                strptime(timestamp_one.c_str(), "%m-%d-%Y", &tm);
                    //NOTE: Weird bug with strptime...
                    // It skews date the very first attempt of program,
                    // but otherwise works fine every time thereafter.
                    // This is my crappy (but effective) fix.

                try {
                    find_item(atoi(item_one.c_str()))->checkout(atoi(id.c_str()), mktime(&tm));
                } catch (string msg) {
                    cout << msg;
                }

                if (getline(ss, item_two, ',')) {
                    getline(ss, timestamp_two, ',');

                    strptime(timestamp_two.c_str(), "%m-%d-%Y", &tm);

                    try {
                        find_item(atoi(item_two.c_str()))->checkout(atoi(id.c_str()), mktime(&tm));
                    } catch (string msg) {
                        cout << msg;
                    }
                }
            }

            members.push_back(Member (name, atoi(id.c_str()), is_premium, atoi(item_one.c_str()), atoi(item_two.c_str())));
        }
    }

    void load_games(string filename) {
        ifstream inFile(filename);
        if (inFile.fail()) cout << "Unable to open file" << endl;

        string line;
        while (getline(inFile, line)) {
            istringstream ss(line);

            string title;
            getline(ss, title, ',');

            string platform;
            getline(ss, platform, ',');

            string product_number;
            getline(ss, product_number, ',');

            inventory.push_back(new Game(title, platform, atoi(product_number.c_str())));
        }
    }

    void load_movies(string filename) {
        ifstream inFile(filename);
        if (inFile.fail()) cout << "Unable to open file" << endl;

        string line;
        while (getline(inFile, line)) {
            istringstream ss(line);

            string title;
            getline(ss, title, ',');

            string actor;
            getline(ss, actor, ',');

            string running_time;
            getline(ss, running_time, ',');

            string product_number;
            getline(ss, product_number, ',');

            inventory.push_back(new Movie(title, actor, atoi(running_time.c_str()), atoi(product_number.c_str())));
        }
    }

    void load_audiobooks(string filename) {
        ifstream inFile(filename);
        if (inFile.fail()) cout << "Unable to open file" << endl;

        string line;
        while (getline(inFile, line)) {
            istringstream ss(line);

            string title;
            getline(ss, title, ',');

            string author;
            getline(ss, author, ',');

            string cds;
            getline(ss, cds, ',');

            string product_number;
            getline(ss, product_number, ',');

            inventory.push_back(new Audiobook(title, author, atoi(cds.c_str()), atoi(product_number.c_str())));
        }
    }

    void add_member(const string name, const bool is_premium=false) {
        members.push_back(Member(name, is_premium));
        cout << "Successfully added new ";
        if (is_premium) cout << "premium ";
        cout << "member " << name << '.' << endl;
    }

    void add_movie(string title, string actor, int running_time) {
        inventory.push_back(new Movie(title, actor, running_time));
    }

    void add_game(string title, string platform) {
        inventory.push_back(new Game(title, platform));
    }

    void add_audiobook(string title, string author, int cds) {
        inventory.push_back(new Audiobook(title, author, cds));
    }

    void checkin(string name, string title) {
        try {
            Member& m = find_member(name);
            Item* i = find_item(title);
            cout << m << ": " << *i << ", Late fee: $" << i->late_fee(m.is_premium) << endl;
            //calculate & display fees
            m.renting(i->get_product_number(), false); //remove item from member rentals
            cout << m << " has successfully returned " << *i << '.' << endl;
            if(i->checkin()) { //if waitlist isn't empty, rent_item to next person,
                int id = i->next_in_line();
                find_member(id).checkout(i);
            }
        } catch(string msg) {
            cout << msg;
        }

    }

    void checkout(string m, string i) {
        try {
            find_member(m).checkout(find_item(i));
        } catch (string msg) {
            cout << msg;
        }
    }

    void upgrade_member(string name) {
        try {
            find_member("Erica Prenga").upgrade();
        } catch (string msg) {
            cout << msg;
        }
    }

    Member& find_member(const string name) {
        for (Member &member : members) {
            if (member.get_name() == name) {
                return member;
            }
        }
        string err = "Member " + name + " does not exist.";
        throw err;
    }

    Member& find_member(const int id) {
        for (Member& member : members) {
            if (member.member_id() == id) {
                return member;
            }
        }
        string err = "Member " + to_string(id) + " does not exist.";
        throw err;
    }

    Item*  find_item(const string title) {
        for (Item* item : inventory) {
            if (item->get_title() == title) {
                return item;
            }
        }

        string err = "Item " + title + " does not exist.";
        throw err;
    }

    Item*  find_item(const int id) {
        for (Item*  item : inventory) {
            if (item->get_product_number() == id) {
                return item;
            }
        }
        string err = "Item " + to_string(id) + " does not exist.";
        throw err;
    }

    void report(const string type) {
        if(type == "available") {
            cout << "Available Items:" << endl;
            for (auto &item : inventory) {
                if (item->is_available()) {
                    cout << "   " << *item << endl;
                }
            }
        } else if (type == "unavailable") {
            cout << "Unvailable Items:" << endl;
            for (auto &item : inventory) {
                if (!item->is_available()) {
                    try {
                        cout << "   " << *item << ": " << find_member(item->get_member()) << endl;
                    } catch (string msg) {
                        cout << msg;
                    }
                }
            }
        } else if (type == "late") {
            cout << "Late Items:" << endl;
            for (auto &item : inventory) {
                if (item->is_late()) {
                    try {
                        cout << "   " << find_member(item->get_member())
                             << ": " << *item
                             << ", Late fee: $" << item->late_fee() << endl;
                    } catch (string msg) {
                        cout << msg;
                    }
                }
            }
        } else if (type == "not renting") {
            cout << "Members not renting:" << endl;
            for (auto &member : members) {
                if (!member.is_renting()) {
                    cout << "   " << member << endl;
                }
            }
        }
    }

    void file_transactions() const {
        // NOTE: this was going to be used in order to file the transactions.
        // However, there was quite a bit of confusion about the purpose of this report,
        // as well as how it should be implemented.
        // For these reasons I was at a loss as to how to handle the discrepancies.

        // If I had better understood this part of the assignment,
        // I would have used this function to simply write all recorded transactions
        // (assuming I would have kept that record throughout the program
        // in a container of some sort within this class)
        // into a transaction.txt file.
    }
};