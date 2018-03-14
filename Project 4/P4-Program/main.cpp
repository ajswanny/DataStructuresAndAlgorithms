//
// Created by Alexander Swanson on 3/12/18.
//

#include <iostream>

#include "Operations.h"
#include "CustomSort.h"


int main() {


    // Define a container for data.
    vector<RedditElement> data;

    // Populate the vector, having re-sized the data beforehand to be composed of just 1000 entries.
    generate_reddit_data(false, data);


    // Perform operations for Bubble Sort.
//    vector<vector<int>> bubble_sort_rw_data = perform_bubble_sorts(data, true);

    // Archive read and write data for Bubble Sort.
//    archive_read_write_counts("bubble_sort_rw_data.csv", bubble_sort_rw_data);


    // Perform operations for Insertion Sort.
//    vector<vector<int>> insertion_sort_rw_data = perform_insertion_sorts(data, true);

    // Archive read and write data for Bubble Sort.
//    archive_read_write_counts("insertion_sort_rw_data.csv", insertion_sort_rw_data);


    // Perform operations for Quick Sort


    return 0;

}