#include <iostream>
#include "Student.cpp"
using namespace std;

class Array {
private:
    static const int MAX = 1000;
    int size();

    void makeMergeSort(int left, int right, bool (*sort_by)(Student&, Student&));
    void merge(int left, int mid, int right, bool (*sort_by)(Student&, Student&));
    void quickSortRecursive(int low, int high, bool (*sort_by)(Student&, Student&));
    int partition(int low, int high, bool (*sort_by)(Student&, Student&));
    void heapify(int n, int i, bool (*sort_by)(Student&, Student&));

public:
    const int type = 1;
    Student head[MAX];
    int index;
    bool isSorted;

    Array() : index(0), isSorted(false) {}

    void insertStudent(Student x);
    void deleteStudent(int x);
    void store(vector<Student>& Students);
    vector<Student> allStudents();
    int search(string id);

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





int Array::size() {
    return index;
}

void Array::insertStudent(Student x) {
    if (index < MAX) {
        head[index++] = x;
    }
}

void Array::deleteStudent(int x) {
    for (int i = x; i < index - 1; ++i) {
        head[i] = head[i + 1];
    }
    index--;
}

void Array::store(vector<Student>& Students) {  
    index = 0;
    for(int i = 0; i < Students.size(); i++) {
        head[index++] = Students[i];
    }
}

vector<Student> Array::allStudents() {
    vector<Student> Students;
    for(int i = 0; i < index; i++) {
        Students.push_back(head[i]);
    }
    return Students;
}

int Array::search(string id) {
    for(int i = 0; i < index; i++) {    
        if(head[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

vector<Student> Array::bruteForceSearch(int (*condition)(Student&, string&), string& value) {
    vector<Student> res;
    for (int i = 0; i < index; ++i) {
        if (!condition(head[i], value)) {
            res.push_back(head[i]); 
        }
    }
    return res;
}

vector<Student> Array::binarySearch(int (*condition)(Student&, string&), string& value) {
    vector<Student> res;

    int left = 0;
    int right = index - 1;
    int lower = -1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        int compare = condition(head[mid], value);

        if(compare == 0) {
            lower = mid;
            right = mid - 1;
        }
        else if(compare == 1) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (lower == -1) return res;

    for (int i = lower; i <= index && condition(head[i], value) == 0; ++i) {
        res.push_back(head[i]);
    }
    return res;
}

bool Array::sorted(bool (*sort_by)(Student&, Student&)) {
    for(int i = 0; i < index - 1; i++) {
        if(sort_by(head[i], head[i + 1]) == false) {
            return false;
        }
    }
    return true;
}

void Array::bubbleSort(bool (*sort_by)(Student&, Student&)) {
    for (int i = 0; i < index - 1; ++i) {
        for (int j = 0; j < index - i - 1; ++j) {
            if (!sort_by(head[j], head[j + 1])) {
                swap(head[j], head[j + 1]);
            }
        }
    }
}

void Array::insertionSort(bool (*sort_by)(Student&, Student&)) {
    for (int i = 1; i < index; ++i) {
        Student Students = head[i];
        int j = i - 1;
        while (j >= 0 && !sort_by(head[j], Students)) {
            head[j + 1] = head[j];
            j--;
        }
        head[j + 1] = Students;
    }
}

void Array::selectionSort(bool (*sort_by)(Student&, Student&)) {
    for (int i = 0; i < index - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < index; ++j) {
            if (sort_by(head[j], head[min_idx])) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(head[i], head[min_idx]);
        }
    }
}

void Array::mergeSort(bool (*sort_by)(Student&, Student&)) {
    makeMergeSort(0, index - 1, sort_by);
}

void Array::makeMergeSort(int left, int right, bool (*sort_by)(Student&, Student&)) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    makeMergeSort(left, mid, sort_by);
    makeMergeSort(mid + 1, right, sort_by);
    merge(left, mid, right, sort_by);
}

void Array::merge(int left, int mid, int right, bool (*sort_by)(Student&, Student&)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student* L = new Student[n1];
    Student* R = new Student[n2];

    for (int i = 0; i < n1; ++i) L[i] = head[left + i];
    for (int i = 0; i < n2; ++i) R[i] = head[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (sort_by(L[i], R[j])) {
            head[k++] = L[i++];
        }
        else {
            head[k++] = R[j++];
        }
    }

    while (i < n1) head[k++] = L[i++];
    while (j < n2) head[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void Array::quickSort(bool (*sort_by)(Student&, Student&)) {
    quickSortRecursive(0, index - 1, sort_by);
}

void Array::quickSortRecursive(int low, int high, bool (*sort_by)(Student&, Student&)) {
    if (low < high) {
        int pivot = partition(low, high, sort_by);
        quickSortRecursive(low, pivot - 1, sort_by);
        quickSortRecursive(pivot + 1, high, sort_by);
    }
}

int Array::partition(int low, int high, bool (*sort_by)(Student&, Student&)) {
    Student pivot = head[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (sort_by(head[j], pivot)) {
            ++i;
            swap(head[i], head[j]);
        }
    }

    swap(head[i + 1], head[high]);
    return i + 1;
}

void Array::heapSort(bool (*sort_by)(Student&, Student&)) {
    for (int i = index / 2 - 1; i >= 0; --i) {
        heapify(index, i, sort_by);
    }

    for (int i = index - 1; i > 0; --i) {
        swap(head[0], head[i]);
        heapify(i, 0, sort_by);
    }
}

void Array::heapify(int n, int i, bool (*sort_by)(Student&, Student&)) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && !sort_by(head[left], head[largest])) {
        largest = left;
    }

    if (right < n && !sort_by(head[right], head[largest])) {
        largest = right;
    }

    if (largest != i) {
        swap(head[i], head[largest]);
        heapify(n, largest, sort_by);
    }
} 