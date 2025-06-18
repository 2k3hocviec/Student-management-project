#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "Function.cpp"
#include "Student.cpp"
using namespace std;

class Console {
public:
    void startProgram();
    void dataStorageMethod(Container& DataStructure, vector<Student>& Students);
    void menuMain(Container& DataStructure);
};