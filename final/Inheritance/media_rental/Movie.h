//
// Created by prenga on 11/15/16.
//

#pragma once

#include "Item.h"

class Movie : public Item
{
    string primary_actor = "";
    int running_time = 0;
public:
    Movie(string title, string actor, int time, int id) : Item(title, "Movie", id),
                                                          primary_actor(actor),
                                                          running_time(time) {}

    Movie(string title, string actor, int time): Item(title, "Movie"),
                                                 primary_actor(actor),
                                                 running_time(time) {}

    string report() const override {
        return title + ',' + primary_actor + ',' + to_string(running_time) + ',' + to_string(product_number);
    };
};