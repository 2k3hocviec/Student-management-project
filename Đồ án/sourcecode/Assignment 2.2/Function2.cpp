#include "Function2.h"

vector<Student> Function2::getInformation() {
    vector<Student> Students;    
    ifstream file("../DSSV.csv");
    string line;

    while(getline(file, line)) {
        stringstream ss(line);
        vector<string> storage(5);

        for(int i = 0; i < 4; i++) {
            getline(ss, storage[i], ',');
        }
        getline(ss, storage[4]);
        Students.push_back({storage[0], storage[2], storage[1], storage[3], stof(storage[4])});
    }
    return Students;
}

void Function2::insertInformation(Student& s) {   
    string filename = "../DSSV.csv";
    ofstream file(filename, ios::app);

    if(!file.is_open()) {
        Function2::notification(50,7," -  CANNOT OPEN THE DSSV.CSV FILE!!  -", 1500);
        return;
    }
    else {
        file << s.getId() << "," << s.getLastName() << "," << s.getFirstName() << "," << s.getClass() << "," << s.getMark() << "\n";
        file.close();
    }
}

void Function2::updateInformation(vector<vector<Student>>& Students) {
    string filename = "../DSSV.csv";
    ofstream file(filename);

    if (!file.is_open()) {
        Function2::notification(50,7," -  CANNOT OPEN THE DSSV.CSV FILE!!  -", 1500);
        return;;
    }
    else {
        for(vector<Student>& students : Students ) {
            for(Student& s : students) {
                file << s.getId() << "," << s.getLastName() << "," << s.getFirstName() << "," << s.getClass() << "," << s.getMark() << "\n";
            }
        }
    }
    file.close();
}

void Function2::notification(int x, int y, string s, int delay) {
    Interface2::notification();
    printAnimation(x, y, 50, s);
    Sleep(delay);
}

void Function2::menuAdd(BinaryTree& BT) {
    showCursor(true);
    Interface2::menuAdd();

    string _lname, _fname, _id, _class;
    float _mark;

    _lname = StandardizeName(inputScreen(60, 7, 20, true));
    if(_lname == "") return;

    _fname = StandardizeName(inputScreen(60, 10, 20, true));
    if(_fname == "") return;

    while(true) {
        showCursor(true);

        bool exist = false;
        _id = inputScreen(60, 13, 20, false);
        if(_id == "") return;

        if(checkId(_id) == false) {
            showCursor(false);
            printRedBold(60, 13, "ID must be formatted as 'N23DCCNxxx'");
            Sleep(2000);
            printScreen(60, 13, "                                    ");
            continue;
        }

        vector<Student> Students = Function2::getInformation();
        for(Student& student : Students) {
            if(student.getId() == _id) {
                exist = true;
                break;
            }
        }
        if(exist == true) {
            showCursor(false);
            printRedBold(60, 13, "This student id already exist!");
            Sleep(2000);
            printScreen(60, 13, "                                ");
            continue;
        }
        else {
            break;
        }
    }   

    _class = StandardizeName(inputScreen(60, 16, 20, false));
    if(_class == "") return;

    while(true) {
        showCursor(true);

        string _markk = inputScreen(60, 19, 10, false);
        if(_markk == "") return;

        if(checkMark(_markk) == true) {
            _mark = stof(_markk);
            break;
        }
        else {
            showCursor(false);
            printRedBold(60, 19, "Mark is invalid, please enter again!");
            Sleep(2000);
            printScreen(60, 19, "                                    ");
            continue;
        }
    }

    showCursor(false);
    Interface2::menuConfirmAdd();
    printScreen(60, 7, _lname);
    printScreen(60, 10, _fname);
    printScreen(60, 13, _id);
    printScreen(60, 16, _class);
    printScreen(60, 19, to_string(_mark));

    while(true) { 
        char c = input(0, 0, 0, true);
        if(c == 'e') break;
    }

    Student student = Student(_id, _fname, _lname, _class, _mark);
    BT.insertStudent(student);
    Function2::insertInformation(student);
}

void Function2::menuDelete(BinaryTree& BT) {
    Interface2::menuDeleteByMark();

    float mark;
    while(true) {
        showCursor(true);
        string _mark = inputScreen(59, 7, 7, false);
        if(_mark == "") return;

        if(checkMark(_mark) == true) {
            mark = stof(_mark);
        }
        else {
            showCursor(false);
            printRedBold(59, 7, "Mark is invalid, please enter again!");
            Sleep(2000);
            printScreen(59, 7, "                                    ");
            continue;
        }
        if(BT.search(mark) == true) {
            break;
        }
        else {
            showCursor(false);
            printRedBold(59, 7, "Mark does not exist!");
            Sleep(2000);
            printScreen(59, 7, "                                    ");
            continue;
        }
    }
    BT.remove(mark);
    int type = 1;
    vector<vector<Student>> Students = BT.traversal(type);

    showCursor(false);
    Function2::updateInformation(Students);
    Function2::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
}

