#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <windows.h>
#include <conio.h>
#include "Student.cpp"
using namespace std;


void heightScrolling(int height) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);

    COORD newSize = csbi.dwSize;
    newSize.Y = height;
    SetConsoleScreenBufferSize(hOut, newSize);
}


void showCursor(bool visible) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}


void goToxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void printScreen(int x, int y, string s) {
    goToxy(x, y);
    cout << s;
}


void printRedBold(int x, int y, string s) {
    goToxy(x, y);
    cout << "\033[1;31m" << s <<"\033[0m";
}


void printAnimation(int x, int y, int delay, string s) {
    goToxy(x, y);
    for(char& c : s) {
        Sleep(delay);
        cout << c;
    }
}


void printAnimationReverse(int x, int y, int delay, string s) {
    int n = s.size();
    for(int i = n - 1; i >= 0; i--) {
        goToxy(x + i, y);
        Sleep(delay);
        cout << s[i];
    }
}


void reverseString(string& s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {      
        char tmp = s[i];
        s[i++] = s[j];
        s[j--] = tmp;
    }
}


void clearLines(int start, int end) {
    for(int i = start; i <= end; i++) {
        goToxy(1, i);
        for(int j = 1; j <= 120; j++) {
            cout << ' ';
        }
    }
}


void printStudent(int i, int line, Student& a, bool reverse) {
    printScreen(5, 8 + line, to_string(i + 1));
    printScreen(23, 8 + line, a.getId());

    string s = a.getLastName() + " " + a.getFirstName();

    if(reverse == false) {
        printScreen(49, 8 + line, s);
    }
    else {
        reverseString(s);
        printScreen(49, 8 + line, s);
    }

    printScreen(83, 8 + line, a.getClass());

    goToxy(115, 8 + line);
    cout << fixed << setprecision(1) << a.getMark();
}

void printRedStudent(int i, int line, Student& a) {
    printRedBold(5, 8 + line, to_string(i + 1));
    printRedBold(23, 8 + line, a.getId());
    printRedBold(49, 8 + line, a.getLastName() + " " + a.getFirstName());
    printRedBold(83, 8 + line, a.getClass());

    goToxy(115, 8 + line);
    cout << "\033[1;31m" << fixed << setprecision(1) << a.getMark() <<"\033[0m";
}


void printStudentList(vector<Student> Students, int& page, bool reverse, int number) {
    int n = Students.size();
    int mx = min(page * number, n);
    int line = 0;
                                                                                                      
    clearLines(8, 8 + number - 1);

    for(int i = (page - 1)*number; i < mx; i++) {
        printStudent(i, line, Students[i], reverse);
        line++;
    }
}


void printList(vector<Student> Students, bool reverse) {
    showCursor(false);

    int page = 1 ;
    int n = Students.size();
    int max_page = n / 15 + (n % 15 == 0 ? 0 : 1);

    goToxy(5, 23);
    cout << "_____________________________________________________________________________________________________________________";
    printScreen(4, 25, " '<--' go to previous page");
    printScreen(101, 25, "go to next page '-->'");
    printScreen(54, 25, "Page " + to_string(page));
    printStudentList(Students, page, reverse, 15);

    while(true) {
        char c = _getch();
        if(c == 9) {            //tab
            return;
        }
        else if(c == 75) {           //left
            if(page - 1 >= 1) {
                page--;
                printStudentList(Students, page, reverse, 15);
            }
        }
        else if(c == 77) {
            if(page + 1 <= max_page) {
                page++;
                printStudentList(Students, page, reverse, 15);
            }
        }
        printScreen(54, 25, "Page " + to_string(page));
    }
}


void printRedStudentList(vector<Student> Students, int& page, int number, int (*searchBy)(Student&, string&), string& value) {
    int n = Students.size();
    int mx = min(page * number, n);
    int line = 0;
    bool reverse = false;

    clearLines(8, 8 + number - 1);   

    for(int i = (page - 1)*number; i < mx; i++) {
        if(searchBy(Students[i], value) != 0) {
            printStudent(i, line, Students[i], reverse);
        }
        else {
            printRedStudent(i, line, Students[i]);
        }
        line++;
    }
}


