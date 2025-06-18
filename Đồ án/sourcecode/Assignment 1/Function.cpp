#include "Function.h"

vector<Student> Function::getInformation() {
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
        Students.push_back({storage[0], StandardizeName(storage[2]), StandardizeName(storage[1]), StandardizeClass(storage[3]), stof(storage[4])});
    }
    return Students;
}

void Function::insertInformation(Student& s) {   
    string filename = "../DSSV.csv";
    ofstream file(filename, ios::app);

    if(!file.is_open()) {
        Function::notification(50,7," -  CANNOT OPEN THE DSSV.CSV FILE!!  -", 1500);
        return;
    }
    else {
        file << s.getId() << "," << s.getLastName() << "," << s.getFirstName() << "," << s.getClass() << "," << s.getMark() << "\n";
        file.close();
    }
}

void Function::updateInformation(vector<Student> Students) {
    string filename = "../DSSV.csv";
    ofstream file(filename);

    if (!file.is_open()) {
        Function::notification(50,7," -  CANNOT OPEN THE DSSV.CSV FILE!!  -", 1500);
        return;
    }
    else {
        for (Student& s : Students) {
            file << s.getId() << "," << s.getLastName() << "," << s.getFirstName() << "," << s.getClass() << "," << s.getMark() << "\n";
        }
    }
    file.close();
}

Error Function::checkInformation(vector<Student>& Students) {
    bool error = false;
    unordered_map<string, int> mp;
    vector<string> invalid_id;
    vector<string> duplicate_id;
    vector<string> space_cl;

    for(Student& x : Students) {
        string _id = x.getId();
        string _cl = x.getClass();
        mp[_id]++;

        if(!checkId(_id)) {
            error = true;
            invalid_id.push_back(_id);
        }
        if(!checkSpace(_cl)) {
            error = true;    
            space_cl.push_back(_cl);
        }
    }
    for(auto& [x, y] : mp) {
        if(y >= 2) {
            error = true;
            duplicate_id.push_back(x);
        }
    }
    return {error, invalid_id, duplicate_id, space_cl};
}

void Function::notification(int x, int y, string s, int delay) {
    Interface::notification();
    printAnimation(x, y, 50, s);
    Sleep(delay);
}

void Function::note1(int y) {
    printScreen(1, y, " ");
    Interface::note1();
}

void Function::welcome() {
    Interface::notification();
    Function::note1(21);
    printAnimation(58, 7, 30, "- Welcome to Group 2 -");
    printAnimation(56, 11, 10, "Press 'Enter' to continue");
    printAnimation(8, 21, 20, "Note: Click on the screen to start typing");
    printScreen(112, 21, "Press 'Tab' to exit");
}

void Function::checkInformation() {
    Interface::notification();
    printAnimation(40, 7, 20, "- System is checking information from the DSSV.csv file -");
    Sleep(700);
    printAnimationReverse(40, 7, 10, "                                                         ");
}

void Function::validInformation() {
    Interface::notificationNote();
    printAnimation(52, 7, 30, "- Data from DSSV.csv file is valid -");
    Sleep(1000);
    printAnimationReverse(52, 7, 20, "                                    ");
    printAnimation(41, 7, 10, "Note:");
    printAnimation(41, 8, 10, "- The first and last name will be automatically formatted:");
    printAnimation(43, 9, 10, "+ First letter uppercase, the rest lowercase");
    printAnimation(43, 10, 10, "+ Words are separated by a single space");
    printAnimation(41, 11, 10, "Example: 'Nguyen Dong Din'");
    printAnimation(41, 13, 10, "- The class name will be formatted in ALL UPPERCASE letters");
    printAnimation(41, 14, 10, "Example: 'D23CQCN03'");
    printAnimation(41, 16, 10, "- The Student ID is 'NxxABCDxxx'");
    printAnimation(41, 17, 10, "Example: 'N23DCCN146");
}