void Function2::menuTraverse(BinaryTree& BT, int type) {
    vector<vector<Student>> Students;
    int traversal_type;

    while (true) {
        Interface2::menuTraverse();

        microseconds duration;
        high_resolution_clock::time_point start, end;

        if (type == 1) {
            printScreen(58, 4, "RECURSIVE TRAVERSAL");

            char c = operation(39, 10, 5);
            if (c == 't') return;

            switch (c) {
                case '1': {
                    traversal_type = 1;
                    start = high_resolution_clock::now();
                    Students = BT.traversal(traversal_type);
                    end = high_resolution_clock::now();
                    duration = duration_cast<microseconds>(end - start);
                    Function2::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
                    break;
                }
                case '2': {
                    traversal_type = 2;
                    start = high_resolution_clock::now();
                    Students = BT.traversal(traversal_type);
                    end = high_resolution_clock::now();
                    duration = duration_cast<microseconds>(end - start);
                    Function2::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
                    break;
                }
                case '3': {
                    traversal_type = 3;
                    start = high_resolution_clock::now();
                    Students = BT.traversal(traversal_type);
                    end = high_resolution_clock::now();
                    duration = duration_cast<microseconds>(end - start);
                    Function2::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
                    break;
                }
                case '4': {
                    if(Students.size() == 0) {
                        Function2::notification(47, 7, "-  PLEASE SELECT ONE OF THE TRAVERSAL TYPES  -", 1000);
                    }
                    else {
                        Function2::algorithm(type, traversal_type, to_string(duration.count()));
                    }
                    break;
                }
                case '5': {
                    if(Students.size() == 0) {
                        Function2::notification(47, 7, "-  PLEASE SELECT ONE OF THE TRAVERSAL TYPES  -", 1000);
                    }
                    else {
                        Function2::listStudents(Students, traversal_type);
                    }
                    break;
                }
            }
        } else {
            printScreen(56, 4, "NON-RECURSIVE TRAVERSAL");

            char c = operation(39, 10, 5);
            if (c == 't') return;

            switch (c) {
                case '1': {
                    traversal_type = 1;
                    start = high_resolution_clock::now();
                    Students = BT.iterativePreOrder();
                    end = high_resolution_clock::now();
                    duration = duration_cast<microseconds>(end - start);
                    Function2::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
                    break;
                }
                case '2': {
                    traversal_type = 2;
                    start = high_resolution_clock::now();
                    Students = BT.iterativeInOrder();
                    end = high_resolution_clock::now();
                    duration = duration_cast<microseconds>(end - start);
                    Function2::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
                    break;
                }
                case '3': {
                    traversal_type = 3;
                    start = high_resolution_clock::now();
                    Students = BT.iterativePostOrder();
                    end = high_resolution_clock::now();
                    duration = duration_cast<microseconds>(end - start);
                    Function2::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
                    break;
                }
                case '4': {
                    if(Students.size() == 0) {
                        Function2::notification(47, 7, "-  PLEASE SELECT ONE OF THE TRAVERSAL TYPES  -", 50);
                    }
                    else {
                        Function2::algorithm(type, traversal_type, to_string(duration.count()));
                    }
                    break;
                }
                case '5': {
                    if(Students.size() == 0) {
                        Function2::notification(47, 7, "-  PLEASE SELECT ONE OF THE TRAVERSAL TYPES  -", 50);
                    }
                    else {
                        Function2::listStudents(Students, traversal_type);
                    }
                    break;
                }
            }
        }
    }
}

void Function2::listStudents(vector<vector<Student>>& Students, int traversal_type) {
    Interface2::menuList();
    switch(traversal_type) {
        case 1 : {
            printScreen(50, 2, "PRE-ORDER TRAVERSAL");
            break;
        }
        case 2 : {
            printScreen(51, 2, "IN-ORDER TRAVERSAL");
            break;
        }
        case 3 : {
            printScreen(49, 2, "POST-ORDER TRAVERSAL");
            break;
        }
    }
    vector<Student> listStudents;
    for(vector<Student>& students : Students) {
        for(Student& student : students) {
            listStudents.push_back(student);
        }
    }
    printList(listStudents, false);
}

void Function2::algorithm(int& type, int traversal_type, string time) {
    Interface2::menuAlgorithm();
    switch(type) {
        case 1: {
            printAnimation(68, 10, 60, "Recursive Traversal");
            break;
        }
        case 2: {
            printAnimation(68, 10, 60, "Non-Recursive Traversal");
            break;
        }
    }
    switch(traversal_type) {
        case 1 : {
            printAnimation(68, 12, 60, "Pre-Order Traversal");
            break;
        }
        case 2 : {
            printAnimation(68, 12, 60, "In-Order Traversal");
            break;
        }
        case 3 : {
            printAnimation(68, 12, 60, "Post-Order Traversal");
            break;
        }
    }
    printAnimation(68, 14, 60, "O(n)");
    printAnimation(68, 16, 60, time + "ms");
    printAnimation(68, 18, 60, "O(h) (h: the height of the tree)");
    char ch = input(0, 0, 0, 0);
}

void Function2::menuList(BinaryTree& BT) {
    Interface2::menuList();
    printScreen(53, 2, "THE STUDENT LIST");
    vector<Student> Students = Function2::getInformation();
    printList(Students, false);
}
