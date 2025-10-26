#include <iostream>
#include <string>

using namespace std;

struct Student {
    string rollNumber;
    string name;
    string fatherName;
    string department;
    string degree;
    Student* next; // Pointer to the next student record in case of collision
};

class StudentManagementSystem {
private:
    static const int TABLE_SIZE = 100; 
    Student** hashTable; 

    
    int hashFunction(const string& rollNumber) {
        int year = stoi(rollNumber.substr(0, 2)); 
        return year % TABLE_SIZE; 
    }

public:
    StudentManagementSystem() {
        hashTable = new Student*[TABLE_SIZE](); 
    }
    void insertStudentRecord(const string& rollNumber, const string& name, const string& fatherName, const string& department, const string& degree) {
        int index = hashFunction(rollNumber);
        Student* newStudent = new Student();
        newStudent->rollNumber = rollNumber;
        newStudent->name = name;
        newStudent->fatherName = fatherName;
        newStudent->department = department;
        newStudent->degree = degree;
        newStudent->next = nullptr;
        if (hashTable[index] == nullptr) {
            hashTable[index] = newStudent;
        } else { 
            Student* current = hashTable[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStudent;
        }
    }
    Student* getStudentRecord(const string& rollNumber) {
        int index = hashFunction(rollNumber);
        Student* current = hashTable[index];
        while (current != nullptr) {
            if (current->rollNumber == rollNumber) {
                return current;
            }
            current = current->next;
        }
        return nullptr; 
    }
    ~StudentManagementSystem() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Student* current = hashTable[i];
            while (current != nullptr) {
                Student* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] hashTable;
    }
};

int main() {
    StudentManagementSystem system;
    system.insertStudentRecord("23;p-+P-1234", "John Doe", "Doe Sr.", "Computer Science", "BSc");
    system.insertStudentRecord("24P-5678", "Alice Smith", "Smith Sr.", "Electrical Engineering", "BEng");
    system.insertStudentRecord("25P-9876", "Bob Johnson", "Johnson Sr.", "Mechanical Engineering", "BEng");

    Student* student1 = system.getStudentRecord("23P-1234");
    if (student1 != nullptr) {
        cout << "Student 1: " << student1->name << ", Department: " << student1->department << endl;
    } else {
        cout << "Student not found." << endl;
    }

    Student* student2 = system.getStudentRecord("25P-9876");
    if (student2 != nullptr) {
        cout << "Student 2: " << student2->name << ", Department: " << student2->department << endl;
    } else {
        cout << "Student not found." << endl;
    }

    return 0;
}