void printRedList(vector<Student> Students, int (*searchBy)(Student&, string&), string& value) {
    showCursor(false);

    int page = 1 ;
    int n = Students.size();
    int max_page = n / 15 + (n % 15 == 0 ? 0 : 1);

    goToxy(5, 23);
    cout << "_____________________________________________________________________________________________________________________";
    printScreen(4, 25, " '<--' go to previous page");
    printScreen(101, 25, "go to next page '-->'");
    printScreen(54, 25, "Page " + to_string(page));
    printRedStudentList(Students, page, 15, searchBy, value);

    while(true) {
        char c = _getch();
        if(c == 9) {            //tab
            return;
        }
        else if(c == 75) {           //left
            if(page - 1 >= 1) {
                page--;
                printRedStudentList(Students, page, 15, searchBy, value);
            }
        }
        else if(c == 77) {
            if(page + 1 <= max_page) {
                page++;
                printRedStudentList(Students, page, 15, searchBy, value);
            }
        }
        printScreen(54, 25, "Page " + to_string(page));
    }
}


char input(int x, int y, int maxi, bool cont) {
    showCursor(false);
    char c, ch;
    string res = "";

    while (true) {
        goToxy(x, y);
        ch = _getch();
        if(ch == 9)  return 't'; // tab
        if(cont == true) {           // enter
            if(ch == 13) return 'e';
            else continue;
            }
        if(ch >= '1' && ch <= char(maxi + '1' - 1)) {
            cout << ch;
            return ch;
        }
    }
    return c;
}


string inputScreen(int x, int y, int maxi, bool space) {
    goToxy(x, y);
    string res = "";
    bool b = true;

    while(true) {
        char c = _getch();

        if(c == 9) {     //tab
            return "";
        }
        else if (c == 8) {    // Backspace
            if (!res.empty()) {
                res.pop_back();
                goToxy(x + res.length(), y);
                cout << ' ';
                goToxy(x + res.length(), y);
            }
        }
        else if(c == 13) {    //enter
            if(!res.empty()) break;
            else continue;
        }
        else {
            if(res.size() == maxi) continue;
            if(b == true) {
                printScreen(x, y, string(maxi, ' '));
                goToxy(x, y);
                b = false;
            }
            if(space == false) {
                if(c == ' ') {
                    continue;
                }
            }
            res.push_back(c);
            cout << c;
        }
    }
    return res;
}

char operation(int start_x, int start_y, int options) {
    int n = options;
    int y = 0;
    int pr_y = 0;

    showCursor(false);
    Sleep(200);
    printScreen(start_x, start_y + y*2, "->");

    while(true) {
        char c = _getch();

        if(c == 9) {            //tap
            return 't';      
        }
        else if(c == 13) {      // enter
            return char(y + 1 + '0');
        }
        else if(c == 72) {      // top
            y = (y + n - 1) % n;
            printScreen(start_x, start_y + pr_y*2, "   ");
            printScreen(start_x, start_y + y*2, "->");
            pr_y = y;
        }
        else if(c == 80) {      // down
            y = (y + 1) % n;
            printScreen(start_x, start_y + pr_y*2, "   ");
            printScreen(start_x, start_y + y*2, "->");
            pr_y = y;
        }
    }
}


bool checkId(string& id) {
    //NxxABCDxxx
    if(id.size() != 10 || id[0] != 'N') return false;
    if(!isdigit(id[1]) || !isdigit(id[2])) return false;
    if(!isdigit(id[7]) || !isdigit(id[8]) || !isdigit(id[9])) return false;

    for(int i = 3; i <= 6; i++) {
        if(id[i] < 65 || id[i] > 90) {
            return false;
        }
    }
    return true;
}


bool checkSpace(string& s) {
    return s.find(' ') == string::npos;
}


bool checkMark(string _mark) {
    istringstream is(_mark);
    float mark;
    char extra;
    if (!(is >> mark)) return false;
    if (is >> extra) return false;
    return mark >= 0 && mark <= 10 && (_mark.size() > 0 && _mark[0] != '-');
}


