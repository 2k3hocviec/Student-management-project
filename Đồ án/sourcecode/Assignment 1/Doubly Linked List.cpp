#include <iostream>
#include "Student.cpp"
using namespace std;

struct noded {
    Student data;
    noded* left;
    noded* right;
};

class Doubly_Linked_List {
private:
    int length();
    noded* makeMergeSort(noded* head, bool (*sort_by)(Student&, Student&));
    noded* merge(noded* left, noded* right, bool (*sort_by)(Student&, Student&));
    noded* getMid(noded* head);
    noded* getTail(noded* start);
    noded* partition(noded* low, noded* high, bool (*sort_by)(Student&, Student&));
    void quickSortRecursive(noded* low, noded* high, bool (*sort_by)(Student&, Student&));
    void heapify(int n, int i, bool (*sort_by)(Student&, Student&));
    noded* getNodedAt(int index);
    void swapData(noded* a, noded* b);

public:
    const int type = 4;
    noded* head;
    bool isSorted;

    Doubly_Linked_List() : head(nullptr), isSorted(false) {}

    noded* makeNoded(Student data);
    void insertStudent(Student data);
    void deleteStudent(string id);
    void store(vector<Student>& Students);
    vector<Student> allStudents();
    noded* search(string id);

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






noded* Doubly_Linked_List::makeNoded(Student data) {
    noded* p = new noded;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void Doubly_Linked_List::insertStudent(Student data) {
    noded* p = makeNoded(data);
    if (head == NULL) {
        head = p;
    } else {
        noded* cur = head;
        while (cur->right != NULL) {
            cur = cur->right;
        }
        cur->right = p;
        p->left = cur;
    }
}

void Doubly_Linked_List::deleteStudent(string id) {
    noded* temp = head;

    while (temp != NULL) {
        if (temp->data.getId() == id) {
            if (temp == head) {
                head = temp->right;
                if (head != NULL) head->left = NULL;
            } else {
                if (temp->left != NULL) temp->left->right = temp->right;
                if (temp->right != NULL) temp->right->left = temp->left;
            }

            delete temp;
            break;
        }

        temp = temp->right;
    }
}

void Doubly_Linked_List::store(vector<Student>& Students) {
    if (Students.size() == 0) return;

    head = makeNoded(Students[0]);
    noded* p = head;
    for (int i = 1; i < Students.size(); i++) {
        noded* tmp = makeNoded(Students[i]);
        p->right = tmp;
        tmp->left = p;
        p = p->right;
    }
}

vector<Student> Doubly_Linked_List::allStudents() {
    vector<Student> Students;
    noded* p = head;
    while (p != NULL) {
        Students.push_back(p->data);
        p = p->right;
    }
    return Students;
}

noded* Doubly_Linked_List::search(string id) {
    noded* temp = head;
    while (temp != NULL) {
        if (temp->data.getId() == id) {
            return temp;
        }
        temp = temp->right;
    }
    return NULL;
}

vector<Student> Doubly_Linked_List::bruteForceSearch(int (*condition)(Student&, string&), string& value) {
    vector<Student> res;
    noded* temp = head;

    while (temp != NULL) {
        if (!condition(temp->data, value)) {
            res.push_back(temp->data);
        }
        temp = temp->right;
    }
    return res;
}

vector<Student> Doubly_Linked_List::binarySearch(int (*condition)(Student&, string&), string& value) {
    vector<Student> res;
    if(head == nullptr) return res;

    noded* left = head;
    noded* right = nullptr;

    auto get_mid = [](noded* start, noded* end) -> noded* {
        if (!start) return nullptr;
        noded* slow = start;
        noded* fast = start;
        while (fast != end && fast->right != end) {
            fast = fast->right;
            if (fast != end) {
                fast = fast->right;
                slow = slow->right;
            }
        }
        return slow;
    };

    noded* lower = nullptr;

    while (left != right) {
        noded* mid = get_mid(left, right);
        if (!mid) break;
    
        int compare = condition(mid->data, value);

        if(compare == 0) {
            lower = mid;
            right = mid;
        } else if(compare > 0) {
            right = mid;
        }
        else {
            left = mid->right;
        }
    }

    if (lower == nullptr) return res;

    noded* cur = lower;
    while (cur != nullptr && condition(cur->data, value) == 0) {
        res.push_back(cur->data);
        cur = cur->right;
    }
    return res;
}

bool Doubly_Linked_List::sorted(bool (*sort_by)(Student&, Student&)) { 
    if(head == NULL) return true;
    noded* tmp = head;

    while(tmp->right != NULL) {
        if(sort_by(tmp->data, tmp->right->data) == false) {
            return false;
        }
        tmp = tmp->right;
    }
    return true;
}

void Doubly_Linked_List::bubbleSort(bool (*sort_by)(Student&, Student&)) {
    if (head == nullptr) return;

    bool swapped;
    noded* end = nullptr;

    do {
        swapped = false;
        noded* cur = head;

        while (cur->right != end) {
            if (!sort_by(cur->data, cur->right->data)) {
                swap(cur->data, cur->right->data);
                swapped = true;
            }
            cur = cur->right;
        }

        end = cur;
    } while (swapped);
}

void Doubly_Linked_List::insertionSort(bool (*sort_by)(Student&, Student&)) {
    if (head == nullptr || head->right == nullptr) return;

    noded* sorted = nullptr;
    noded* cur = head;

    while (cur != nullptr) {
        noded* next = cur->right;

        cur->left = cur->right = nullptr;

        if (sorted == nullptr) {
            sorted = cur;
        }
        else if (sort_by(cur->data, sorted->data)) {
            cur->right = sorted;
            sorted->left = cur;
            sorted = cur;
        } else {
            noded* temp = sorted;
            while (temp->right != nullptr && !sort_by(cur->data, temp->right->data)) {
                temp = temp->right;
            }

            cur->right = temp->right;
            if (temp->right != nullptr)
                temp->right->left = cur;

            temp->right = cur;
            cur->left = temp;
        }

        cur = next;
    }

    head = sorted;
}

void Doubly_Linked_List::selectionSort(bool (*sort_by)(Student&, Student&)) {
    for (noded* i = head; i != nullptr; i = i->right) {
        noded* minnoded = i;
        for (noded* j = i->right; j != nullptr; j = j->right) {
            if (sort_by(j->data, minnoded->data)) {
                minnoded = j;
            }
        }

        if (minnoded != i) {
            swap(i->data, minnoded->data);
        }
    }
}

void Doubly_Linked_List::mergeSort(bool (*sort_by)(Student&, Student&)) {
    head = makeMergeSort(head, sort_by);
}

noded* Doubly_Linked_List::makeMergeSort(noded* head, bool (*sort_by)(Student&, Student&)) {
    if (head == nullptr || head->right == nullptr) return head;

    noded* middle = getMid(head);
    noded* nextToMiddle = middle->right;

    middle->right = nullptr;
    if (nextToMiddle != nullptr) nextToMiddle->left = nullptr;

    noded* left = makeMergeSort(head, sort_by);
    noded* right = makeMergeSort(nextToMiddle, sort_by);

    return merge(left, right, sort_by);
}

noded* Doubly_Linked_List::merge(noded* left, noded* right, bool (*sort_by)(Student&, Student&)) {
    if (!left) return right;
    if (!right) return left;

    noded* res = nullptr;

    if (sort_by(left->data, right->data)) {
        res = left;
        res->right = merge(left->right, right, sort_by);
        if (res->right != nullptr) res->right->left = res;
    } else {
        res = right;
        res->right = merge(left, right->right, sort_by);
        if (res->right != nullptr) res->right->left = res;
    }

    return res;
}

noded* Doubly_Linked_List::getMid(noded* head) {
    if (head == nullptr) return head;

    noded* slow = head;
    noded* fast = head->right;

    while (fast != nullptr && fast->right != nullptr) {
        slow = slow->right;
        fast = fast->right->right;
    }

    return slow;
}

void Doubly_Linked_List::quickSort(bool (*sort_by)(Student&, Student&)) {
    noded* tail = getTail(head);
    quickSortRecursive(head, tail, sort_by);
}

noded* Doubly_Linked_List::getTail(noded* start) {
    if (start == nullptr) return nullptr;
    while (start->right != nullptr) {
        start = start->right;
    }
    return start;
}

void Doubly_Linked_List::quickSortRecursive(noded* low, noded* high, bool (*sort_by)(Student&, Student&)) {
    if (high != nullptr && low != high && low != high->right) {
        noded* pivot = partition(low, high, sort_by);
        quickSortRecursive(low, pivot->left, sort_by);  
        quickSortRecursive(pivot->right, high, sort_by);
    }
}

noded* Doubly_Linked_List::partition(noded* low, noded* high, bool (*sort_by)(Student&, Student&)) {
    Student pivot = high->data;
    noded* i = low->left;

    for (noded* j = low; j != high; j = j->right) {
        if (sort_by(j->data, pivot)) {
            i = (i == nullptr) ? low : i->right;
            swap(i->data, j->data);
        }
    }

    i = (i == nullptr) ? low : i->right;
    swap(i->data, high->data);
    return i;
}

void Doubly_Linked_List::heapSort(bool (*sort_by)(Student&, Student&)) {
    int n = length();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i, sort_by);
    }

