#include <iostream>
#include <vector>
using namespace std;

int program_picker()
{
    vector<string> choices;
    choices.push_back("1) Calculate Divisors for a number");
    choices.push_back("2) Determine whether a string is a palindrome");
    choices.push_back("3) Compare the length of different words");
    string spaces = "     ";

    int user_input;
    cout << "Don't forget, you may quit at any time by entering 0 here or holding down ctrl+c anytime." << endl << endl;
    cout << ">> What would you like to do? " << endl
         << spaces << choices[1] << endl
         << spaces << choices[2] << " OR" << endl
         << spaces << choices[3] << endl;

    do {
        cout << ">> Please type 1, 2, or 3 and press enter." << endl;
        cin >> user_input;
    } while(user_input < 0 && user_input > 3);

    return user_input;
}

void calculate_divisors(int user_input)
{
    for (int i = 1; i <= user_input; ++i) {
        if (user_input % i == 0) {
            cout << ' ' << i;
        }
    }
    cout << ". Pretty cool, huh?" << endl;
}

void divisors_program()
{
    int user_num;
    cout << ">> Type a number, any number!" << endl;
    cin >> user_num;
    cout << "The divisors for " << user_num << " are...";
    calculate_divisors(user_num);
}

int is_palindrome(char user_input[100])
{
    char new_arr[100];
    int length = (int)strlen(user_input);
    for (int i = 0; i < length; ++i) {
        if (('a' <= user_input[i] && 'z' >= user_input[i]) &&
            ('A' <= user_input[i] && 'Z' >= user_input[i]) &&
            ('0' <= user_input[i] && '9' >= user_input[i])) //only compare characters
        {
            new_arr[i] = (user_input[i]);
        }
    }

    int b = (int)strlen(new_arr) - 1;
    cout << new_arr << endl;
    for (int i = 0; i < strlen(new_arr); ++i)
    {
        if (char(tolower(new_arr[b])) != char(tolower(new_arr[i])))
        {
            return 0;
        }
        b--;
    }

    return 1;
}

int palindrome_program()
{
    char user_input[100];
    cout << ">> Type something and hit enter to check if it is the same written forwards and backwards!" << endl
         << ">> (Note that the max is 100 characters...)" << endl;
    cin.ignore();
    cin.getline(user_input, 100);

    if (is_palindrome(user_input)) {
        cout << "It is a palindrome!" << endl;
    } else {
        cout << "Sorry, '" << user_input << "' is not a palindrome." << endl;
    }
    return 0;
}

void word_comparison_program() //can i condense this?
{
    string user_word;
    vector<string> user_words;
    int i = 0;
    int longest = 0;
    int shortest = 0;

    cout << ">> Enter some words, then enter 'stop' when you are done:" << endl;
    while (user_word != "stop")
    {
        cin.ignore();
        cin >> user_word;
        if (user_word != "stop") {
            user_words.push_back(user_word); // Add to array
        }
        if (user_word.length() > user_words[longest].length()) { // Check if longest
            longest = i;
        }
        if (user_word.length() < user_words[shortest].length()) { // Check if shortest
            shortest = i;
        }
        i++;
    }
    cout << "The word '" << user_words[longest] << "' is the longest of the bunch with a total of "
         << user_words[longest].length() << " characters!" << endl;
}

// RUNNER
int main() {
    cout << endl << "Welcome to Erica's first assignment submission for CSCI E-53 Fall 2016. Enjoy!" << endl << endl;
    while (true) {
        int choice = program_picker();

        switch (choice) {
            case 0:
                return 0;

            case 1  : //DETERMINE DIVISORS
                divisors_program();
                break;

            case 2 : //DETERMINE PALINDROMES
                palindrome_program();
                break;

            default : //DETERMINE LONGEST WORD
                word_comparison_program();
                break;
        }
        cout << endl;
    }
}