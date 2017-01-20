//PROBLEM 2: ********************************************************************************************
//  The problem: Implement a 5 letter word guessing game
//      The computer selects a secret word from a dictionary of 5 letter words.
//      The user will make a guess in the form of a real 5 letter word.
//      The computer responds with the number of letters that are correct between the two words.
//
//  Ground Rules:
//      Include a “test” mode that will display the secret word in the beginning to allow for easier testing.
//      After each turn, display all words guessed and the computer response
//      Submit code as a zip file
//
//  Rubric:
//      Implementation plan - 20 points
//      Program runs to spec – 50 points
//      Quality of code – 20 points
//PROBLEM 2: ********************************************************************************************

#include <iostream>
#include <vector>

using namespace std;

void test_mode(string word)
{
    char input;
    do {
        cout << "Would you like to enter test mode? Type 'y for YES and 'n' for NO." << endl;
        cin >> input;
    } while (input != 'y' && input != 'n');

    if (input == 'y')
    {
        cout << "Test: " << word << "\n\n";
    }
}

string get_guess(int count)
{
    if (count == 1)
    {
        cout << "Alright, let's get started! I've thought of a word... \n";
    }
    string input;
    cout << "Guess " << count << ": ";
    cin >> input; //next guess
    return input;
}

void explain_rules()
{
    char start;
    do {
        cout << "Here's the game:\n"
                "I have thought of a 5 letter word which you must guess.\n"
                "If you can guess the word in 10 attempts, you win. If not, I win!\n"
                "Each time, I'll share how many letters in the word you guessed are in the word I thought of.\n"
                "Got it? Type 'y for YES." << endl;
        cin >> start;
    } while (start != 'y'); //repeat rules until user confirms understanding
}

int random_number(int max)
{
    srand((unsigned int)time(0)); //seed the pseudo-random number generator
    int r = rand() % max; //modulo max to protect range
    return r;
}

