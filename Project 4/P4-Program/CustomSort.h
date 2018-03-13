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
void bubbleSort(vector<Comparable> &v, const bool &verbose) {
    int numSwaps = -1;
    auto maxIndex = static_cast<int>(v.size());
    while (numSwaps != 0) {
        numSwaps = 0;
        for (int i = 0; i + 1 < maxIndex; ++i) {
            if (v[i] > v[i + 1]) {
                // swap the elements
                Comparable temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                ++numSwaps;
            }
        }
        --maxIndex;

        if (verbose) { printVector(v); }

    }
}


#endif //P4_PROGRAM_CUSTOMSORT_H
