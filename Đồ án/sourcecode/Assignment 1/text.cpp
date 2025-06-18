#include "Console.cpp"

int main() {
    Console con;
    Container a;
    vector<Student> b = Function::getInformation();

    con.dataStorageMethod(a, b);
}