string random_word()
{
    vector<string> dictionary = {"about", "above", "abuse", "actor", "acute", "admit", "adopt", "adult", "after", "again", "agent", "agree", "ahead", "alarm", "album", "alert", "alike", "alive", "allow", "alone", "along", "alter", "among", "anger", "Angle", "angry", "apart", "apple", "apply", "arena", "argue", "arise", "array", "aside", "asset", "audio", "audit", "avoid", "award", "aware", "badly", "baker", "bases", "basic", "basis", "beach", "began", "begin", "begun", "being", "below", "bench", "billy", "birth", "black", "blame", "blind", "block", "blood", "board", "boost", "booth", "bound", "brain", "brand", "bread", "break", "breed", "brief", "bring", "broad", "broke", "brown", "build", "built", "buyer", "cable", "calif", "carry", "catch", "cause", "chain", "chair", "chart", "chase", "cheap", "check", "chest", "chief", "child", "china", "chose", "civil", "claim", "class", "clean", "clear", "click", "clock", "close", "coach", "coast", "could", "count", "court", "cover", "craft", "crash", "cream", "crime", "cross", "crowd", "crown", "curve", "cycle", "daily", "dance", "dated", "dealt", "death", "debut", "delay", "depth", "doing", "doubt", "dozen", "draft", "drama", "drawn", "dream", "dress", "drill", "drink", "drive", "drove", "dying", "eager", "early", "earth", "eight", "elite", "empty", "enemy", "enjoy", "enter", "entry", "equal", "error", "event", "every", "exact", "exist", "extra", "faith", "false", "fault", "fiber", "field", "fifth", "fifty", "fight", "final", "first", "fixed", "flash", "fleet", "floor", "fluid", "focus", "force", "forth", "forty", "forum", "found", "frame", "frank", "fraud", "fresh", "front", "fruit", "fully", "funny", "giant", "given", "glass", "globe", "going", "grace", "grade", "grand", "grant", "grass", "great", "green", "gross", "group", "grown", "guard", "guess", "guest", "guide", "happy", "harry", "heart", "heavy", "hence", "henry", "horse", "hotel", "house", "human", "ideal", "image", "index", "inner", "input", "issue", "japan", "jimmy", "joint", "jones", "judge", "known", "label", "large", "laser", "later", "laugh", "layer", "learn", "lease", "least", "leave", "legal", "level", "lewis", "light", "limit", "links", "lives", "local", "logic", "loose", "lower", "lucky", "lunch", "lying", "magic", "major", "maker", "march", "maria", "match", "maybe", "mayor", "meant", "media", "metal", "might", "minor", "minus", "mixed", "model", "money", "month", "moral", "motor", "mount", "mouse", "mouth", "movie", "music", "needs", "never", "newly", "night", "noise", "north", "noted", "novel", "nurse", "occur", "ocean", "offer", "often", "order", "other", "ought", "paint", "panel", "paper", "party", "peace", "peter", "phase", "phone", "photo", "piece", "pilot", "pitch", "place", "plain", "plane", "plant", "plate", "point", "pound", "power", "press", "price", "pride", "prime", "print", "prior", "prize", "proof", "proud", "prove", "queen", "quick", "quiet", "quite", "radio", "raise", "range", "rapid", "ratio", "reach", "ready", "refer", "right", "rival", "river", "robin", "roger", "roman", "rough", "round", "route", "royal", "rural", "scale", "scene", "scope", "score", "sense", "serve", "seven", "shall", "shape", "share", "sharp", "sheet", "shelf", "shell", "shift", "shirt", "shock", "shoot", "short", "shown", "sight", "since", "sixth", "sixty", "sized", "skill", "sleep", "slide", "small", "smart", "smile", "smith", "smoke", "solid", "solve", "sorry", "sound", "south", "space", "spare", "speak", "speed", "spend", "spent", "split", "spoke", "sport", "staff", "stage", "stake", "stand", "start", "state", "steam", "steel", "stick", "still", "stock", "stone", "stood", "store", "storm", "story", "strip", "stuck", "study", "stuff", "style", "sugar", "suite", "super", "sweet", "table", "taken", "taste", "taxes", "teach", "teeth", "terry", "texas", "thank", "theft", "their", "theme", "there", "these", "thick", "thing", "think", "third", "those", "three", "threw", "throw", "tight", "times", "tired", "title", "today", "topic", "total", "touch", "tough", "tower", "track", "trade", "train", "treat", "trend", "trial", "tried", "tries", "truck", "truly", "trust", "truth", "twice", "under", "undue", "union", "unity", "until", "upper", "upset", "urban", "usage", "usual", "valid", "value", "video", "virus", "visit", "vital", "voice", "waste", "watch", "water", "wheel", "where", "which", "while", "white", "whole", "whose", "woman", "women", "world", "worry", "worse", "worst", "worth", "would", "wound", "write", "wrong", "wrote", "yield", "young", "youth"};
    int len = (int)dictionary.size(); //get # elements in dictionary
    int rand = random_number(len); //get random number within range 0-len
    string word = dictionary[rand]; //get random word from dictionary using rand as index
    return word;
}

string remove_char(string word, char letter)
{
    auto pos = find(word.begin(), word.end(), letter);
    if (pos != word.end())
    {
        word.erase(pos);

    }
    return word;
}

int correct_letters(string word, string guess)
{
    int correct = 0;
    string perm = guess;
    for (int i=0; i<=guess.length(); i++) //for each letter in GUESS
    {
        char letter = perm[i];
        if (word.find(letter) < 5)
        {
            correct += 1; //add to # of correct letters
            word = remove_char(word, letter); //remove letter from word to avoid double credit
        }
    }
    return correct;
}

void declare_winner(string guess, string word)
{
    if (guess == word) //user wins
    {
        cout << "You guessed it! The word is '" << word << "'!";
    }
    else //user loses
    {
        cout << "Darn, you couldn't guess it in time. I win! The word was '" << word << "'.";
    }
}

void play_game()
{
    string word = random_word(); //get random word from dictionary

    test_mode(word); //enter test mode

    vector<string> words;
    vector<int> counts;
    int attempts = 1;

    string guess = get_guess(attempts);

    while (guess != word && attempts < 10)  //if guess is wrong or user hasn't hit attempt limit
    {
        int count = correct_letters(word, guess); //get correct letters
        cout << "WRONG. You got " << count << " letters correct." << endl;

        words.push_back(guess);
        counts.push_back(count);
        for (int i=0; i < attempts-1; i++)
        {
            cout << words[i] << ' ' << counts[i] << endl; //print guesses so far
        }

        guess = get_guess(++attempts); //next guess attempt
    }

    declare_winner(guess, word);
}

int main()
{
    explain_rules();
    char input;
    do {
        play_game(); //runner
        cout << "\n\nWanna play again? Type 'y' for YES and 'n' for NO.\n";
        cin >> input;
    } while (input == 'y'); //game loop
}