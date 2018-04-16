//
// Created by Admin on 4/15/18.
//

#ifndef PROJECT_5_OPERATIONS_H
#define PROJECT_5_OPERATIONS_H


#include <fstream>

#include "RedditElement.h"
#include "SeparateChaining.h"
#include "Probing.h"

/**
 *
 * Outputs a vector to a CSV file, delimited by a newline character.
 *
 * @param v
 * @param file_path
 */
void vector_to_csv(vector<int> &v, const string &file_path) {

    ofstream out_file(file_path);

    for (int i : v) {

        out_file << i << "\n";

    }

}



/**
 *
 * Generates the vector of 1202 RedditElements for reserved data.
 *
 * @param verbose
 * @param reddit_elements
 */
void generate_reddit_data(bool verbose, vector<RedditElement> &reddit_elements) {


    // Define the input stream object.
    ifstream file_input("reddit_data.csv");


    // Define a String to contain an entire line of input.
    string file_line;

    // Define a vector to hold every element of a line of the data file.
    vector<string> container;

    // Define a String to temporarily hold each element from a single line of the data file.
    string stream_cell;


    // Loop continuously so long as the stream has not encountered the end of the file.
    while ( (file_input) && (file_input.peek() != EOF) ) {

        // Fetch a line of the data file.
        getline(file_input, file_line);

        // Define the String stream object.
        stringstream line_stream(file_line);


        // Collect every element individually from a line of input and store it in the vector 'container'.
        while ( getline(line_stream, stream_cell, ',') ) {

            container.push_back(stream_cell);

        }


        // Remove the original dataset index value included in the CSV source file.
        container.erase(container.begin());


        // Output process input.
        if (verbose) {

            for (const auto &i : container) {

                cout << i << endl;

            }

            cout << "\n\n";

        }


        // Create the Reddit data object.
        RedditElement r(container);

        // Append the Reddit data object to 'reddit_elements'.
        reddit_elements.push_back(r);


        // Clear the container vector for a new iteration.
        container.clear();

        // Clear the stream.
        file_input.clear();

    }

}



/**
 *
 * @tparam Comparable
 * @param data
 * @param sc_table
 */
template <typename Comparable>
void populate_sc_hash_table(vector<Comparable> &data, SeparateChaining<Comparable> &sc_table) {

    for (Comparable E : data) {

        sc_table.insert(E);

    }

}



/**
 *
 * @tparam Comparable
 * @param data
 * @param lp_table
 */
template <typename Comparable>
void populate_lp_hash_table(vector<Comparable> &data, Probing<Comparable> &lp_table) {

    for (Comparable E : data) {

        lp_table.insert(E);

    }

}


#endif //PROJECT_5_OPERATIONS_H