void Function::invalidInformation(Error& Information) {
    Interface::notification();
    printAnimation(55, 7, 70, "- Information is INVALID! -");
    Sleep(1000);
    printAnimationReverse(54, 7, 10, "                             ");
    printAnimation(40, 7, 60, "      - Please check again from the DSSV.csv file -      ");
    Sleep(1000);

    Interface::invalidInformation();

    int cnt = 0;
    int a = Information.space_cl.size();
    int b = Information.duplicate_id.size();
    int c = Information.invalid_id.size();
    int n = max({a, b, c});

    for(int i = 0; i < n; i++) {
        if(i < a) printScreen(1, 8 + cnt, Information.space_cl[i]);
        if(i < b) printScreen(41, 8 + cnt, Information.duplicate_id[i]);
        if(i < c) printScreen(69, 8 + cnt, Information.invalid_id[i]);
        cout << endl;
        if(cnt + 1 <= 27) cnt++;
    }
    char ch = input(0, 0, 0, false);
}

void Function::menuAdd(Container& DataStructure) {
    showCursor(true);
    Interface::menuAdd();

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
            printRedBold(60, 13, "ID must be formatted as 'NxxABCDxxx'");
            Sleep(2000);
            printScreen(60, 13, "                                    ");
            continue;
        }

        switch(DataStructure.type) {
            case 1: {
                if(DataStructure.Array.search(_id) != -1) exist = true;
                break;
            }
            case 2: {
                if(DataStructure.Sll.search(_id) != NULL) exist = true;
                break;
            }
            case 3: {
                if(DataStructure.Cll.search(_id) != NULL) exist = true;
                break;
            }
            case 4: {
                if(DataStructure.Dll.search(_id) != NULL) exist = true;
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

    _class = StandardizeClass(inputScreen(60, 16, 20, false));
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
        }
    }

    Student student = Student(_id, _fname, _lname, _class, _mark);

    switch(DataStructure.type) {
        case 1: {
            DataStructure.Array.insertStudent(student);
            DataStructure.Array.isSorted = false;
            break;
        }
        case 2: {
            DataStructure.Sll.insertStudent(student);
            DataStructure.Sll.isSorted = false;
            break;
        }
        case 3: {
            DataStructure.Cll.insertStudent(student);
            DataStructure.Cll.isSorted = false;
            break;
        }
        case 4: {
            DataStructure.Dll.insertStudent(student);
            DataStructure.Dll.isSorted = false;
            break;
        }
    }

    showCursor(false);
    Interface::menuConfirmAdd();
    printScreen(60, 7, _lname);
    printScreen(60, 10, _fname);
    printScreen(60, 13, _id);
    printScreen(60, 16, _class);
    printScreen(60, 19, to_string(_mark));

    while(true) {
        char c = input(0, 0, 0, true);
        if(c == 'e') break;
    }
    Function::insertInformation(student);
}

