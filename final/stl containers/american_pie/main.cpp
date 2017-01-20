#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

string testSolution(string output) {
    string answer = "theandidayathatbewastoinbutwillthislevydiebyeweresinginmusicyouonsomywithwhiskeywethemryepieoldmissgoodfordrydrovedrinkindiedchevyboysamericanmewhiletheresangofnojesterjackifhowdodancecuzcanallyouryearswhenusedtriedtimethosetheytakestartedsawrememberreadplayersoneoffnownotnewsmarchingmanmakelovelongknowkingitidhishimhighhehappygotfromdowncriedcouldchancebookbluesasyoureyieldwritewouldntwordwidowedwhowherewhatwevewentwellwatchedvoiceverdictupturnedtunetrucktraintouchedthreethornytheydthatstentellsteenageteachsweltersweetsummerstreetsstorestonestolestillstickstepstartstagespokenspellspacesoulsonsomethingsomesmiledsmileslowskeltersidelinesshoesshiversheltershesergeantsscreamedsavesatanssatansatsaidsacrificialsacredrollingrollrockriterhythmreturnedrefusedrecallrealragequickqueenquartetpracticedpoetsplayedplayplacepinkpickupperfumepeoplepassparkpaperownoutouronlynimblenightnevermostmossmortalmoremilesmetmenmaybemarxmadeluckloverslostlookinglonelylightleninleftlaughinglastlandedknewkickedjustjamesisintoinsideholyherhelterhellheardhavehandshalftimehadgymgrowsgrassgodgirlghostgenerationfriendfoulforwardflewflashflamesfistsfirefieldfeelfebruaryfatherfatfastfalloutfallinfaitheveryeightdreameddoorstepdirgesdigdiddevilsdeliverdelightdeepdeandarkdancincrowncourtroomcouldntcomecoatcoastclimbedclenchedchurchchildrencaughtcastcarnationcantcandlecamebuckbroncinbrokenbridebreadbothborrowedbornbirdsbiblebellsbelievebeforebeenbandbadawayataskedangelagoagainadmireadjournedaboveabout";//acquired through http://www.writewords.org.uk/word_count.asp

    if (output == answer) cout << "Test passed: actual output is equal to expected output" << endl << endl;
}

int main() {
    map<int, set<string>> count_sets;
    map<string, int> word_counts;

    //RETRIEVE, CLEAN & STORE WORDS
    ifstream file("ampie.txt");
    if (file.fail()) cout << "Unable to open file" << endl;

    string dirty;
    while ( file >> dirty ) //read in a word till end of file
    {
        string word;
        for ( int i = 0; i < dirty.length(); i++ ) {
            if ( !ispunct(dirty[i]) ) { //if char isn't punctuation
                word += tolower(dirty[i]); //store char in word
            }
        }

        int count = word_counts[word];
        set group = count_sets[count];

        if (count) { //if word has already appeared
            group.erase(word); //remove from current count set

            if (group.empty()) {
                count_sets.erase(count); //remove pair if set is empty
            }
        }

        count += 1; //update word count
        group.insert(word); //add word to group with updated count
    }

    file.close(); //close file

    string output; //for testing
    string display; //for display

    for (auto c = count_sets.rbegin(); c != count_sets.rend(); c++) { //for every count set
            display += to_string(c->first) + ": "; //display count
            for (auto w = c->second.rbegin(); w != c->second.rend(); w++) { //for every word in the set
                output += *w;
                display += *w + ' '; //display the word
            }
            display += '\n';
    }

    testSolution(output); //test against external solution
    cout << display; //display decorated output

    return 0;
}