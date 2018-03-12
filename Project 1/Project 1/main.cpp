/*
 * Alexander Swanson
 * January 30, 2018
 */


// Import necessary resources.
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>


/**
 *
 * @return 0
 */
int main() {


    // Define the input stream object.
    std::ifstream file_input("reddit_data.csv");


    // Define a String to contain an entire line of input.
    std::string file_line;

    // Define a vector to hold every element of a line of the data file.
    std::vector<std::string> container;

    // Define a String to temporarily hold each element from a single line of the data file.
    std::string stream_cell;


    // Loop continuously so long as the stream has not encountered the end of the file.
    while ( (file_input) && (file_input.peek() != EOF) ) {

        /*
         * We must read in every element for all entries in 'reddit_data.csv'.
         * The columns are organized as follows:
         *      index,id,parent_id,submission_id,subreddit_name_prefixed,ups,downs,score,controversiality,category,sentiment_score,sentiment_magnitude,created,date_created,time_created
         */


        // Fetch a line of the data file.
        std::getline(file_input, file_line);

        // Define the String stream object.
        std::stringstream line_stream(file_line);


        // Collect every element individually from a line of input and store it in the vector 'container'.
        while ( std::getline(line_stream, stream_cell, ',') ) {

            container.push_back(stream_cell);

        }


        // Output the data.
        for (int i = 0; i < container.size(); i++) {

            // Convert to respective type and output doubles with specified precision.
            if (i > 9 && i < 12) {

                // Define an alias to size_t.
                std::string::size_type sz;

                // Define a converted double.
                double str_double = std::stod(container[i], &sz);

                // Perform output.
                std::cout << std::left << std::setw(25);
                std::cout << std::setprecision(10) << str_double;


            } else {

                // Perform regular output.
                std::cout << std::left << std::setw(25);
                std::cout << container[i];

            }

        }
        // Format output.
        std::cout << std::endl;


        // Clear the container vector for a new iteration.
        container.clear();

        // Clear the stream.
        file_input.clear();

    }

    // Output completion status.
    std::cout << std::endl << "Completed display of data." << std::endl;


    return 0;

}