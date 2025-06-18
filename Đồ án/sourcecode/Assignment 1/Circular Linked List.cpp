#include <iostream>
#include "Student.cpp"
using namespace std;


struct nodec {
    Student data;
    nodec* next;
};

class Circular_Linked_List {
private:
    nodec* makeMergeSort(nodec* head, bool (*sort_by)(Student&, Student&));
    nodec* merge(nodec* left, nodec* right, bool (*sort_by)(Student&, Student&));
    nodec* getMid(nodec* head);

public:
    const int type = 3;
    nodec* head;
    bool isSorted;

    Circular_Linked_List() : head(nullptr), isSorted(false) {}
 
    nodec* makeNodec(Student data);
    void insertStudent(Student data);
    void deleteStudent(string id);
    void store(vector<Student>& Students);
    vector<Student> allStudents();
    nodec* search(string id);

    vector<Student> bruteForceSearch(int (*condition)(Student&, string&), string& value);
    vector<Student> binarySearch(int (*condition)(Student&, string&), string& value);

    bool sorted(bool (*sort_by)(Student&, Student&));
    
    void bubbleSort(bool (*sort_by)(Student&, Student&));
    void insertionSort(bool (*sort_by)(Student&, Student&));
    void selectionSort(bool (*sort_by)(Student&, Student&));
    void mergeSort(bool (*sort_by)(Student&, Student&));
    void quickSort(bool (*sort_by)(Student&, Student&));
    void heapSort(bool (*sort_by)(Student&, Student&));
};





nodec* Circular_Linked_List::makeNodec(Student data) {
    nodec* p = new nodec;
    p->data = data;
    p->next = NULL;
    return p;
}

void Circular_Linked_List::insertStudent(Student data) {
    nodec* p = makeNodec(data);

    if(head == NULL) {
        head = p;
        p->next = head;
    }
    else {
        nodec* temp = head;
        while (temp -> next != head){
            temp = temp -> next;
        }
        temp->next = p;
        p->next = head;
    }
}

void Circular_Linked_List::deleteStudent(string id) {
    if (head == NULL) return;

    nodec* cur = head;
    nodec* prev = NULL;

    do {
        if (cur->data.getId() == id) {
            if (cur == head) {
                if (head->next == head) {
                    delete head;
                    head = NULL;
                    return;
                }
                nodec* last = head;
                while (last->next != head) last = last->next;
                last->next = head->next;
                nodec* delnodec = head;
                head = head->next;
                delete delnodec;
                cur = head;
                
                return;
            } else {
                prev->next = cur->next;
                delete cur;
                return;
            }
        }
        prev = cur;
        cur = cur->next;
    } while (cur != head);
}

void Circular_Linked_List::store(vector<Student>& Students) {
    if(Students.size() == 0) return;
    
    head = makeNodec(Students[0]);
    nodec* p = head;

    for(int i = 1; i < Students.size(); i++) {
        nodec* tmp = makeNodec(Students[i]);
        p->next = tmp;
        p = p->next;
    }
    p->next = head;
}

vector<Student> Circular_Linked_List::allStudents() {
    vector<Student> Students;
    if (head == NULL) return Students;

    nodec* p = head;
    do{
        Students.push_back(p->data);
        p = p->next;
    }while (p != head);

    return Students;
}

