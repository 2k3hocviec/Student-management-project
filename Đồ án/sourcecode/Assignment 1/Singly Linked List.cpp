#include <iostream>
#include "Student.cpp"
using namespace std;

struct nodes {
Student data;
nodes* next;
};

class Singly_Linked_List {
private:
    nodes* makeNodes(Student data);
    nodes* makeMergeSort(nodes* head, bool (*sort_by)(Student&, Student&));
    nodes* merge(nodes* left, nodes* right, bool (*sort_by)(Student&, Student&));
    nodes* getMid(nodes* head);

public:
    const int type = 2;
    nodes* head;
    bool isSorted;

    Singly_Linked_List() : head(nullptr), isSorted(false) {}

    void insertStudent(Student data);
    void deleteStudent(string id);
    void store(vector<Student>& Students);
    vector<Student> allStudents();
    nodes* search(string id);

    vector<Student> bruteForceSearch(int (*condition) (Student&, string&), string& value);
    vector<Student> binarySearch(int (*condition) (Student&, string&), string& value);

    bool sorted(bool (*sort_by)(Student&, Student&));
    
    void bubbleSort(bool (*sort_by)(Student&, Student&));
    void insertionSort(bool (*sort_by)(Student&, Student&));
    void selectionSort(bool (*sort_by)(Student&, Student&));
    void mergeSort(bool (*sort_by)(Student&, Student&));
    void quickSort(bool (*sort_by)(Student&, Student&));
    void heapSort(bool (*sort_by)(Student&, Student&));
};


nodes* Singly_Linked_List::makeNodes(Student data) {
    nodes* p = new nodes;
    p->data = data;
    p->next = NULL;
    return p;
}

void Singly_Linked_List::insertStudent(Student data) {
    nodes* p = makeNodes(data);
    if(head == NULL) head = p;

    nodes* tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = p;
    return;
}

void Singly_Linked_List::deleteStudent(string id) {
    while (head != NULL && head->data.getId() == id) {
        nodes* delNode = head;
        head = head->next;
        delete delNode;
    }

    nodes* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data.getId() == id) {
            nodes* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
            break;
        } 
        else {
            temp = temp->next;
        }
    }
    return;
}

void Singly_Linked_List::store(vector<Student>& Students) {
    if(Students.size() == 0) return;
    
    head = makeNodes(Students[0]);
    nodes* p = head;

    for(int i = 1; i < Students.size(); i++) {
        nodes* tmp = makeNodes(Students[i]);
        p->next = tmp;
        p = p->next;
    }
    return;
}

vector<Student> Singly_Linked_List::allStudents() {
    vector<Student> Students;
    nodes* p = head;
    
    while(p != NULL) {
        Students.push_back(p->data);
        p = p->next;
    }
    return Students;
}

nodes* Singly_Linked_List::search(string id) {
    nodes* temp = head;
    while (temp != NULL) {
        if (temp->data.getId() == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

vector<Student> Singly_Linked_List::bruteForceSearch(int (*condition) (Student&, string& value), string& value) {
    vector<Student> res;
    nodes* temp = head;

    while (temp != NULL) {
        if (!condition(temp->data, value)) {
            res.push_back(temp->data);
        }
        temp = temp->next;
    }
    return res;
}

vector<Student> Singly_Linked_List::binarySearch(int (*condition) (Student&, string& value), string& value) {
    return {};
}

bool Singly_Linked_List::sorted(bool (*sort_by)(Student&, Student&)) { 
    if(head == NULL) return true;
    nodes* tmp = head;

    while(tmp->next != NULL) {
        if(sort_by(tmp->data, tmp->next->data) == false) {
            return false;
        }
        tmp = tmp->next;
    }
    return true;
}

void Singly_Linked_List::bubbleSort(bool (*sort_by)(Student&, Student&)) {
    for(nodes* cur = head; cur != NULL; cur = cur->next) {
        bool swapped = false;
        for(nodes* k = head; k->next != NULL; k = k->next) {
            if(sort_by(k->data, k->next->data) == false) {
                swap(k->data, k->next->data);
                swapped = true;
            }
        }
        if(swapped == false) return;
    }
}

void Singly_Linked_List::insertionSort(bool (*sort_by)(Student&, Student&)) {
    nodes* sorted = NULL;
    nodes* current = head;

    while (current != NULL) {
        nodes* nextNode = current->next;

        if (sorted == NULL || sort_by(current->data, sorted->data)) {
            current->next = sorted;
            sorted = current;
        } else {
            nodes* temp = sorted;
            while (temp->next != NULL && !sort_by(current->data, temp->next->data)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }
    head = sorted;
}

void Singly_Linked_List::selectionSort(bool (*sort_by)(Student&, Student&)) {
    for (nodes* i = head; i != NULL; i = i->next) {
        nodes* minnodes = i;
        for (nodes* j = i->next; j != NULL; j = j->next) {
            if (sort_by(j->data, minnodes->data)) {
                minnodes = j;
            }
        }
        if (minnodes != i) {
            swap(i->data, minnodes->data);
        }
    }
    return;
}

void Singly_Linked_List::mergeSort(bool (*sort_by)(Student&, Student&)) {
    this->head = makeMergeSort(this->head, sort_by);
}

nodes* Singly_Linked_List::makeMergeSort(nodes* head, bool (*sort_by)(Student&, Student&)) {
    if (head == NULL || head->next == NULL) return head;

    nodes* middle = getMid(head);
    nodes* nextToMiddle = middle->next;

    middle->next = NULL;

    nodes* left = makeMergeSort(head, sort_by);
    nodes* right = makeMergeSort(nextToMiddle, sort_by);
    return merge(left, right, sort_by);
}

nodes* Singly_Linked_List::merge(nodes* left, nodes* right, bool (*sort_by)(Student&, Student&)) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    nodes* result = NULL;

    if (sort_by(left->data, right->data)) {
        result = left;
        result->next = merge(left->next, right, sort_by);
    } else {
        result = right;
        result->next = merge(left, right->next, sort_by);
    }
    return result;
}

nodes* Singly_Linked_List::getMid(nodes* head) {
    if (head == NULL) return head;

    nodes* slow = head;
    nodes* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void Singly_Linked_List::quickSort(bool (*sort_by)(Student&, Student&)) {}

void Singly_Linked_List::heapSort(bool (*sort_by)(Student&, Student&)) {}

