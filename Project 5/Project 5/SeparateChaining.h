//
// Created by Lisa Dion on 4/2/18.
//


#ifndef PROJECT_5_SEPARATECHAINING_H
#define PROJECT_5_SEPARATECHAINING_H


#include <functional>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


template<typename T>
class SeparateChaining {
private:
    std::vector<std::vector<T>> hashTable;
    int tableSize;
    std::function<std::string(const T &)> getKey;

    unsigned int hornerHash(const std::string &key) {
        unsigned int hashVal = 0;
        for (char ch : key) {
            hashVal = 37*hashVal + ch;
        }
        return hashVal % tableSize;
    }

public:
    SeparateChaining(int tableSizeIn, std::function<std::string(const T &)> getKeyIn) {
        hashTable.resize(tableSizeIn);
        for (std::vector<T> &vec : hashTable) {
            vec.clear();
        }
        tableSize = tableSizeIn;
        getKey = getKeyIn;
    }

    int insert(const T &item) {

        // Define container for READS.
        int insertion_reads = 0;

        //
        // Append READS.
        insertion_reads++;
        //
        std::string key = getKey(item);

        T dummy;
        // Check if the item is already in the hashTable

        //
        // Append READS.
        insertion_reads++;
        //
        if (!search(key, dummy, insertion_reads)) {
            // Item is not there. Insert it.
            int index = hornerHash(key);
            hashTable[index].push_back(item);
        }
        // Item is in hashTable. Do nothing.

        return insertion_reads;

    }

    // Assuming that keys are unique
    // if key leads to active hashItem, set item to hashItem and
    // return true. return false otherwise.
    bool search(std::string key, T &item, int &insertion_reads) {
        int index = hornerHash(key);
        for (T &hashItem : hashTable[index]) {
            //
            // Append READS.
            insertion_reads++;
            //

            if (getKey(hashItem) == key) {
                // we found the item
                item = hashItem;
                return true;
            }
        }
        // went through the vector and didn't find the item
        return false;
    }

    bool remove(std::string key) {
        int index = hornerHash(key);
        for (int i = 0; i < hashTable[index].size(); ++i) {
            if (getKey(hashTable[index][i]) == key) {
                // We found the item. Remove it.
                // Erase method takes an iterator argument
                // Begin method returns iterator that is positioned at
                // the first index. Can add indexes from there.
                hashTable[index].erase(hashTable[index].begin() + i);
                return true;
            }
        }
        // went through the vector and didn't find the item
        return false;
    }

    void printTable(std::ostream &outs) const {
        for (int index = 0; index < tableSize; ++index) {

            outs << index << ": ";
            for (int i = 0; i < hashTable[index].size(); ++i) {
                outs << hashTable[index][i] << ", ";
            }
            outs << endl;

        }
    }

};

#endif //PROJECT_5_SEPARATECHAINING_H
