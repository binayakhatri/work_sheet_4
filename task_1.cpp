#include <iostream>
using namespace std;

class Student {
private:
    int code;       // Student's identifier.
    int courses;    // Number of courses.
    float *grades;  // Allocate memory to store the grades in all courses.

public:
    // Constructor to initialize code, courses, and allocate memory for grades.
    Student(int studentCode = 0, int numCourses = 0) : code(studentCode), courses(numCourses) {
        grades = new float[courses];
    }

    // Destructor to free the allocated memory.
    ~Student() {
        delete[] grades;
    }

    // Overloaded input operator to read student data.
    friend istream &operator>>(istream &in, Student &s) {
        in >> s.code >> s.courses;
        s.grades = new float[s.courses];
        for (int i = 0; i < s.courses; ++i)
            in >> s.grades[i];
        return in;
    }

    // Compare the number of passed courses for two students.
    int operator>(const Student &other) const {
        int passedCourses1 = 0;
        int passedCourses2 = 0;

        for (int i = 0; i < courses; ++i) {
            if (grades[i] >= 2)
                passedCourses1++;
            if (other.grades[i] >= 2)
                passedCourses2++;
        }

        if (passedCourses1 > passedCourses2)
            return 1;
        else if (passedCourses2 > passedCourses1)
            return 2;
        else
            return 3;
    }

    // Disable the copy operation by making the copy constructor and assignment operator private.
private:
    Student(const Student &);
    Student &operator=(const Student &);
};

int main() {
    int i;
    Student s1, s2;

    cout << "Enter student 1 data (code, courses, grades): ";
    cin >> s1;

    cout << "Enter student 2 data (code, courses, grades): ";
    cin >> s2;

    i = (s1 > s2);

    if (i == 1)
        cout << "Student 1 has succeeded in more courses." << endl;
    else if (i == 2)
        cout << "Student 2 has succeeded in more courses." << endl;
    else
        cout << "Both students have succeeded in the same number of courses." << endl;

    return 0;
}