void Function::menuUpdate(Container& DataStructure) {
    while(true) {
        Interface::enterStudentId();
        printScreen(54, 4, "ENTER STUDENT ID TO UPDATE");

        Data data = Function::enterStudentId(DataStructure);

        if(data.empty()) {     
            return;
        }
        else {
            while(true) {
                Student student;
                bool success = false;

                switch(DataStructure.type) {
                    case 1: {
                        student = DataStructure.Array.head[data.index]; 
                        break;
                    }
                    case 2: {
                        student = data.nodes->data;
                        break;
                    }
                    case 3: {
                        student = data.nodec->data;
                        break;
                    }
                    case 4: {
                        student = data.noded->data;
                        break;
                    }
                }

                showCursor(false);
                Function::printUpdateInformation(student);

                char c = operation(39, 10, 4);
                if(c == 't') break;

                Interface::criteria();
                showCursor(true);

                if(c == '1') {
                    printScreen(59, 4, "UPDATE LAST NAME");
                    printScreen(42, 7, "Last name");

                    string _lname = StandardizeName(inputScreen(59, 7, 15, true));

                    if(_lname != "") {
                        student.changeLastName(_lname);
                        success = true;
                    }
                }
                else if(c == '2') {
                    printScreen(59, 4, "UPDATE FIRST NAME");
                    printScreen(42, 7, "First name");

                    string _fname = StandardizeName(inputScreen(59, 7, 15, true));

                    if(_fname != "") {
                        student.changeFirstName(_fname);
                        success = true;
                    }
                }
                else if(c == '3') {
                    printScreen(61, 4, "UPDATE CLASS");
                    printScreen(44, 7, "CLASS");

                    string _class = StandardizeClass(inputScreen(59, 7, 20, false));
                    
                    if(_class != "") {
                        student.changeClass(_class);
                        success = true;
                    }
                }
                else if(c == '4') {
                    printScreen(61, 4, "UPDATE MARK");
                    printScreen(44, 7, "Mark");
                    float _mark;

                    while(true) {
                        showCursor(true);

                        string _markk = inputScreen(59, 7, 10, false);
                        if(_markk == "") break;

                        if(checkMark(_markk) == true) {
                            _mark = stof(_markk);
                            student.changeMark(_mark);
                            success = true;
                            break;
                        }
                        else {
                            showCursor(false);
                            printRedBold(59, 7, "Mark is invalid, please enter again!");
                            Sleep(2000);
                            printScreen(59, 7,"                                    ");
                        }
                    }
                }

                vector<Student> Students;

                if(success == true) {
                    switch(DataStructure.type) {
                        case 1: {
                            DataStructure.Array.head[data.index] = student;
                            Students = DataStructure.Array.allStudents();
                            if(c == '4') DataStructure.Array.isSorted = false;
                            break;
                        }
                        case 2: {
                            data.nodes->data = student;
                            Students = DataStructure.Sll.allStudents();
                            if(c == '4') DataStructure.Sll.isSorted = false;
                            break;
                        }
                        case 3: {
                            data.nodec->data = student;
                            Students = DataStructure.Cll.allStudents();
                            if(c == '4') DataStructure.Cll.isSorted = false;
                            break;
                        }
                        case 4: {
                            data.noded->data = student;
                            Students = DataStructure.Dll.allStudents();
                            if(c == '4') DataStructure.Dll.isSorted = false;
                            break;
                        }
                    }
                    showCursor(false);
                    Function::updateInformation(Students);
                    Function::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
                }
            }
        }
    }
}

void Function::printUpdateInformation(Student x) {
    Interface::menuUpdate();
    printScreen(69, 4, x.getId());
    printScreen(72, 10, x.getLastName());
    printScreen(72, 12, x.getFirstName());
    printScreen(72, 14, x.getClass());
    goToxy(72, 16);
    cout << fixed << setprecision(1) << x.getMark();
}

Data Function::enterStudentId(Container& DataStructure) {
    while(true) {
        showCursor(true);

        Data data;
        bool exist = false;

        string _id = inputScreen(59, 7, 10, false);
        if(_id == "") return data;              

        switch(DataStructure.type) {
            case 1: {
                data.index = DataStructure.Array.search(_id);
                if(data.index != -1) exist = true;
                break;
            }
            case 2: {   
                data.nodes = DataStructure.Sll.search(_id);
                if(data.nodes != NULL) exist = true;
                break;
            }
            case 3: {
                data.nodec = DataStructure.Cll.search(_id);
                if(data.nodec != NULL) exist = true;
                break;
            }
            case 4: {
                data.noded = DataStructure.Dll.search(_id);
                if(data.noded != NULL) exist = true;
                break;
            }
        }

        if(exist == false) {                     
            showCursor(false);
            printRedBold(59, 7, "This student ID does not exist!");
            Sleep(2000);
            printScreen(59, 7, "                                  ");
        }
        else {             
            return data;
        }
    }
}

