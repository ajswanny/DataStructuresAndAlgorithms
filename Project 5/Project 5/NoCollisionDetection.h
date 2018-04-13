//
// Created by Lisa Dion on 3/21/18.
//

#ifndef PROJECT_5_NOCOLLISIONDETECTION_H
#define PROJECT_5_NOCOLLISIONDETECTION_H


#include <functional>
#include <string>
#include <vector>


template<typename T>
class NoCollisionDetection {
private:
    enum status {empty, active};

    struct hashItem {
        T item;
        status state;
    };

    std::vector<hashItem> hashTable;
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
    NoCollisionDetection(int tableSizeIn, std::function<std::string(const T &)> getKeyIn) {
        hashTable.resize(tableSizeIn);
        for (hashItem &h : hashTable) {
            h.state = empty;
        }
        tableSize = tableSizeIn;
        getKey = getKeyIn;
    }

    void insert(const T &item) {
        std::string key = getKey(item);
        int index = hornerHash(key);
        hashTable[index].item = item;
        hashTable[index].state = active;
    }

    // Assuming that keys are unique
    // if key leads to active hashItem, set item to hashItem and
    // return true. return false otherwise.
    bool search(std::string key, T &item) {
        int index = hornerHash(key);
        if (hashTable[index].state == empty) {
            return false;
        } else {
            item = hashTable[index].item;
            return true;
        }
    }

    bool remove(std::string key) {
        int index = hornerHash(key);
        if (hashTable[index].state == empty) {
            return false;
        } else {
            hashTable[index].state = empty;
            return true;
        }
    }

};


#endif //PROJECT_5_NOCOLLISIONDETECTION_H
