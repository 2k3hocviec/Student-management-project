#include <iostream>
#include "Array.cpp"
#include "Singly Linked List.cpp"
#include "Doubly Linked List.cpp"
#include "Circular Linked List.cpp"
using namespace std;

class Container {
private:
public:
    int type;
    Array Array;
    Singly_Linked_List Sll;
    Doubly_Linked_List Dll;
    Circular_Linked_List Cll;
    Container() : type(0), Array(), Sll(), Dll(), Cll() {}
};