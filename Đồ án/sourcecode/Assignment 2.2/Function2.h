#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "Interface2.cpp"
#include "Binary Tree.cpp"
#include "../Assignment 1/Common Function.cpp"

using namespace std;
using namespace chrono;

namespace Function2 {
    vector<Student> getInformation();
    void insertInformation(Student& s);
    void updateInformation(vector<vector<Student>>& Students);
    void notification(int x, int y, string s, int delay) ;
    void menuAdd(BinaryTree& BT);
    void menuDelete(BinaryTree& BT);
    void menuTraverse(BinaryTree& BT, int type);
    void listStudents(vector<vector<Student>>& Students, int traversal_type);
    void algorithm(int& type, int traversal_type, string time);
    void menuList(BinaryTree& BT);
};