string lower(string s) {
    string res = "";
    for (char& ch : s) {
        if (isalpha(ch)) {
            res += tolower(ch);
        } else {
            res += ch;
        }
    }
    return res;
}

string StandardizeName(string s) {
    if(s == "") return "";

    int n = s.size(), i = 0;
    string res = "";

    while(i < n) {
        while(i < n && s[i] == ' ') i++;
        if(i == n) break;

        res += toupper(s[i++]);
        if(i == n) break;

        while(i < n && s[i] != ' ') {
            res += tolower(s[i++]);
        }
        res += " ";        
    }
    if(res.size() == 0) {
        return " ";
    }
    else {
        if(res[res.size() - 1] == ' ') {
            res.pop_back();
        }
        return res;
    }
}

string StandardizeClass(string s) {
    string res = "";
    for(char& c : s) {
        res += toupper(c);
    }
    return res;
}

template<typename T>
vector<Student> listWithLowestMark(T& DataStructure) {
    vector<Student> x = DataStructure.allStudents();
    if(x.empty()) return {};

    float mini_mark = 10.0;
    vector<Student> res;

    if(DataStructure.isSorted == true) {
        mini_mark = x[0].getMark();
        int i = 0;

        while(i < x.size() && x[i].getMark() == mini_mark) {
            res.push_back(x[i++]);
        }
    }
    else {
        for(Student& i : x) {
            mini_mark = min(mini_mark, i.getMark());
        }
        for(Student& i : x) {
            if(i.getMark() == mini_mark) {
                res.push_back(i);
            }
        }
    }
    return res;
}

template<typename T>
vector<Student> listWithHighestMark(T& DataStructure) {
    vector<Student> x = DataStructure.allStudents();
    if(x.empty()) return {};

    float maxi_mark = 0;
    vector<Student> res;

    if(DataStructure.isSorted == true) {
        maxi_mark = x[x.size() - 1].getMark();
        int i = x.size() - 1;

        while(i >= 0 && x[i].getMark() == maxi_mark) {
            res.push_back(x[i--]);
        }
    }
    else {
        for(Student& i : x) {
            maxi_mark = max(maxi_mark, i.getMark());
        }
        for(Student& i : x) {
            if(i.getMark() == maxi_mark) {
                res.push_back(i);
            }
        }
    }
    return res;
}

int searchById(Student& s, string& value) {
    string a = lower(s.getId());
    string b = lower(value);
    if(a == b) return 0;
    else if(a < b) return -1;
    else return 1;
}

int searchByLastName(Student& s, string& value) {
    string a = lower(s.getLastName());
    string b = lower(value);
    if(a == b) return 0;
    else if(a < b) return -1;
    else return 1;
}

int searchByFirstName(Student& s, string& value) {
    string a = lower(s.getFirstName());
    string b = lower(value);
    if(a == b) return 0;
    else if(a < b) return -1;
    else return 1;
}

int searchByClass(Student& s, string& value) {
    string a = lower(s.getClass());
    string b = lower(value);
    if(a == b) return 0;
    else if(a < b) return -1;
    else return 1;
}

int searchByMark(Student& s, string& value) {
    float a = s.getMark();
    float b = stof(value);
    if(a == b) return 0;
    else if(a < b) return -1;
    else return 1;
}

bool sortById(Student& a, Student& b) {
    return a.getId() <= b.getId();
}

bool sortByName(Student& a, Student& b) {
    if(a.getFirstName() != b.getFirstName()) return a.getFirstName() < b.getFirstName();
    else if (a.getLastName() != b.getLastName()) return a.getLastName() < b.getLastName();
    else return a.getId() < b.getId();
}

bool sortByLastName(Student& a, Student& b) {
    return a.getLastName() <= b.getLastName();
}

bool sortByFirstName(Student& a, Student& b) {
    return a.getFirstName() <= b.getFirstName();
}

bool sortByClass(Student& a, Student& b) {
    return a.getClass() <= b.getClass();
}

bool sortByMark(Student& a, Student& b) {
    return a.getMark() <= b.getMark();
}