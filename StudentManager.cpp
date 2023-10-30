#include "BinarySearchTree.cpp"
// Lớp quản lý sinh viên
class StudentManager {
private:
    BinarySearchTree bst;

public:
    void readFromFile(string filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            int MSV;
            string name;
            int age;

            while (inFile >> MSV >>name>> age) {
                bst.insert(MSV, name, age);
            }

            inFile.close();
        }
    }

    void addStudent(int MSV, string name, int age) {
        TreeNode* existingStudent = bst.search(MSV);
        if (existingStudent != nullptr) {
            cout << "Student with MSV " << MSV << " already exists." << endl;
        } else {
            bst.insert(MSV, name, age);
        }
    }

    void removeStudent(int MSV) {
        TreeNode* existingStudent = bst.search(MSV);
        if (existingStudent != nullptr) {
            bst.remove(MSV);
            cout << "Student with MSV " << MSV << " has been removed." << endl;
        } else {
            cout << "Student with MSV " << MSV << " does not exist." << endl;
        }
    }

    void updateStudent(int MSV, string name, int age) {
        TreeNode* existingStudent = bst.search(MSV);
        if (existingStudent != nullptr) {
            existingStudent->name = name;
            existingStudent->age = age;
            cout << "Student with MSV " << MSV << " has been updated." << endl;
        } else {
            cout << "Student with MSV " << MSV << " does not exist." << endl;
        }
    }

    void findStudent(int MSV) {
        TreeNode* existingStudent = bst.search(MSV);
        if (existingStudent != nullptr) {
            cout << "Student found:" << endl;
            cout << "MSV: " << existingStudent->MSV << ", Name: " << existingStudent->name << ", Age: " << existingStudent->age << endl;
        } else {
            cout << "Student with MSV " << MSV << " does not exist." << endl;
        }
    }

    void displayAllStudents() {
        cout << "List of students:" << endl;
        bst.inOrder();
    }

    void saveToFile(string filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            bst.writeToFile(outFile);
            outFile.close();
            cout << "Data saved to file." << endl;
        } else {
            cout << "Error opening file." << endl;
        }
    }
};
