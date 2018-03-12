#include <iostream>

#include "Operations.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    vector<RedditElement> data;


    generate_reddit_data(false, data);


    cout << data[0];

    return 0;

}