    for (int i = n - 1; i > 0; i--) {
        swapData(getNodedAt(0), getNodedAt(i));
        heapify(i, 0, sort_by);
    }
}

void Doubly_Linked_List::heapify(int n, int i, bool (*sort_by)(Student&, Student&)) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    noded* nodeLargest = getNodedAt(largest);
    noded* nodeLeft = (left < n) ? getNodedAt(left) : nullptr;
    noded* nodeRight = (right < n) ? getNodedAt(right) : nullptr;

    if (nodeLeft && !sort_by(nodeLeft->data, nodeLargest->data)) {
        largest = left;
        nodeLargest = nodeLeft;
    }

    if (nodeRight && !sort_by(nodeRight->data, nodeLargest->data)) {
        largest = right;
        nodeLargest = nodeRight;
    }

    if (largest != i) {
        swapData(getNodedAt(i), nodeLargest);
        heapify(n, largest, sort_by);
    }
}

int Doubly_Linked_List::length() {
    int n = 0;
    noded* p = head;
    while(p != NULL) {
        n++;
        p = p->right;
    }
    return n;
}

noded* Doubly_Linked_List::getNodedAt(int index) {
    noded* cur = head;
    int count = 0;
    while (cur != nullptr && count < index) {
        cur = cur->right;
        count++;
    }
    return cur;
}

void Doubly_Linked_List::swapData(noded* a, noded* b) {
    Student temp = a->data;
    a->data = b->data;
    b->data = temp;
}