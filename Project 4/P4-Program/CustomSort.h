//
// Created by Lisa Dion
//

#ifndef P4_PROGRAM_CUSTOMSORT_H
#define P4_PROGRAM_CUSTOMSORT_H

#include <vector>
#include <iostream>

using namespace std;


//
template <typename Comparable>
void printVector(const vector<Comparable> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ",";
        }
        cout << " ";
    }
    cout << endl;
}


// Complexity of Bubble Sort is Quadratic = O(N^2)
template <typename Comparable>
vector<int> bubbleSort(vector<Comparable> &v, const bool &verbose) {

    // Define counters for READS and WRITES.
    int reads = 0;
    int writes = 0;

    int numSwaps = -1;
    auto maxIndex = static_cast<int>(v.size());
    while (numSwaps != 0) {
        numSwaps = 0;
        for (int i = 0; i + 1 < maxIndex; ++i) {

            // Record READS.
            reads += 2;
            //
            if (v[i] > v[i + 1]) {

                // swap the elements
                Comparable temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                //
                // Record READS and WRITES.
                reads += 2;
                writes += 3;

                ++numSwaps;
            }
        }
        --maxIndex;

        if (verbose) { printVector(v); }

    }


    // Define collection of READS and WRITES statistics.
    vector<int> reads_writes;
    reads_writes.push_back(reads);
    reads_writes.push_back(writes);


    return reads_writes;


}



/**
 *
 * @param v
 * @param verbose
 * @return
 */
vector<int> bubble_sort_alt(vector<RedditElement> &v) {

    // Define counters for READS and WRITES.
    int reads = 0;
    int writes = 0;

    int numSwaps = -1;
    auto maxIndex = static_cast<int>(v.size());
    while (numSwaps != 0) {
        numSwaps = 0;
        for (int i = 0; i + 1 < maxIndex; ++i) {

            // Record READS.
            reads += 2;
            //
            // Sort using the "Score" field of a RedditElement object.
            if (v[i].get_score() > v[i + 1].get_score()) {

                // swap the elements
                RedditElement temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                //
                // Record READS and WRITES.
                reads += 2;
                writes += 3;

                ++numSwaps;
            }
        }
        --maxIndex;

    }


    // Define collection of READS and WRITES statistics.
    vector<int> reads_writes;
    reads_writes.push_back(reads);
    reads_writes.push_back(writes);


    return reads_writes;


}


#endif //P4_PROGRAM_CUSTOMSORT_H
