#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct student {
    string name;
    int age;
    int iD;
    int grade;
};

vector<student> s;
int n;

// دالة التصنيف
void classification(int grade) {
    if (grade >= 85)
        cout << "Classification: Excellent\n";
    else if (grade >= 70)
        cout << "Classification: Good\n";
    else if (grade >= 60)
        cout << "Classification: Pass\n";
    else
        cout << "Classification: Fail\n";
}


void adds() {
    student temp;

    cout << "Enter ID (0 to stop): ";
    cin >> temp.iD;
    if (temp.iD == 0)
        return;

    cin.ignore();
    cout << "Enter name: ";
    getline(cin, temp.name);

    cout << "Enter age: ";
    cin >> temp.age;

    cout << "Enter grade: ";
    cin >> temp.grade;

    s.push_back(temp);
    cout << "Student added successfully!\n\n";
}


void display() {
    if (s.empty()) {
        cout << "No students stored.\n";
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        cout << "\nStudent details\n";
        cout << "ID: " << s[i].iD << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Age: " << s[i].age << endl;
        cout << "Grade: " << s[i].grade << endl;
        classification(s[i].grade);
    }
}
void averageGrade() {
    if (s.empty()) {
        cout << "No students to calculate average.\n";
        return;
    }

    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i].grade;
    }

    double avg = (double)sum / s.size();
    cout << "Average Grade = " << avg << endl;
}


int main() {

    cout << "Student Management System\n";

    while (true) {
        cout << "\n1. Add student information";
        cout << "\n2. View all student records";
        cout << "\n3. Calculate average grade";
        cout << "\n4. Exit the program\n";
        cout << "Enter your choice: ";

        cin >> n;

        switch (n) {
        case 1:
            adds();
            break;
        case 2:
            display();
            break;
        case 3:
            averageGrade();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
