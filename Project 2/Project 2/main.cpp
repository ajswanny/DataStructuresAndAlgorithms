//
// Created by Alexander Swanson on 2/8/18.
//



#include "RedditData.h"



/**
 *
 * @return
 */
int process(bool verbose, vector<RedditElement>& reddit_elements) {


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

    return 0;

}



/**
 * The function calculates the arithmetic mean of the sentiment score measures from the dataset.
 *
 * @param container
 * @return
 */
double measure_happiness(vector<RedditElement>& reddit_elements) {

    // Initialize a sum for the sentiment to be calculated.
    double sentiment_sum = 0;


    // Perform the summation.
    for (const auto &i : reddit_elements) {

        sentiment_sum += i.get_sentiment_score();

    }


    // Define a calculation of the arithmetic mean of the sentiment score.
    double sentiment_avg = sentiment_sum / reddit_elements.size();


    return sentiment_avg;

}



int main() {

    // Declare a vector to contain all RedditElement objects.
    vector<RedditElement> reddit_elements;


    // Create the necessary RedditElement objects.
    process(false, reddit_elements);


    // Observe an example of a RedditElement object.
    reddit_elements[100].info();


    // Calculate the average sentiment score from the dataset.
    cout << "\n\n Average sentiment: " << measure_happiness(reddit_elements) << endl;


    return 0;

}