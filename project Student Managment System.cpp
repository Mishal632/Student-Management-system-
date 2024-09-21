#include <iostream>
#include <vector>
using namespace std;
class Person {
protected:
    string name;
    int age;

public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAge(int a) {
        age = a;
    }
    int getAge() {
        return age;
    }
};
class Student : public Person {
private:
    int rollNo;

public:
    Student(string n, int a, int r) {
        name = n;
        age = a;
        rollNo = r;
    }

    void setRollNo(int r) {
        rollNo = r;
    }

    int getRollNo() {
        return rollNo;
    }

    void getData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

// Function to add a new student
void addNewStudent(vector<Student> &students) {
    string name;
    int age, rollNo;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Roll No: ";
    cin >> rollNo;

    // Add the new student to the vector
    students.push_back(Student(name, age, rollNo));
    cout << "Student Added Successfully!" << endl;
}

int main() {
    vector<Student> students;  // Vector to store student objects
    int op = 0;

    do {
        cout << "\n1. Add New Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> op;

        if (op == 1) {
            addNewStudent(students);
        } 
        else if (op == 2) {
            // Display all students 
            if (students.empty()) {
                cout << "No Students Available!" << endl;
            } else {
                for (int i = 0; i < students.size(); i++) {
                    students[i].getData();
                    cout << "------------------" << endl;
                }
            }
        }
        else if (op == 3) {
            // Search Student by Roll No
            int rollNo;
            bool found = false;
            cout << "Enter Roll No to Search: ";
            cin >> rollNo;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getRollNo() == rollNo) {
                    cout << "Student Found!" << endl;
                    students[i].getData();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student Not Found!" << endl;
            }
        } 
        else if (op == 4) {
            // Update Student by Roll No 
            int rollNo;
            bool found = false;
            cout << "Enter Roll No to Update: ";
            cin >> rollNo;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getRollNo() == rollNo) {
                    cout << "Enter New Name: ";
                    string newName;
                    cin >> newName;
                    students[i].setName(newName);

                    cout << "Enter New Age: ";
                    int newAge;
                    cin >> newAge;
                    students[i].setAge(newAge);

                    cout << "Student Updated Successfully!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student Not Found!" << endl;
            }
        } 
        else if (op == 5) {
            // Delete Student by Roll No using index-based loop
            int rollNo;
            bool found = false;
            cout << "Enter Roll No to Delete: ";
            cin >> rollNo;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getRollNo() == rollNo) {
                    students.erase(students.begin() + i);
                    cout << "Student Deleted Successfully!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student Not Found!" << endl;
            }
        } 
        else if (op == 6) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid Choice!" << endl;
        }
    } while (op != 6);

    return 0;
}