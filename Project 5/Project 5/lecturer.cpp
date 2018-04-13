//
// Created by Lisa Dion on 2/5/18.
//

#include "lecturer.h"

Lecturer::Lecturer() {
    name = "Jane Doe";
    classes.push_back(101);
    office = "Votey 9.75";
}

Lecturer::Lecturer(string n, int c1, int c2, int c3, string o) {
    name = n;
    classes.push_back(c1);
    classes.push_back(c2);
    if (c3 != 0) {
        // the Lecturer teaches a third class
        classes.push_back(c3);
    }
    office = o;
}

string Lecturer::getName() const {
    return name;
}

int Lecturer::getClass1() const {
    if (classes.size() > 0) {
        return classes[0];
    }
    return 0;
}

int Lecturer::getClass2() const {
    if (classes.size() > 1) {
        return classes[1];
    }
    return 0;
}

int Lecturer::getClass3() const {
    if (classes.size() > 2) {
        return classes[2];
    }
    return 0;
}

string Lecturer::getOffice() const {
    return office;
}

void Lecturer::setName(string n) {
    name = n;
}

void Lecturer::setClasses(vector<int> &c) {
    classes.clear();
    for (int classNum : c) {
        classes.push_back(classNum);
    }
}

void Lecturer::setOffice(string o) {
    office = o;
}

// friends of a class do not need Lecturer::
ostream& operator << (ostream& outs, const Lecturer &l) {
    outs << setw(25) << l.name;
    outs << setw(6) << l.classes[0];
    outs << setw(6) << l.classes[1];
    if (l.classes.size() > 2) {
        outs << setw(6) << l.classes[2];
    } else {
        // there is no third class. Leave that column empty.
        outs << setw(6) << " ";
    }
    outs << setw(12) << l.office;
    return outs;
}

// This function is not part of the Lecturer class
// and does not get a Lecturer::
void readLecturers(vector<Lecturer> &l) {
    l.resize(5);
    int lecCount = 0;

    ifstream fIn;
    fIn.open("CS_Lecturers.csv");
    string name = "", office = "";
    int class1 = 0, class2 = 0, class3 = 0;
    char comma;
    // check that the file opened and is ready to be read from
    // and that the next character is not the end-of-file
    while (fIn && fIn.peek() != EOF) {
        // to read a string, use getline
        // read from the file (f_in)
        // read into the string (name)
        // stop reading at a comma (',')
        getline(fIn, name, ',');
        // next, read the integer classes
        fIn >> class1 >> comma;
        fIn >> class2 >> comma;
        fIn >> class3;
        // check to see if the stream is in a bad state
        if (!fIn) {
            // clear the stream
            fIn.clear();
        }
        fIn >> comma;
        // now read in the office
        // without a third argument, getline stops at a newline char
        getline(fIn, office);

        // save the values for the Lecturer
        l[lecCount] = Lecturer(name, class1, class2, class3, office);
        ++lecCount;

    }
    fIn.close();
}
