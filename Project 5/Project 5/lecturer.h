//
// Created by Lisa Dion on 2/5/18.
//

#ifndef PROJECT_5_LECTURER_H
#define PROJECT_5_LECTURER_H


#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Lecturer {
private:
    string name;
    vector<int> classes;
    string office;

public:
    // Constructor
    Lecturer();
    Lecturer(string n, int c1, int c2, int c3, string o);

    // Getters
    string getName() const; // const means it will not modify fields
    int getClass1() const;
    int getClass2() const;
    int getClass3() const;
    string getOffice() const;


    // Setters
    void setName(string n);
    void setClasses(vector<int> &c);
    void setOffice(string o);

    // Overloaded Operators
    friend ostream& operator << (ostream& outs, const Lecturer &l);
};

// reading Lecturers in from a file
void readLecturers(vector<Lecturer> &l);


#endif //PROJECT_5_LECTURER_H
