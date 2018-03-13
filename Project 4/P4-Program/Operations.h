//
// Created by Alexander Swanson on 3/12/18.
//

#ifndef P4_PROGRAM_OPERATIONS_H
#define P4_PROGRAM_OPERATIONS_H


#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "RedditElement.h"
#include "CustomSort.h"

using namespace std;


// Outputs a vector to a CSV file, delimited by a newline character.
void vector_to_csv(vector<int> &v, const string &file_path) {

    ofstream out_file(file_path);

    for (int i : v) {

        out_file << i << "\n";

    }

}


// Generates the vector of 1202 RedditElements for reserved data.
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


// Performs operations for "Bubble Sort".
void perform_bubble_sorts(const vector<RedditElement> &V) {

    // Define multiplier for indexing of 'V'.
    int multiplier = 1;

    // Define a matrix to contain READS and WRITES for all Bubble Sorts.
    int reads_writes[10][2];

    // Perform Bubble Sorts for 100, 200, ... 1000 elements within 'V'.
    for (int i = 1; i < 11; i++) {

        // Define multiplied truncation variable.
        int T = 100 * i;

        // Define alias to 'V' truncated by 'T'.
        vector<RedditElement> reddit_elements(V.begin(), V.begin() + T);

        cout << reddit_elements.size() << endl;

        // Perform Bubble Sort.
        vector<int> RW = bubbleSort(reddit_elements, false);


        cout << "\n" << endl;

    }


}



#endif //P4_PROGRAM_OPERATIONS_H
