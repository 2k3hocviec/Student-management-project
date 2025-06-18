#include "Interface.h"

void Interface::notification() {
    system("cls");
    cout << R"(
                                     _____________________________________________________________
                                    |                                                             |
                                    |                        NOTIFICATION                         |
                                    |                            ~oOo~                            |
                                    |                                                             |
                                    |                                                             |
                                    |                                                             |
                                    |_____________________________________________________________|
    )";   
}

void Interface::invalidInformation() {
    system("cls");
    Sleep(700);
    cout << R"(
                                              INVALID INFORMATION                          Press 'tab' to continue
_________________________________________________________________________________________________________________________

Class ID contains space                 Duplicate ID                INVALID ID (The ID must be formatted as 'NxxABCDxxx')
_________________________________________________________________________________________________________________________           
    )";                                                                                       
}

void Interface::notificationNote() {
    system("cls");
    cout << R"(
                                     _______________________________________________________________
                                    |                                                               |
                                    |                         NOTIFICATION                          |
                                    |                             ~oOo~                             |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |                                                               |
                                    |_______________________________________________________________|

                                                        Press 'Enter' to continue
    )";
}

void Interface::note1() {
    cout << R"(
       ___________________________________________________________________________________________________________________________
    )";
}

void Interface::dataStorageMethod() {
    system("cls");
    Sleep(400);
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |               DATA STORAGE METHOD SELECTION              |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                  METHOD                      |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Array                                      |
                                    |           |                                              |
                                    |    [2]    |   Singly linked list                         |
                                    |           |                                              |
                                    |    [3]    |   Circular linked list                       |
                                    |           |                                              |
                                    |    [4]    |   Doubly linked list                         |
                                    |___________|______________________________________________|
                                                        
                                                        Press 'Tab' to exit
    )";
}

void Interface::menuChoice() {
    system("cls");
    cout << R"(          
                                     __________________________________________________________           
                                    |                                                          |
                                    |                                                          |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                  FUNCTION                    |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Add new student                            |
                                    |           |                                              |
                                    |    [2]    |   Update information                         |
                                    |           |                                              |
                                    |    [3]    |   Delete student                             |
                                    |           |                                              |
                                    |    [4]    |   Calculate the class average score          |
                                    |           |                                              |
                                    |    [5]    |   Sort the list in ascending order           |
                                    |           |                                              |
                                    |    [6]    |   Search for students based on criteria      |                                    
                                    |           |                                              |
                                    |    [7]    |   List the students                          |                       
                                    |___________|______________________________________________|

                                                        Press 'Tab' to back
    )";                 
}

void Interface::menuAdd() {
    system("cls");
    cout << R"(                 
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                ADD NEW STUDENT INFORMATION               |
                                    |__________________________________________________________|
                                    |                  |                                       |
                                    |  Last name       |   Enter Last name:                    |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  First name      |   Enter First name:                   |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  Student ID      |   Enter Student ID:                   |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  Class ID        |   Enter Class:                        |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  Mark            |   Enter Mark                          |
                                    |__________________|_______________________________________|

                                                         Press 'Tab' to back


                                    Note:
                                    - The first and last name will be automatically formatted:
                                      + Each word is capitalized (first letter uppercase, the rest lowercase)
                                      + Words are separated by a single space
                                      Example: "Nguyen Huu Duy"
                                    
                                    - The class name will be formatted in ALL UPPERCASE letters.
                                      Example: "D23CQCN03"
    )";
}

void Interface::menuConfirmAdd() {
    system("cls");
    Sleep(300);
    cout << R"(                 
                                     __________________________________________________________ 
                                    |                                                          |
                                    |          SUCCESSFULLY ADDED STUDENT INFORMATION          |
                                    |__________________________________________________________|
                                    |                  |                                       |
                                    |  Last name       |                                       |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  First name      |                                       |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  Student ID      |                                       |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  Class ID        |                                       |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  Mark            |                                       |
                                    |__________________|_______________________________________|

                                                       Press 'Enter' to continue
    )";
}

void Interface::enterStudentId() {
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                                                          |
                                    |__________________________________________________________|
                                    |                  |                                       |
                                    |    Student ID    |                                       |
                                    |__________________|_______________________________________|

                                                         Press 'Tab' to back
    )";
}

void Interface::menuUpdate() {
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |               UPDATE STUDENT:                            |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |              FIELD TO UPDATE                 |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Last name:                                 |
                                    |           |                                              |
                                    |    [2]    |   First name:                                |
                                    |           |                                              |
                                    |    [3]    |   Class:                                     |
                                    |           |                                              |
                                    |    [4]    |   Mark:                                      |
                                    |___________|______________________________________________|

                                                         Press 'Tab' to back


                                    Note:
                                    - The first and last name will be automatically formatted:
                                      + Each word is capitalized (first letter uppercase, the rest lowercase)
                                      + Words are separated by a single space
                                      Example: "Nguyen Le Hoang Hoc"
                                    
                                    - The class name will be formatted in ALL UPPERCASE letters.
                                      Example: "D23CQCN03"                  
    )";
}

void Interface::menuDelete() {
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                       DELETE STUDENT                     |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Student ID:                                |
                                    |           |                                              |
                                    |    [2]    |   Last name:                                 |
                                    |           |                                              |
                                    |    [3]    |   First name:                                |
                                    |           |                                              |
                                    |    [4]    |   Class:                                     |
                                    |           |                                              |
                                    |    [5]    |   Mark:                                      |
                                    |___________|______________________________________________|

                                             Press 'enter' to delete, or 'tab' to back  
    )";
}

