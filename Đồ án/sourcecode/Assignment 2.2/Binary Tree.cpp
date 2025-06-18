#include <stack>
#include "../Assignment 1/Student.cpp"

struct treeNode {
    float key;  
    vector<Student> info; 

    treeNode* left;
    treeNode* right;

    treeNode(float k, Student& s)
        : key(k), info{ s }, left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:

public:
    treeNode* root;

    BinaryTree() : root(nullptr) {}

    void insertStudent(Student& s) {
        inserting(root, s);
    }

    void inserting(treeNode*& node, Student& s) {
        if (node == nullptr) {
            node = new treeNode(s.getMark(), s);
            return;
        }
        if (s.getMark() < node->key)
            inserting(node->left, s);
        else if (s.getMark() > node->key)
            inserting(node->right, s);
        else
            node->info.push_back(s);
    }

    void store(vector<Student>& Students) {
        for(Student& student : Students) {
            insertStudent(student);
        }
    }

    void remove(float key) {
        removing(root, key);
    }

    void removing(treeNode*& node, float key) {
        if (node == nullptr) return;

        if (key < node->key)
            removing(node->left, key);
        else if (key > node->key)
            removing(node->right, key);
        else {
            if (node->left == nullptr) {
                treeNode* right = node->right;
                delete node;
                node = right;
            }
            else if (node->right == nullptr) {
                treeNode* left = node->left;
                delete node;
                node = left;
            }
            else {
                treeNode* minRight = findMin(node->right);
                node->key = minRight->key;
                node->info = minRight->info;
                removing(node->right, minRight->key);
            }
        }
    }

    bool search(float mark) {
        return searching(root, mark);
    }

    bool searching(treeNode* node, float mark) {
        if (node == nullptr) return false;

        if (mark < node->key)
            return searching(node->left, mark);
        else if (mark > node->key)
            return searching(node->right, mark);
        else
            return true;  // mark == node->key
    }



    treeNode* findMin(treeNode* node) {
        while (node != nullptr && node->left)
            node = node->left;
        return node;
    }

    vector<vector<Student>> traversal(int& type) {
        vector<vector<Student>> Students;
        traversing(root, type, Students);
        return Students;
    }

    void traversing(treeNode* node, int& type, vector<vector<Student>>& Students) {
        if (node == nullptr) return;
        if (type == 1) {
            Students.push_back(node->info);
            traversing(node->left, type, Students);
            traversing(node->right, type, Students);
        }
        else if (type == 2) {
            traversing(node->left, type, Students);
            Students.push_back(node->info);
            traversing(node->right, type, Students);
        }
        else if(type == 3) {
            traversing(node->left, type, Students);
            traversing(node->right, type, Students);
            Students.push_back(node->info);
        }
    }

    vector<vector<Student>> iterativePreOrder() {
        vector<vector<Student>> result;
        if (root == nullptr) return result;

        stack<treeNode*> s;
        s.push(root);

        while (!s.empty()) {
            treeNode* current = s.top(); s.pop();
            result.push_back(current->info);

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
        return result;
    }

    vector<vector<Student>> iterativeInOrder() {
        stack<treeNode*> s;
        treeNode* current = root;
        vector<vector<Student>> result;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top(); s.pop();
            result.push_back(current->info);
            current = current->right;
        }
        return result;
    }

    vector<vector<Student>> iterativePostOrder() {
        vector<vector<Student>> result;
        if (root == nullptr) return result;

        stack<treeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            treeNode* current = s1.top(); s1.pop();
            s2.push(current);

            if (current->left) s1.push(current->left);
            if (current->right) s1.push(current->right);
        }

        while (!s2.empty()) {
            treeNode* node = s2.top(); s2.pop();
            result.push_back(node->info);
        }
        return result;
    }
};