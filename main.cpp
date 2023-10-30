#include "StudentManager.cpp"

int main() {
    StudentManager manager;
    cout<<"\n\n\t\t==============================\n";
    // Đọc danh sách sinh viên từ tệp
    manager.readFromFile("students.txt");

    // Thêm sinh viên
    manager.addStudent(109, "Cao-Thi-Yen", 20);
    manager.addStudent(110, "Bao-Anh", 20);
    

    // Xóa sinh viên
    manager.removeStudent(101);

    // Cập nhật sinh viên
    manager.updateStudent(111, "Tran Duc Bo", 21);

    // Tìm kiếm sinh viên
    manager.findStudent(104);

    // Hiển thị danh sách sinh viên
    manager.displayAllStudents();

    // Lưu danh sách sinh viên vào tệp
    manager.saveToFile("updated_students.txt");
    cout<<"\t\t==============================";
    return 0;
}