void Interface::criteria() {
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                                                          |
                                    |__________________________________________________________|
                                    |                  |                                       |
                                    |                  |  Enter:                               |
                                    |__________________|_______________________________________|

                                                         Press 'Tab' to back
    )";
}

void Interface::menuAverageMark() {
    system("cls");
    cout << R"(
                                         CALCULATE THE CLASS AVERAGE MARK                         Press 'Tab' to back
    _____________________________________________________________________________________________________________________

    CLASS                          NUMBER OF STUDENTS                        AVERAGE SCORE
    _____________________________________________________________________________________________________________________           
        )";                                                                     
}

void Interface::menuSort1(){
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                      SORTING METHOD                      |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                   METHOD                     |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Bubble sort                                |
                                    |           |                                              |
                                    |    [2]    |   Insertion sort                             |
                                    |           |                                              |
                                    |    [3]    |   Selection sort                             |
                                    |           |                                              |
                                    |    [4]    |   Merge sort                                 |
                                    |___________|______________________________________________|

                                                         Press 'Tab' to back
    )";
}

void Interface::menuSort2(){
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                      SORTING METHOD                      |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                   METHOD                     |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Bubble sort                                |
                                    |           |                                              |
                                    |    [2]    |   Insertion sort                             |
                                    |           |                                              |
                                    |    [3]    |   Selection sort                             |
                                    |           |                                              |
                                    |    [4]    |   Merge sort                                 |
                                    |           |                                              |
                                    |    [5]    |   Quicksort                                  |
                                    |           |                                              |
                                    |    [6]    |   Heapsort                                   |
                                    |___________|______________________________________________|
                                                         Press 'Tab' to back
    )";
}

void Interface::menuSortingCriteria(){
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                                                          |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                  CRITERIA                    |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Sort by Student ID                         |
                                    |           |                                              |
                                    |    [2]    |   Sort by Name                               |
                                    |           |                                              |
                                    |    [3]    |   Sort by Mark                               |
                                    |           |                                              |
                                    |    [4]    |   Display time complexity of the sorting     |
                                    |           |                                              |
                                    |    [5]    |   List the sorted students                   |
                                    |___________|______________________________________________|

                                                         Press 'Tab' to back
    )";
}

void Interface::menuSearchingMethod(){
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                     SEARCHING METHOD                     |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                   METHOD                     |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Brute Force Search                         |
                                    |           |                                              |
                                    |    [2]    |   Binary Search                              |
                                    |___________|______________________________________________|

                                                         Press 'Tab' to back
    )";
}

void Interface::menuSearchByCriteria() {
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                  SEARCH STUDENT BY CRITERIA              |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                 SEARCH BY                    |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Student ID                                 |
                                    |           |                                              |
                                    |    [2]    |   Last name                                  |
                                    |           |                                              |
                                    |    [3]    |   First name                                 |
                                    |           |                                              |
                                    |    [4]    |   Class                                      |
                                    |           |                                              |
                                    |    [5]    |   Mark                                       |
                                    |___________|______________________________________________|

                                                         Press 'Tab' to back                    
    )";
}

void Interface::sectionsOfTheSearch() {
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                    SEARCH BY:                            |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                 SECTION                      |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Display the list of found students         | 
                                    |           |                                              |
                                    |    [2]    |   Display found student in reverse order     |                                    
                                    |           |                                              |
                                    |    [3]    |   Highlight the found students in list       |
                                    |           |                                              |
                                    |    [4]    |   Display time complexity of the search      |
                                    |___________|______________________________________________|

                                                         Press 'Tab' to back
    )";
}

void Interface::menuListByCriteria() {
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                  LIST STUDENT BY CRITERIA                |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                 SEARCH BY                    |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   List the students                          |
                                    |           |                                              |
                                    |    [2]    |   List the students with the lowest score    |
                                    |           |                                              |
                                    |    [3]    |   List the students with the highest score   |
                                    |___________|______________________________________________|

                                                         Press 'Tab' to back
    )";
}

void Interface::menuListTheStudents() {
    system("cls");
    cout << R"(
    Execution Time: 0ms                                                                         Press 'Tab' to back
    _____________________________________________________________________________________________________________________

    No.               ID STUDENT                FULL NAME                           CLASS                         MARK   
    _____________________________________________________________________________________________________________________           
    )";                                                                                                     
}

void Interface::menuAlgorithm() {
    system("cls");
    cout << R"(
                                 _________________________________________________________________________
                                |                                                                         |
                                |                                                                         |
                                |_________________________________________________________________________|
                                |                                                                         |
                                |                           PERFORMANCE METRICS                           |
                                |_________________________________________________________________________|
                                |                               |                                         |
                                | [1] Storage Method            |                                         |
                                |                               |                                         |
                                | [2] Algorithm Name            |                                         |
                                |                               |                                         |
                                | [3] Time Complexity           |                                         |
                                |                               |                                         |
                                | [4] Execution Time            |                                         |
                                |                               |                                         |
                                | [5] Space Complexity          |                                         |
                                |_______________________________|_________________________________________|

                                                           Press 'Tab' to back
    )";
}