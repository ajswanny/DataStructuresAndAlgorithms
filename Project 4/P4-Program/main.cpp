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


    // Perform operations for "Bubble Sort".
    perform_bubble_sorts(data);


    return 0;

}