#include <iostream>
#include <windows.h>
#include "Interface2.h"
using namespace std;

void Interface2::notification() {
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

void Interface2::menuBinaryTree() {
    system("cls");
    Sleep(300);
    cout << R"(
                                     __________________________________________________________
                                    |                                                          |
                                    |                        BINARY TREE                       |
                                    |__________________________________________________________|
                                    |           |                                              |
                                    |   OPTION  |                  FUNCTION                    |
                                    |___________|______________________________________________|
                                    |           |                                              |
                                    |    [1]    |   Add student                                |
                                    |           |                                              |
                                    |    [2]    |   Delete node by mark                        |
                                    |           |                                              |
                                    |    [3]    |   Traverse tree (recursive)                  |
                                    |           |                                              |
                                    |    [4]    |   Traverse tree (non-recursive)              |
                                    |           |                                              |
                                    |    [5]    |   List the students                          |
                                    |___________|______________________________________________|

                                                        Press 'Tab' to exit
    )";
}

void Interface2::menuAdd() {
    system("cls");
    Sleep(300);
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
                                    |  Student code    |   Enter Student ID:                   |
                                    |__________________|_______________________________________|
                                    |                  |                                       |
                                    |  Class code      |   Enter Class:                        |
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

void Interface2::menuConfirmAdd() {
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

void Interface2::menuDeleteByMark() {
    system("cls");
    cout << R"(
                                     __________________________________________________________ 
                                    |                                                          |
                                    |                   ENTER MARK TO DELETE                   |
                                    |__________________________________________________________|
                                    |                  |                                       |
                                    |       Mark       |  Enter:                               |
                                    |__________________|_______________________________________|

                                                         Press 'Tab' to back
    )";
}

void Interface2::menuTraverse() {
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
                                    |    [1]    |   Pre-Order Traversal                        |
                                    |           |                                              |
                                    |    [2]    |   In-Order Traversal                         |
                                    |           |                                              |
                                    |    [3]    |   Post-Order Traversal                       |
                                    |           |                                              |
                                    |    [4]    |   Display time complexity of the traversal   |
                                    |           |                                              |
                                    |    [5]    |   List the traversed students                |
                                    |___________|______________________________________________|

                                                        Press 'Tab' to exit
    )";
}

void note_1() {
    cout << R"(
       ___________________________________________________________________________________________________________________________
    )";
}

void Interface2::menuList() {
    system("cls");
    cout << R"(
                                                                                             Press 'Tab' to back
    _____________________________________________________________________________________________________________________

    No.               ID STUDENT                FULL NAME                           CLASS                         MARK   
    _____________________________________________________________________________________________________________________           
    )";    
} 

void Interface2::menuAlgorithm() {
    system("cls");
    cout << R"(
                                 _________________________________________________________________________
                                |                                                                         |
                                |             -   TRAVERSAL ALGORITHM PERFORMANCE SUMMARY    -            |
                                |_________________________________________________________________________|
                                |                                                                         |
                                |                           PERFORMANCE METRICS                           |
                                |_________________________________________________________________________|
                                |                               |                                         |
                                | [1] Algorithm Name            |                                         |
                                |                               |                                         |
                                | [2] Traversal Method          |                                         |
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