void Function::menuDelete(Container& DataStructure) {
    while(true) {
        Interface::enterStudentId();
        printScreen(54, 4, "ENTER STUDENT ID TO DELETE");

        Data data = Function::enterStudentId(DataStructure);

        if(data.empty()) {      
            return;
        }
        else {
            Interface::menuDelete();
            Student student;

            switch(DataStructure.type) {
                case 1: {
                    student = DataStructure.Array.head[data.index];
                    break;
                }
                case 2: {
                    student = data.nodes->data;
                    break;
                }
                case 3: {
                    student = data.nodec->data;
                    break;
                }
                case 4: {
                    student = data.noded->data;
                    break;
                }
            }
            printRedBold(70, 7, student.getId());
            printScreen(70, 9, student.getFirstName());
            printScreen(70, 11, student.getLastName());
            printScreen(70, 13, student.getClass());
            printScreen(70, 15, to_string(student.getMark()));

            char c = input(0, 0, 0, true);
            if(c == 't') {
                continue;
            }
            else {
                vector<Student> Students;
                switch(DataStructure.type) {
                    case 1: {
                        DataStructure.Array.deleteStudent(data.index);
                        Students = DataStructure.Array.allStudents();
                        break;
                    }
                    case 2: {
                        DataStructure.Sll.deleteStudent(data.nodes->data.getId());
                        Students = DataStructure.Sll.allStudents();
                        break;
                    }
                    case 3: {
                        DataStructure.Cll.deleteStudent(data.nodec->data.getId());
                        Students = DataStructure.Cll.allStudents();
                        break;
                    }
                    case 4: {
                        DataStructure.Dll.deleteStudent(data.noded->data.getId());
                        Students = DataStructure.Dll.allStudents();
                        break;
                    }
                }
                showCursor(false);
                Function::updateInformation(Students);
                Function::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
            }
        }
    }
}

void Function::menuAverageMark(Container& DataStructure) {
    showCursor(false);
    Interface::menuAverageMark();

    unordered_map<string, pair<int, float>> mp;
    vector<Student> Students;
    vector<Student> result;

    switch(DataStructure.type) {
        case 1: {
            Students = DataStructure.Array.allStudents(); 
            break;
        }
        case 2: {
            Students = DataStructure.Sll.allStudents(); 
            break;
        }
        case 3: {
            Students = DataStructure.Cll.allStudents(); 
            break;
        }
        case 4: {
            Students = DataStructure.Dll.allStudents(); 
            break;
        }
    }

    for(Student& x : Students) {
        string _cl = x.getClass();
        float _mark = x.getMark();
        mp[_cl].first += 1;
        mp[_cl].second += _mark;
    }

    int cnt = 0;
    for(auto& [x, y] : mp) {
        printScreen(5, 8 + cnt, x);
        printScreen(43, 8 + cnt, to_string(y.first));
        goToxy(82, 8 + cnt);
        cout << fixed << setprecision(2) << y.second / y.first; 
        cout << endl;
        if(cnt + 1 <= 27) cnt++;
    }

    char c = input(0, 0, 0, 0);
}

void Function::menuSort(Container& DataStructure) {
    switch(DataStructure.type) {
        case 1: {
            Function::menuSortingType(DataStructure.Array);
            break;
        }
        case 2: {
            Function::menuSortingType(DataStructure.Sll);
            break;
        }
        case 3: {
            Function::menuSortingType(DataStructure.Cll);
            break;
        }
        case 4: {
            Function::menuSortingType(DataStructure.Dll);
            break;
        }
    }
}

