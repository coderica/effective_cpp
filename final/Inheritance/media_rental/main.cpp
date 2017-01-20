#include "Blockbuster.h"
using namespace std;

int main() {
    Blockbuster store;

    // report all currently available inventory include the name and type of item
    store.report("available");
    cout << endl << endl;

    // report all items checked out and the member that has it.
    store.report("unavailable");
    cout << endl << endl;

    // report all members that currently late, the item checked out, & what the current late fee is.
    store.report("late");
    cout << endl << endl;

    // report all users with nothing checked out
    store.report("not renting");
    cout << endl << endl;

    // add new item
    store.add_audiobook("Fables", "Aesop", 3);
    store.report("available");
    cout << endl << endl;

    // add new member
    store.add_member("Johnny Stecchino");
    store.add_member("Mister Plant", true);
    cout << endl;
    store.report("not renting");
    cout << endl << endl;

    // member checks out an item...
        // If member is not eligible to check out more items, display a message
        // If available, item is checked out by them and the transaction is time-stamped
        // If not available, member is put on wait list for the item (display a message)
    store.checkout("Erica Prenga", "Fables");

    store.upgrade_member("Erica Prenga");

    store.checkout("Erica Prenga", "Fables");
    store.checkout("Erica Prenga", "Fight Club");
    cout << endl << endl;

    store.checkout("Renee Marroquin", "The Witcher");
    cout << endl << endl;

    // member checks in an item
        // A message is displayed with the name of the member, the returned item name and any fees assessed.
        // If there is a wait list, item is automatically checked out to the next eligible member.
    store.checkin("Juliana Casey", "The Witcher");

    store.checkout("Mister Potatoe", "The Witcher");

    // Transactions File
    store.file_transactions(); //See note in function definition

    return 0;
}