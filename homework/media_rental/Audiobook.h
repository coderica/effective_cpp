//
// Created by prenga on 11/21/16.
//

#pragma once

#include "Item.h"

class Audiobook : public Item
{
    string author = "";
    int number_of_cds = 0;
public:
    Audiobook(string title, string author, int cds, int id) : Item(title, "Audio Book", id),
                                                              number_of_cds(cds),
                                                              author(author)
    {
        max_days = 30;
    }

    Audiobook(string title, string author, int cds) : Item(title, "Audio Book"),
                                                      number_of_cds(cds),
                                                      author(author)
    {
        max_days = 30;
    }

    string report() const override {
        return title + ',' + author + ',' + to_string(number_of_cds) + ',' + to_string(product_number);
    };
};
