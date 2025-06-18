#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string id;
    string fname;
    string lname;
    string classs;
    float mark;

public:
    Student() {}
    Student(string _id, string _fname, string _lname, string _class, float _mark) : id(_id), fname(_fname), lname(_lname), classs(_class), mark(_mark) {}
    
    friend ostream& operator << (ostream& cout, Student& other) {
        cout << other.id << " ";
        cout << other.lname << " ";
        cout << other.fname << " ";
        cout << other.classs << " ";
        cout << other.mark << " ";
        return cout;
    } 

    string getId() { return id; }
    string getFirstName() { return fname; }
    string getLastName() { return lname; }
    string getClass() { return classs; }
    float  getMark() { return mark; }

    void changeId(string _id) { id = _id; }
    void changeFirstName(string _fname) { fname = _fname; }
    void changeLastName(string _lname) { lname = _lname; }
    void changeClass(string _classs) { classs = _classs; }
    void changeMark(float _mark) { mark = _mark; }
};

class Error {
public:
    bool error;
    vector<string> invalid_id;
    vector<string> duplicate_id;
    vector<string> space_cl;
    Error() {}
    Error(bool _error, vector<string> _invalid_id, vector<string> _duplicate_id, vector<string> _space_cl) : error(_error), invalid_id(_invalid_id), duplicate_id(_duplicate_id), space_cl(_space_cl) {}
};