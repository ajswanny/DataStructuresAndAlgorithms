#include "lecturer.h"
#include "NoCollisionDetection.h"
#include "Probing.h"
#include "SeparateChaining.h"
#include <iostream>
#include <vector>
using namespace std;

unsigned int hornerHash(const string &key, int tableSize);
string getLecturerName(const Lecturer &lec);
string whoAmI(const string &s);
string guessWho(const int &i);

void NoCollisionTesting(vector<Lecturer> &lecs);
void SeparateChainingTesting(vector<Lecturer> &lecturers);
void ProbingTesting(vector<Lecturer> &lecturers);

int main() {
    cout << "Hello, World!" << endl;
    vector<Lecturer> lecturers;
    readLecturers(lecturers);

    for (Lecturer &l : lecturers) {
        cout << l.getName() << ": ";
        cout << hornerHash(l.getName(), 13) << endl;
    }

    SeparateChaining<int> jenny(7, guessWho);
    vector<int> numbers = {8, 6, 7, 5, 3, 0, 9};

    for (int number : numbers) {
        jenny.insert(number);
        cout << hornerHash(guessWho(number), 7) << endl;
        jenny.printTable(cout);
        cout << endl;
    }

    /*
    Probing<string> simpsons(7, whoAmI);
    vector<string> names = {"Homer", "Marge", "Bart", "Lisa", "Maggie", "Santa's Little Helper"};

    for (string name : names ) {
        simpsons.insert(name);
        cout << hornerHash(name, simpsons.getSize()) << endl;
        simpsons.printTable(cout);
        cout << endl;
    }
*/
    return 0;
}

unsigned int hornerHash(const string &key, int tableSize) {
    unsigned int hashVal = 0;
    for (char ch : key) {
        hashVal = 37*hashVal + ch;
    }
    cout << hashVal << ", ";
    return hashVal % tableSize;
}

string getLecturerName(const Lecturer &lec) {
    return lec.getName();
}

string whoAmI(const string &s) {
    return s;
}

string guessWho(const int &i) {
    return to_string(i);
}

void NoCollisionTesting(vector<Lecturer> &lecs) {
    NoCollisionDetection<Lecturer> hashTable1(19, getLecturerName);
    Lecturer dummy;
    //cout << boolalpha << hashTable1.search("Lisa Dion", dummy) << endl;
    cout << boolalpha << hashTable1.remove("Lisa Dion") << endl;
    hashTable1.insert(lecs[0]); // insert Lisa
    //cout << hashTable1.search("Lisa Dion", dummy) << endl;
    cout << hashTable1.remove("Lisa Dion") << endl;

    for (Lecturer &l : lecs) {
        hashTable1.insert(l);
    }
    cout << "Bob's office: ";
    if (hashTable1.search("Robert (Bob) Erickson", dummy)) {
        cout << dummy.getOffice();
    } else {
        cout << "unknown";
    }
    cout << endl;
}

void SeparateChainingTesting(vector<Lecturer> &lecturers) {
    SeparateChaining<Lecturer> hashTable2(13, getLecturerName);
    hashTable2.printTable(cout);
    for (Lecturer &l : lecturers) {
        hashTable2.insert(l);
    }
    hashTable2.printTable(cout);
    Lecturer dummy;
    cout << boolalpha << hashTable2.search("Lisa Dion", dummy); // true
    cout << " " << dummy.getOffice() << endl;
    cout << hashTable2.search("Jackie Horton", dummy); // true
    cout << " " << dummy.getOffice() << endl;
    hashTable2.insert(lecturers[0]); // this should do nothing
    cout << hashTable2.remove("Lisa Dion") << endl; // true
    cout << hashTable2.search("Lisa Dion", dummy) << endl; // false
    hashTable2.printTable(cout);
}

void ProbingTesting(vector<Lecturer> &lecturers) {
    Probing<Lecturer> hashTable3(13, getLecturerName);
    hashTable3.printTable(cout);
    for (Lecturer &l : lecturers) {
        hashTable3.insert(l);
        hashTable3.printTable(cout);
    }
    Lecturer dummy;
    cout << boolalpha << hashTable3.search("Lisa Dion", dummy); // true
    cout << " " << dummy.getOffice() << endl;
    cout << hashTable3.search("Jackie Horton", dummy); // true
    cout << " " << dummy.getOffice() << endl;
    hashTable3.insert(lecturers[0]); // this should do nothing
    cout << hashTable3.remove("Lisa Dion") << endl; // true
    cout << hashTable3.search("Lisa Dion", dummy) << endl; // false

    hashTable3.printTable(cout);
    cout << hashTable3.search("Jackie Horton", dummy) << endl; // true
}
