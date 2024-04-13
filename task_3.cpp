#include <iostream>
#include <string>
using namespace std;
class School {
private:
    string name;

public:
    // Constructor with school name
    School(const string& n) : name(n) {}

    // Function to display school information
    void show() const {
       cout << "School: " << name << endl;
    }
};

class Student {
private:
    string schoolName;
    string studentName;
    int studentCode;
    int numProgrammingCourses;
    int numNetworkCourses;

public:
    // Constructor with school name, student name, student code, and number of courses
    Student(const string& school, const string& name, int code, int progCourses, int netCourses)
        : schoolName(school), studentName(name), studentCode(code), numProgrammingCourses(progCourses), numNetworkCourses(netCourses) {}

    // Function to display student information
    void show() const {
        cout << "School: " << schoolName << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Student Code: " << studentCode << endl;
        cout << "Number of Programming courses: " << numProgrammingCourses <<endl;
        cout << "Number of Network courses: " << numNetworkCourses << endl;
    }
};

int main() {
    Student s("TBC", "Santosh", 100, 7, 8);
    s.show();

    return 0;
}
