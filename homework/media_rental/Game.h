//
// Created by prenga on 11/15/16.
//

#pragma once

#include "Item.h"

class Game : public Item
{
    string platform = "";
public:
    Game(string title, string platform, int id) : Item(title, "Game", id),
                                                  platform(platform)
    {
        max_days = 14;
        overcharge = 1.0;
    }

    Game(string title, string platform) : Item(title, "Game"),
                                          platform(platform)
    {
        max_days = 14;
        overcharge = 1.0;
    }

    string report() const override {
        return title + ',' + platform + ',' + to_string(product_number);
    };
};