template<typename T>
void Function::menuSortingType(T& DataStructure) {
    while(true) {
        if(DataStructure.type == 2 || DataStructure.type == 3) {
            Interface::menuSort1();
            char c = operation(39, 10, 4);

            if(c == 't') {
                return;
            }
            else if(c == '1') {
                Function::menuSortingCriteria(DataStructure, 62, 4, "BUBBLE SORT", &T::bubbleSort, 1);
            }
            else if(c == '2') {
                Function::menuSortingCriteria(DataStructure,60, 4, "INSERTION SORT", &T::insertionSort, 2);
            }
            else if(c == '3') {
                Function::menuSortingCriteria(DataStructure, 60, 4, "SELECTION SORT", &T::selectionSort, 3);
            }
            else if(c == '4') {
                Function::menuSortingCriteria(DataStructure, 62, 4, "MERGE SORT", &T::mergeSort, 4);
            }
        }
        else {
            Interface::menuSort2();
            char c = operation(39, 10, 6);

            if(c == 't') {
                return;
            }
            else if(c == '1') {
                Function::menuSortingCriteria(DataStructure, 62, 4, "BUBBLE SORT", &T::bubbleSort, 1);
            }
            else if(c == '2') {
                Function::menuSortingCriteria(DataStructure, 60, 4, "INSERTION SORT", &T::insertionSort, 2);
            }
            else if(c == '3') {
                Function::menuSortingCriteria(DataStructure, 60, 4, "SELECTION SORT", &T::selectionSort, 3);
            }
            else if(c == '4') {
                Function::menuSortingCriteria(DataStructure, 62, 4, "MERGE SORT", &T::mergeSort, 4);
            }
            else if(c == '5') {
                Function::menuSortingCriteria(DataStructure, 60, 4, "QUICKSORT", &T::quickSort, 5);
            }
            else if(c == '6') {
                Function::menuSortingCriteria(DataStructure, 62, 4, "HEAPSORT", &T::heapSort, 6);
            }
        }
    }
}

template<typename T>
void Function::menuSortingCriteria(T& DataStructure, int x, int y, string s, void (T::*sort)(bool (*)(Student&, Student&)), int sorting_type) {
    bool sorted = false;
    microseconds duration;
    time_point<high_resolution_clock> start, end;

    while(true) {
        Interface::menuSortingCriteria();
        printScreen(x, y, s);

        char c = operation(39, 10, 5);

        if(c == 't') {
            return;
        }
        else if(c == '1') {
            sorted = true;
            DataStructure.isSorted = false;

            start = high_resolution_clock::now();
            (DataStructure.*sort)(sortById);
            end = high_resolution_clock::now();

            duration = duration_cast<microseconds>(end - start);

            Function::updateInformation(DataStructure.allStudents());
            Function::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
        }
        else if(c == '2') {
            sorted = true;
            DataStructure.isSorted = false;

            start = high_resolution_clock::now();
            (DataStructure.*sort)(sortByName);
            end = high_resolution_clock::now();

            duration = duration_cast<microseconds>(end - start);

            Function::updateInformation(DataStructure.allStudents());
            Function::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
        }
        else if(c == '3') {
            sorted = true;
            DataStructure.isSorted = true;          

            start = high_resolution_clock::now();
            (DataStructure.*sort)(sortByMark);
            end = high_resolution_clock::now();

            duration = duration_cast<microseconds>(end - start);
            
            Function::updateInformation(DataStructure.allStudents());
            Function::notification(52, 7, "-  THE OPERATION WAS SUCCESSFUL  -", 1000);
        }
        else if(c == '4') {
            if(sorted == true) {
                Function::note1(21);
                printScreen(8, 21, "Time taken for the search: ");
                Function::sortingAlgorithm(duration.count(), DataStructure.type, sorting_type);
                printScreen(110, 21, "Time complexity: O(n)");
            }
            else {
                Interface::notification();
                printAnimation(48, 7, 60, "PLEASE SELECT ONE OF THE SORTING CRITERIA");
                printAnimation(59, 8, 60, "BEFORE DISPLAYING!");
                Sleep(2000);
            }
        }
        else if(c == '5') {
            if(sorted == true) {
                Function::studentList(42, 2, DataStructure.allStudents(), false, "LIST OF SORTED STUDENTS", duration.count());
            }
            else {
                Interface::notification();
                printAnimation(48, 7, 60, "PLEASE SELECT ONE OF THE SORTING CRITERIA");
                printAnimation(59, 8, 60, "BEFORE DISPLAYING!");
                Sleep(2000);
            }
        }
    }
}

