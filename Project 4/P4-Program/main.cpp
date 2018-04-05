//
// Created by Alexander Swanson on 3/12/18.
//

#include <iostream>

#include "Operations.h"
#include "CustomSort.h"


int main() {



    // SWAP FUNCTIONS ARE 2 READS AND 2 WRITES
    // FOR LOOPS



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



    // Perform operations for Quick Sort.
//    vector<vector<int>> quick_sort_rw_data = perform_quick_sorts(data, true);

    // Archive read and write data for Quick Sort.
//    archive_read_write_counts("quick_sort_rw_data.csv", quick_sort_rw_data);



    // Perform operations for Heap Sort.
//    vector<vector<int>> heap_sort_rw_data = perform_heap_sorts(data, true);

    // Archive read and write data for Heap Sort.
//    archive_read_write_counts("heap_sort_rw_data.csv", heap_sort_rw_data);



    // Perform operations for Heap Sort.
//    vector<vector<int>> heap_sort_rw_data = perform_heap_sorts(data, true);

    // Archive read and write data for Heap Sort.
//    archive_read_write_counts("heap_sort_rw_data.csv", heap_sort_rw_data);



    //// Perform operations for Two-Sort

    // Perform operations for Shell Sort.
//    vector<vector<int>> shell_sort_rw_data = perform_shell_sorts(data, true);

    // Archive read and write data for Shell Sort.
//    archive_read_write_counts("TWOSORT_shell_sort_rw_data.csv", shell_sort_rw_data);

    // Perform operations for ALT Bubble Sort.
//    vector<vector<int>> alt_bubble_sort_rw_data = perform_alt_bubble_sorts(data, true);

    // Archive read and write data for ALT Bubble Sort.
//    archive_read_write_counts("TWOSORT_alt_bubble_sort_rw_data.csv", alt_bubble_sort_rw_data);




    return 0;

}
