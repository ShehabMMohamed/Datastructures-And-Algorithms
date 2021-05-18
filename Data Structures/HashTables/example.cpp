#include "HashTable.h"

// Example of a Student struct to create a StudentTable.
struct Student {
    int ID;
    string name;
    double GPA;
    Student() : ID(0), name("N/A"), GPA(0.0) {}
    Student(int ID, string name, double GPA) : ID(ID), name(name), GPA(GPA) {}
    friend ostream& operator<<(ostream &out, Student student);
};
ostream& operator<<(ostream &out, Student student) {
    out<<"ID: "<<student.ID<<", Name: "<<student.name<<", GPA: "<<student.GPA;
    return out;
}


int main() {
    // Example 1.
    HashTable<string, Student> StudentTable(6);
    
    Student studentList[] = {
        Student(90012, "Omar", 3.43), Student(90013, "Mai", 3.56),
        Student(90010, "Maged", 3.78), Student(90011, "Rana", 3.12)
    };
    
    for(Student student : studentList) {
        StudentTable.Insert(student.name, student);
    }
    
    // Delete example.
    StudentTable.DisplayTable();
    StudentTable.Delete("Omar");
    StudentTable.Delete("Shehab");
    StudentTable.DisplayTable();
    
    // Uncomment for Search example.
//    string searchName = "Mai";
//    Student result = StudentTable.Get(searchName);
//    cout<<"Result After querying with ID: "<<searchName<<endl;
//    cout<<"Search Result: ID: "<<result.ID<<", Name: "<<result.name<<" GPA: "<<result.GPA<<endl;
    
    // Example 2.
    HashTable<string, string> NameToAddress(5);
    NameToAddress.Insert("ABC", "Cairo");
    NameToAddress.Insert("WXYZ", "Alex");
    NameToAddress.DisplayTable();
    
    // Example 3.
    HashTable<char, int> LetterToCount(6);
    LetterToCount.Insert('A', 50);
    LetterToCount.Insert('B', 25);
    LetterToCount.DisplayTable();
    
    return 0;
}