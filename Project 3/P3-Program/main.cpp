#include <iostream>
#include <algorithm>
#include <random>

#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include "RedditElement.h"
#include "RedditDataGeneration.h"



/**
 *
 * @param container
 * @param generate_ordered
 * @param generate_random
 * @param generate_repeated
 */
void generate_number_lists(vector<RedditElement> &container,
                           bool generate_ordered,
                           bool generate_random,
                           bool generate_repeated);



int main() {


    /* Define the data vector. */
    // Create object.
    vector<RedditElement> data;

    // Generate vector data.
    generate_reddit_data(false, data);

    // Define the "dummy objects."
    RedditElement dummy_one;
    RedditElement dummy_two;
    RedditElement dummy_three;

    // Append the "dummy objects" to the data vector.
    data.insert(data.end(), {dummy_one, dummy_two, dummy_three});


//    data[0].info();

    generate_number_lists(data, false, false, true);

    return 0;

}




void generate_number_lists(vector<RedditElement> &container,
                           bool generate_ordered,
                           bool generate_random,
                           bool generate_repeated) {


    /* Create the vector of integers to be used for ordered, random, and repeated integer lists. */

    // Declare a vector of integers.
    vector<int> integers;
    integers.reserve(container.size());

    // Define the ordered integer content of the "integers" vector.
    for (int i = 0; i < container.size(); i++) {

        integers.push_back(i);

    }


    // Create file IO object.
    ofstream file;

    /* Generate integer list from 0 to N. */
    if (generate_ordered) {

        // Open the respective file.
        file.open("integers_ordered.csv");

        // Generate the ordered list of integers.
        for (int i : integers) { file << i << ","; }

        // Close the file.
        file.close();

        // Clear the stream.
        file.clear();

    }


    /* Generate integer list from 0 to N, randomly ordered. */
    if (generate_random) {

        // Open the respective file.
        file.open("integers_random.csv");

        // Define an alias to "integers" in order to obtain a randomly shuffled version.
        vector<int> T = integers;

        // Define a "random" element engine.
        auto rng = default_random_engine {};

        // Randomly shuffle the given vector.
        shuffle(begin(T), end(T), rng);

        // Generate the randomly ordered list of integers.
        for (int i : T) { file << i << ","; }

        // Close the file.
        file.close();

        // Clear the stream.
        file.clear();

    }


    if (generate_repeated) {

        // Open the respective file.
        file.open("integers_random.csv");

        // Define an alias to "integers" in order to generate a version with repeating elemnts.
        vector<int> T;

        for (int i : integers) {

            // Define container with 5 instances of the integer "i".
            vector<int> i_T(5, i);

            for (int j : i_T) cout << j << endl;

//            // Append the repeated integers to the aggregate collection, "T".
//            T.insert(T.begin(), i_T, i_T.size());




        }

    }

}