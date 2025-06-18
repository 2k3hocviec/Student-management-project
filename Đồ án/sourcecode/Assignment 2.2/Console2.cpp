#include "Console2.h"

void Console2::startProgram() {
    BinaryTree BT;
    vector<Student> Students = Function2::getInformation();
    BT.store(Students);
    
    while(true) {
        showCursor(false);
        Interface2::menuBinaryTree();
        
        char c = operation(39, 10, 5);
        if(c == 't') break;

        switch(c) {
            case '1' : {
                Function2::menuAdd(BT);
                break;
            }
            case '2' : {
                Function2::menuDelete(BT);
                break;
            }
            case '3' : {
                Function2::menuTraverse(BT, 1);
                break;
            }
            case '4' : {
                Function2::menuTraverse(BT, 2);
                break;
            }
            case '5' : {
                Function2::menuList(BT);
                break;
            }
        }
    }
    showCursor(false);
    Function2::notification(55, 7, "- The program has ended! -", 90);
    printScreen(20, 20, " ");
}