void Function::sortingAlgorithm(int duration, int dataType, int sortingType) {
    Interface::menuAlgorithm();
    printScreen(47, 4, "-   SORTING ALGORITHM PERFORMANCE SUMMARY    -");
    
    string time = to_string(duration) + "ms";

    switch(dataType) {
        case 1: {
            printAnimation(67, 10, 60, "Array");
            break;
        }
        case 2: {
            printAnimation(67, 10, 60, "Singly Linked List");
            break;
        }
        case 3: {
            printAnimation(67, 10, 60, "Circular Linked List");
            break;
        }
        case 4: {
            printAnimation(67, 10, 60, "Doubly Linked List");
            break;
        }
    }
    switch(sortingType) {
        case 1: {
            printAnimation(67, 12, 60, "Bubble Sort");
            printAnimation(67, 14, 60, "O(n^2)");
            printAnimation(67, 16, 60, time);
            printAnimation(67, 18, 60, "O(1)");
            break;
        }
        case 2: {
            printAnimation(67, 12, 60, "Insertion Sort");
            printAnimation(67, 14, 60, "O(n^2)");
            printAnimation(67, 16, 60, time);
            printAnimation(67, 18, 60, "O(1)");
            break;
        }
        case 3: {
            printAnimation(67, 12, 60, "Selection Sort");
            printAnimation(67, 14, 60, "O(n^2)");
            printAnimation(67, 16, 60, time);
            printAnimation(67, 18, 60, "O(1)");
            break;
        }
        case 4: {
            printAnimation(67, 12, 60, "Merge Sort");
            printAnimation(67, 14, 60, "O(n log n)");
            printAnimation(67, 16, 60, time);
            printAnimation(67, 18, 60, "O(n)");
            break;
        }
        case 5: {
            printAnimation(67, 12, 60, "Quick Sort");
            printAnimation(67, 14, 60, "O(n log n) average, O(n^2) worst");
            printAnimation(67, 16, 60, time);
            printAnimation(67, 18, 60, "O(log n)");
            break;
        }
        case 6: {
            printAnimation(67, 12, 60, "Heap Sort");
            if(dataType == 1) printAnimation(67, 14, 60, "O(n log n)");
            else printAnimation(67, 14, 60, "O(n^2 log n)  (O(n log n) on Array)");
            printAnimation(67, 16, 60, time);
            printAnimation(67, 18, 60, "O(1)");
            break;
        }
    }
    char c = input(0, 0, 0, 0);
}

void Function::menuSearch(Container& DataStructure) {
    switch(DataStructure.type) {
        case 1: {
            Function::menuSearching(DataStructure.Array);
            break;
        }
        case 2: {
            Function::menuSearching(DataStructure.Sll);
            break;
        }
        case 3: {
            Function::menuSearching(DataStructure.Cll);
            break;
        }
        case 4: {
            Function::menuSearching(DataStructure.Dll);
            break;
        }
    }
}

template<typename T>
void Function::menuSearching(T& DataStructure) {
    while(true) {
        showCursor(false);
        Interface::menuSearchByCriteria();
        char c = operation(39, 10, 5);

        if(c == 't') {          //tab
            return;
        }
        else {
            switch(c) {
                case '1' : {
                    Function::searching(DataStructure, searchById, sortById, 61, "SEARCH BY ID", 42, "Student ID",false);
                    break;
                }
                case '2' : {
                    Function::searching(DataStructure, searchByLastName, sortByLastName, 57, "SEARCH BY LAST NAME", 42, "Last name", false);
                    break;
                }
                case '3' : {
                    Function::searching(DataStructure, searchByFirstName, sortByFirstName, 57, "SEARCH BY FIRST NAME", 41, "First name", false);
                    break;
                }
                case '4' : {
                    Function::searching(DataStructure, searchByClass, sortByClass, 60, "SEARCH BY CLASS", 44, "Class", false);
                    break;
                }
                case '5' : {
                    Function::searching(DataStructure, searchByMark, sortByMark, 60, "SEARCH BY MARK", 45, "Mark", true);
                    break;
                }
            }
        }
    }
}

