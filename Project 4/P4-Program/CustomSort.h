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
vector<int>& bubbleSort(vector<Comparable> &v, const bool &verbose) {

    int reads = 0;
    int writes = 0;

    int numSwaps = -1;
    auto maxIndex = static_cast<int>(v.size());
    while (numSwaps != 0) {
        numSwaps = 0;
        for (int i = 0; i + 1 < maxIndex; ++i) {
            if (v[i] > v[i + 1]) {

                // Record READS.
                reads += 2;

                // swap the elements
                Comparable temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;

                // Record WRITES.
                writes += 2;

                ++numSwaps;
            }
        }
        --maxIndex;

        if (verbose) { printVector(v); }

    }

    vector<int> reads_writes(2);

    reads_writes.push_back(reads);
    reads_writes.push_back(writes);

    cout << "Reads: " << reads_writes[0] << endl;
    cout << "Writes: " << reads_writes[1] << endl;

    return reads_writes;


}


#endif //P4_PROGRAM_CUSTOMSORT_H
