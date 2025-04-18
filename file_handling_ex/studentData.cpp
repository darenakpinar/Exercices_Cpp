#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Define the Student class
class Student {
private:
    string name;
    int age;
    double grade;

public:
    // Constructor
    Student(string studentName, int studentAge, double studentGrade) {
        name = studentName;
        age = studentAge;
        grade = studentGrade;
    }

    // Function to display student information
    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
ASAD
    // Function to save student information to a file
    void saveToFile(ofstream &outFile) const {
        outFile << name << " " << age << " " << grade << endl;
    }

    // Static function to load a student from a file line
    static bool loadFromFile(ifstream &inFile, Student &student) {
        string studentName;
        int studentAge;
        double studentGrade;

        if (inFile >> studentName >> studentAge >> studentGrade) { // Read only if data is available
            student = Student(studentName, studentAge, studentGrade);
            return true; // Successfully loaded a student
        }
        return false; // No more students to load
    }
};

int main() {
    vector<Student> students; // Vector to store multiple students

    // Step 1: Load students from file at the start
    ifstream inFile("students.txt");
    if (inFile) {
        Student tempStudent("", 0, 0.0);
        while (Student::loadFromFile(inFile, tempStudent)) { // Load students safely
            students.push_back(tempStudent);
        }
        inFile.close();
        cout << "Students loaded from file successfully!" << endl;
    } else {
        cout << "No saved students found. Starting fresh!" << endl;
    }

    int choice;
    do {
        cout << "\n1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Save to File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) { // Input validation
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Ignore incorrect input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            // Add a new student
            string name;
            int age;
            double grade;

            cout << "Enter student's name: ";
            cin >> name;

            cout << "Enter student's age: ";
            while (!(cin >> age) || age <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid age. Please enter a positive number: ";
            }

            cout << "Enter student's grade: ";
            while (!(cin >> grade) || grade < 0 || grade > 100) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid grade. Please enter a number between 0 and 100: ";
            }

            students.emplace_back(name, age, grade);

        } else if (choice == 2) {
            // Display all students
            if (students.empty()) {
                cout << "No students available!" << endl;
            } else {
                for (const auto &student : students) {
                    student.displayInfo();
                }
            }

        } else if (choice == 3) {
            // Save students to a file
            ofstream outFile("students.txt", ios::out); // Overwrite existing file
            if (!outFile) {
                cout << "Error opening file!" << endl;
            } else {
                for (const auto &student : students) {
                    student.saveToFile(outFile);
                }
                cout << "Students saved to file successfully!" << endl;
            }
            outFile.close();

        } else if (choice == 4) {
            cout << "Exiting program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}