template<typename T>
void Function::searching(T& DataStructure, int(*searchBy)(Student&, string&), bool (*sortBy)(Student&, Student&), int x1, string s1, int x2, string s2, bool isMark) {
    while(true) {
        Interface::criteria();
        printScreen(x1, 4, s1);
        printScreen(x2, 7, s2);
        showCursor(true);

        Sorting res;
        string inputInformation = inputScreen(59, 7, 20, true);
        if(inputInformation == "") break;

        if(isMark == true) {
            if(checkMark(inputInformation) == false) {
                showCursor(false);
                printRedBold(59, 7, "Mark is invalid, please enter again!");
                Sleep(2000);
                printScreen(59, 7,"                                    ");
                continue;
            }
            inputInformation = to_string(stof(inputInformation));
        }

        res = Function::isSorted(DataStructure, searchBy, sortBy, inputInformation);
        
        if(res.list.empty()) {
            showCursor(false);
            printRedBold(59, 7, "This information does not exist!");
            Sleep(2000);
            printScreen(59, 7,"                                    ");
        }
        else {
            while(true) {
                showCursor(false);
                Interface::menuSearchingMethod();

                char c = operation(39, 10, 2);
                if(c == 't') break;

                switch(c) {
                    case '1' : {
                        Function::sectionsOfTheSearch(DataStructure, res, searchBy, inputInformation, 1);
                        break;
                    }
                    case '2' : {
                        if(DataStructure.type == 2 || DataStructure.type == 3) {
                            Function::notification(40, 7, "Binary search only applies to Array or Doubly Linked List!", 1000);
                        }
                        else if(res.sorted == false) {
                            Function::notification(44, 7, "The student list must be sorted in ascending order!", 1000);
                        }
                        else {
                            Function::sectionsOfTheSearch(DataStructure, res, searchBy, inputInformation, 2);
                        }
                    }
                }
            }
        }
    }
}

template<typename T>
Sorting Function::isSorted(T& DataStructure, int (*searchBy)(Student&, string&), bool (*sortBy)(Student&, Student&), string value) {
    Sorting res;

    if(DataStructure.type == 2 || DataStructure.type == 3) {
        res.sorted = false;
        res.list = DataStructure.bruteForceSearch(searchBy, value);
    }
    else {
        if(DataStructure.sorted(sortBy) == true) {
            res.sorted = true;
            res.list = DataStructure.binarySearch(searchBy, value);
        }
        else {
            res.sorted = false;
            res.list = DataStructure.bruteForceSearch(searchBy, value);
        }
    }
    return res;
}

