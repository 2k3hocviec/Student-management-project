#include <iostream>
#include <string>
#include <conio.h>
#include <cctype>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <unordered_map>
#include <windows.h>
#include "Common Function.cpp"
#include "Interface.cpp"
#include "Data Structure.cpp"

using namespace std::chrono;
using namespace std;

struct Data {
    int index;
    nodes* nodes;
    nodec* nodec;
    noded* noded;

    Data() : index(-1), nodes(NULL), nodec(NULL), noded(NULL) {}
    bool empty() { return index == -1 && nodes == NULL && nodec == NULL && noded == NULL; }
};

struct Sorting {
    vector<Student> list;
    bool sorted;
    Sorting() : sorted(false) {}
};

namespace Function {
    vector<Student> getInformation();
    void insertInformation(Student& s);
    void updateInformation(vector<Student> Students);
    Error checkInformation(vector<Student>& Students);

    void notification(int x, int y, string s, int delay);
    void note1(int y);
    void welcome();
    void end();
    void checkInformation();
    void validInformation();
    void invalidInformation(Error& Information);

    void menuAdd(Container& DataStructure);
    void menuUpdate(Container& DataStructure);
    void printUpdateInformation(Student x);
    void menuDelete(Container& DataStructure);
    Data enterStudentId(Container& DataStructure);
    void menuAverageMark(Container& DataStructure);
    void menuSort(Container& DataStructure);
    template<typename T>
    void menuSortingType(T& DataStructure);
    template<typename T>
    void menuSortingCriteria(T& DataStructure, int x, int y, string s, void (T::*sort)(bool (*)(Student&, Student&)), int sorting_type);
    void sortingAlgorithm(int duration, int dataType, int sortingType);
    void menuSearch(Container& DataStructure);
    template<typename T>
    void menuSearching(T& DataStructure);
    template<typename T>
    void searching(T& DataStructure, int(*search_by)(Student&, string&), bool (*sort_by)(Student&, Student&), int x1, string s1, int x2, string s2, bool isMark);
    template<typename T>
    Sorting isSorted(T& DataStructure,int (*search_by)(Student&, string&), bool (*sort_by)(Student&, Student&), string value);
    template<typename T>
    void sectionsOfTheSearch(T& DataStructure, Sorting& res, int (*search_by)(Student&, string&), string& value, int method);
    void searchingAlgorithm(int duration, int dataType, int searchingType);

    void menuListTheStudents(Container& DataStructure);

    template<typename T>
    void printListTheStudents(T& DataStructure);
    void studentList(int x, int y, vector<Student> Students, bool converse, string s, int duration);
    void redStudentList(int x, int y, vector<Student> Students, string s, int (*search_by)(Student&, string&), string& value, int duration);
};