nodec* Circular_Linked_List::search(string id) {
    if (head == NULL) return NULL;
    nodec* temp = head;
    do {
        if (temp->data.getId() == id) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

vector<Student> Circular_Linked_List::bruteForceSearch(int (*condition) (Student&, string& value), string& value) {
    vector<Student> res;
    if (head == NULL) return res;
    nodec* temp = head;
    do {
        if (!condition(temp->data, value)) {
            res.push_back(temp->data);
        }
        temp = temp->next;
    } while (temp != head);
    return res;
}

vector<Student> Circular_Linked_List::binarySearch(int (*condition) (Student&, string& value), string& value) {
    return {};
}

bool Circular_Linked_List::sorted(bool (*sort_by)(Student&, Student&)) { 
    if(head == NULL) return true;
    nodec* tmp = head;

    while(tmp->next != head) {
        if(sort_by(tmp->data, tmp->next->data) == false) return false;
        tmp = tmp->next;
    }
    return true;
}

void Circular_Linked_List::bubbleSort(bool (*sort_by)(Student&, Student&)) {
    if (head == NULL || head->next == head) return; 

    bool swapped;
    nodec* last = NULL;
    do {
        swapped = false;
        nodec* cur = head;
        do {
            nodec* next = cur->next;
            
            if (next == head || next == last) break;
            if (!sort_by(cur->data, next->data)) {
                swap(cur->data, next->data);
                swapped = true;
            }
            cur = cur->next;
        } while (cur->next != head && cur->next != last);
        last = cur; 
    } while (swapped);
}

void Circular_Linked_List::insertionSort(bool (*sort_by)(Student&, Student&)) {
    if (head == NULL || head->next == head) return;

    nodec* sorted = NULL;
    nodec* cur = head;

    nodec* last = head;
    while (last->next != head) last = last->next;
    last->next = NULL;

    while (cur != NULL) {
        nodec* next = cur->next;
        if (sorted == NULL || sort_by(cur->data, sorted->data)) {
            cur->next = sorted;
            sorted = cur;
        } else {
            nodec* temp = sorted;
            while (temp->next != NULL && !sort_by(cur->data, temp->next->data)) {
                temp = temp->next;
            }
            cur->next = temp->next;
            temp->next = cur;
        }
        cur = next;
    }

    head = sorted;
    nodec* tail = head;
    while (tail->next != NULL) tail = tail->next;
    tail->next = head;
}

void Circular_Linked_List::selectionSort(bool (*sort_by)(Student&, Student&)) {
    if (head == NULL || head->next == head) return;

    nodec* i = head;
    do {
        nodec* minnodec = i;
        nodec* j = i->next;
        while (j != head) {
            if (sort_by(j->data, minnodec->data)) {
                minnodec = j;
            }
            j = j->next;
        }
        if (minnodec != i) {
            swap(i->data, minnodec->data);
        }
        i = i->next;
    } while (i != head);
}

void Circular_Linked_List::mergeSort(bool (*sort_by)(Student&, Student&)) {
    if (head == NULL || head->next == head) return;

    nodec* last = head;
    while (last->next != head) last = last->next;
    last->next = NULL;

    head = makeMergeSort(head, sort_by);

    nodec* tail = head;
    if (tail != NULL) {
        while (tail->next != NULL) tail = tail->next;
        tail->next = head;
    }
}

nodec* Circular_Linked_List::makeMergeSort(nodec* head, bool (*sort_by)(Student&, Student&)) {
    if (head == NULL || head->next == NULL) return head;

    nodec* middle = getMid(head);
    nodec* nextToMiddle = middle->next;
    middle->next = NULL;

    nodec* left = makeMergeSort(head, sort_by);
    nodec* right = makeMergeSort(nextToMiddle, sort_by);
    return merge(left, right, sort_by);
}

nodec* Circular_Linked_List::merge(nodec* left, nodec* right, bool (*sort_by)(Student&, Student&)) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    nodec* result = NULL;
    if (sort_by(left->data, right->data)) {
        result = left;
        result->next = merge(left->next, right, sort_by);
    } else {
        result = right;
        result->next = merge(left, right->next, sort_by);
    }
    return result;
}

nodec* Circular_Linked_List::getMid(nodec* head) {
    if (head == NULL) return head;

    nodec* slow = head;
    nodec* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void Circular_Linked_List::quickSort(bool (*sort_by)(Student&, Student&)) {}

void Circular_Linked_List::heapSort(bool (*sort_by)(Student&, Student&)) {}