template<typename T>
void Function::sectionsOfTheSearch(T& DataStructure, Sorting& res, int (*searchBy)(Student&, string&), string& value, int method) {
    showCursor(false);

    while(true) {
        Interface::sectionsOfTheSearch();
        printScreen(69, 4, value);

        auto start = high_resolution_clock::now();
        if(method == 2) {
            DataStructure.binarySearch(searchBy, value);
        }
        else if(method == 1) {
            DataStructure.bruteForceSearch(searchBy, value);
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        char c = operation(39, 10, 4);
        if(c == 't') return;

        switch(c) {
            case '1': {
                Function::studentList(50, 2, res.list, false, "LIST THE STUDENTS", duration.count());
                break;
            }
            case '2': {
                Function::studentList(46, 2, res.list, true, "LIST THE STUDENTS IN REVERSE ORDER", duration.count());
                break;
            }
            case '3': {
                Function::redStudentList(50, 2, DataStructure.allStudents(), "LIST THE STUDENTS", searchBy, value, duration.count());
                break;
            }
            case '4': {
                Function::note1(21);
                Function::searchingAlgorithm(duration.count(), DataStructure.type, method);
                break;
            }
        }
    }
}

void Function::searchingAlgorithm(int duration, int dataType, int searchingType) {
    Interface::menuAlgorithm();
    printScreen(46, 4, "-   SEARCHING ALGORITHM PERFORMANCE SUMMARY    -");
    
    string time = to_string(duration) + "ms";

    switch(dataType) {
        case 1: {
            printAnimation(67, 10, 60, "Array");
            break;
        }
        case 2: {
            printAnimation(67, 10, 60, "Singly Linked List");
            break;
        }
        case 3: {
            printAnimation(67, 10, 60, "Circular Linked List");
            break;
        }
        case 4: {
            printAnimation(67, 10, 60, "Doubly Linked List");
            break;
        }
    }
    switch(searchingType) {
        case 1: {
            printAnimation(67, 12, 60, "Brute Force Search");
            printAnimation(67, 14, 60, "O(n)");
            printAnimation(67, 16, 60, time);
            printAnimation(67, 18, 60, "O(1)");
            break;
        }
        case 2: {
            printAnimation(67, 12, 60, "Binary Search");
            printAnimation(67, 14, 60, "O(log n)");
            printAnimation(67, 16, 60, time);
            printAnimation(67, 18, 60, "O(1)");
            break;
        }
    }
    char c = input(0, 0, 0, 0);
}

void Function::menuListTheStudents(Container& DataStructure) {
    switch(DataStructure.type) {
        case 1: {
            Function::printListTheStudents(DataStructure.Array);
            break;
        }
        case 2: {
            Function::printListTheStudents(DataStructure.Sll);
            break;
        }
        case 3: {
            Function::printListTheStudents(DataStructure.Cll);
            break;
        }
        case 4: {
            Function::printListTheStudents(DataStructure.Dll);
            break;
        }
    }
}

template<typename T>
void Function::printListTheStudents(T& DataStructure) {
    while(true) {
        Interface::menuListByCriteria();

        microseconds duration;
        time_point<high_resolution_clock> start, end;
        vector<Student> Students;

        char c = operation(39, 10, 3);
        if(c == 't') return;

        switch(c) {
            case '1' : {
                start = high_resolution_clock::now();
                Students = DataStructure.allStudents();
                end = high_resolution_clock::now();
                duration = duration_cast<microseconds>(end - start);

                Function::studentList(51, 2, Students, false, "LIST THE STUDENTS", duration.count());
                break;
            }
            case '2' : {
                start = high_resolution_clock::now();
                Students = listWithLowestMark(DataStructure);
                end = high_resolution_clock::now();
                duration = duration_cast<microseconds>(end - start);

                Function::studentList(43, 2, Students, false, "LIST THE STUDENTS WITH THE LOWEST MARK", duration.count());
                break;
            }
            case '3' : {
                start = high_resolution_clock::now();
                Students = listWithHighestMark(DataStructure);
                end = high_resolution_clock::now();
                duration = duration_cast<microseconds>(end - start);

                Function::studentList(42, 2, Students, false, "LIST THE STUDENTS WITH THE HIGHEST MARK", duration.count());
                break;
            }
        }
    }
}

void Function::studentList(int x, int y, vector<Student> Students, bool converse, string s, int duration) {
    Interface::menuListTheStudents();
    printScreen(x, y, s);
    printScreen(21, 2, to_string(duration) + "ms");
    printList(Students, converse);
}

void Function::redStudentList(int x, int y, vector<Student> Students, string s, int (*searchBy)(Student&, string&), string& value, int duration) {
    Interface::menuListTheStudents();
    printScreen(x, y, s);
    printScreen(21, 2, to_string(duration) + "ms");
    printRedList(Students, searchBy, value);
}