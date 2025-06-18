#include "Console.h"

void Console::startProgram() {
    showCursor(false);
    
    Container DataStructure;
    Error Information;
    vector<Student> Students = Function::getInformation();

    while(true) {
        Function::welcome();
        char c = input(0, 0, 0, true);

        if(c == 't') {                 
            break;  
        }           
        else if(c == 'e') {       
            Function::checkInformation();
            Information = Function::checkInformation(Students);

            if(Information.error == true) {
                Function::invalidInformation(Information);
            }
            else {
                Function::validInformation();
                Function::updateInformation(Students);

                while(true) {
                    char c = input(0, 0, 0, true);
                    if(c == 'e') {
                        Console::dataStorageMethod(DataStructure, Students);
                        break;
                    }
                }
            }
        }
        break;
    }
    Function::notification(55, 7, "- The program has ended! -", 90);
    printScreen(20, 20, "");
}

void Console::dataStorageMethod(Container& DataStructure, vector<Student>& Students){
    while(true) {
        Interface::dataStorageMethod();
        vector<Student> res;

        char c = operation(39, 10, 4);
        if(c == 't') return;

        switch(c) {
            case '1': {
                DataStructure.type = 1;
                DataStructure.Array.store(Students);
                DataStructure.Array.isSorted = DataStructure.Array.sorted(sortByMark);
                Console::menuMain(DataStructure);
                res = DataStructure.Array.allStudents();
                break;
            }
            case '2': {
                DataStructure.type = 2;
                DataStructure.Sll.store(Students);
                DataStructure.Sll.isSorted = DataStructure.Sll.sorted(sortByMark);
                Console::menuMain(DataStructure);
                res = DataStructure.Sll.allStudents();
                break;
            }
            case '3': {
                DataStructure.type = 3;
                DataStructure.Cll.store(Students);
                DataStructure.Cll.isSorted = DataStructure.Cll.sorted(sortByMark);
                Console::menuMain(DataStructure);
                res = DataStructure.Cll.allStudents();
                break;
            }
            case '4': {
                DataStructure.type = 4;
                DataStructure.Dll.store(Students);
                DataStructure.Dll.isSorted = DataStructure.Dll.sorted(sortByMark);
                Console::menuMain(DataStructure);
                res = DataStructure.Dll.allStudents();
                break;
            }
        }
        Students = res;
    }
}

void Console::menuMain(Container& DataStructure) {
    while(true) {
        Interface::menuChoice();

        switch(DataStructure.type) {
            case 1:
                printScreen(63, 4, "Array");
                break;
            case 2:
                printScreen(58, 4, "Singly Linked List");
                break;
            case 3:
                printScreen(57, 4, "Circular Linked List");
                break;
            case 4:
                printScreen(58, 4, "Doubly Linked List");
                break;
        }

        char c = operation(39, 10, 7);
        if(c == 't') return;

        switch(c) {
            case '1': {
                Function::menuAdd(DataStructure);
                break;
            }
            case '2': {
                Function::menuUpdate(DataStructure);
                break;
            }
            case '3': {
                Function::menuDelete(DataStructure);
                break;
            }
            case '4': {
                Function::menuAverageMark(DataStructure);
                break;
            }
            case '5': {
                Function::menuSort(DataStructure);
                break;
            }
            case '6': {
                Function::menuSearch(DataStructure);
                break;
            }
            case '7': {
                Function::menuListTheStudents(DataStructure);
                break;
            }
        }
    }
}