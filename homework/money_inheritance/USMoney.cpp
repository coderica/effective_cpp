//
// Created by prenga on 11/6/16.
//

#include "USMoney.h"

USMoney::USMoney(const CanadianMoney &m)
{
    set(m.total() / exchangeRate);
} // conversion constructor from Canadian Money.

void USMoney::display() const
{
    cout << "$" << total();
} // Override to display correct symbol

USMoney::operator CanadianMoney() const
{
    CanadianMoney m = total() * exchangeRate;
    return m;
}