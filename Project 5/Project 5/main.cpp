#include "lecturer.h"
#include "NoCollisionDetection.h"
#include "Probing.h"
#include "SeparateChaining.h"
#include "RedditElement.h"
#include "Operations.h"
#include <iostream>
#include <vector>

using namespace std;

unsigned int hornerHash(const string &key, int tableSize);

string get_reddit_element_key(const RedditElement &reddit_element);


void work_separate_chaining_hts(vector<RedditElement> &data);

void work_linear_probing_hts(vector<RedditElement> &data);


// Declare Separate-Chaining Hash-Tables.
SeparateChaining<RedditElement> SC_HashTable(10, get_reddit_element_key);
SeparateChaining<RedditElement> SC_HT_SZ_002(2, get_reddit_element_key);
SeparateChaining<RedditElement> SC_HT_SZ_127(127, get_reddit_element_key);
SeparateChaining<RedditElement> SC_HT_SZ_233(233, get_reddit_element_key);
SeparateChaining<RedditElement> SC_HT_SZ_353(353, get_reddit_element_key);
SeparateChaining<RedditElement> SC_HT_SZ_419(419, get_reddit_element_key);

// Declare Linear-Probing Hash-Tables.
Probing<RedditElement> LP_HashTable(10, get_reddit_element_key);
Probing<RedditElement> LP_HT_SZ_002(2, get_reddit_element_key);
Probing<RedditElement> LP_HT_SZ_127(127, get_reddit_element_key);
Probing<RedditElement> LP_HT_SZ_233(233, get_reddit_element_key);
Probing<RedditElement> LP_HT_SZ_353(353, get_reddit_element_key);
Probing<RedditElement> LP_HT_SZ_419(419, get_reddit_element_key);


int main() {

    // Define a container for data.
    vector<RedditElement> reddit_element_data;

    // Populate the vector, having re-sized the data file beforehand to be composed of just 1000 entries.
    generate_reddit_data(false, reddit_element_data);

    // Define list of prime numbers to be used as Hash-Table initial sizes.
    vector<int> prime_numbers = {2, 127, 233, 353, 419};


    // Perform insertions for the Separate-Chaining Hash-Tables.
    work_separate_chaining_hts(reddit_element_data);

    // Perform insertions for the Linear-Probing Hash-Tables.
    work_linear_probing_hts(reddit_element_data);



    return 0;

}


/**
 *
 * @param reddit_element
 * @return
 */
string get_reddit_element_key(const RedditElement &reddit_element) {

    return reddit_element.get_id();

}



/**
 *
 * @param data
 */
void work_separate_chaining_hts(vector<RedditElement> &data) {

    /* Perform insertions. */
    // Table Size: 10
    populate_sc_hash_table(data, SC_HashTable);

    // Table Size: 2
    populate_sc_hash_table(data, SC_HT_SZ_002);

    // Table Size: 127
    populate_sc_hash_table(data, SC_HT_SZ_127);

    // Table Size: 233
    populate_sc_hash_table(data, SC_HT_SZ_233);

    // Table Size: 353
    populate_sc_hash_table(data, SC_HT_SZ_353);

    // Table Size: 419
    populate_sc_hash_table(data, SC_HT_SZ_419);

}



/**
 *
 * @param data
 */
void work_linear_probing_hts(vector<RedditElement> &data) {

    /* Perform insertions. */
    // Table Size: 10
    populate_lp_hash_table(data, LP_HashTable);

    // Table Size: 2
    populate_lp_hash_table(data, LP_HT_SZ_002);

    // Table Size: 127
    populate_lp_hash_table(data, LP_HT_SZ_127);

    // Table Size: 233
    populate_lp_hash_table(data, LP_HT_SZ_233);

    // Table Size: 353
    populate_lp_hash_table(data, LP_HT_SZ_353);

    // Table Size: 419
    populate_lp_hash_table(data, LP_HT_SZ_419);

}




void demo() {

//    vector<Lecturer> lecturers;
//    readLecturers(lecturers);

//    for (Lecturer &l : lecturers) {
//        cout << l.getName() << ": ";
//        cout << hornerHash(l.getName(), 13) << endl;
//    }


//    SeparateChaining<int> jenny(7, guessWho);
//    vector<int> numbers = {8, 6, 7, 5, 3, 0, 9};
//
//    for (int number : numbers) {
//        jenny.insert(number);
//        cout << hornerHash(guessWho(number), 7) << endl;
//        jenny.printTable(cout);
//        cout << endl;
//    }


//    SeparateChaining<string> string_separate_chain(7, whoAmI);
//    vector<string> names1 = {"Homer", "Marge", "Bart", "Lisa", "Maggie", "Santa's Little Helper"};
//
//    for (string name : names1) {
//        string_separate_chain.insert(name);
//        cout << hornerHash(whoAmI(name), 7) << endl;
//        string_separate_chain.printTable(cout);
//        cout << endl;
//    }


//    Probing<string> simpsons(7, whoAmI);
//    vector<string> names = {"Homer", "Marge", "Bart", "Lisa", "Maggie", "Santa's Little Helper"};
//
//    for (string name : names ) {
//        simpsons.insert(name);
//        cout << hornerHash(name, simpsons.getSize()) << endl;
//        simpsons.printTable(cout);
//        cout << endl;
//    }

}

unsigned int hornerHash(const string &key, int tableSize) {
    unsigned int hashVal = 0;
    for (char ch : key) {
        hashVal = 37*hashVal + ch;
    }
    cout << hashVal << ", ";
    return hashVal % tableSize;
}
