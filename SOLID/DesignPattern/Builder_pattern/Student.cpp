#include <bits/stdc++.h>
using namespace std;

class StudentBuilder;  // Forward declaration

class Student {
    int rollNumber;
    int age;
    string name;
    string fatherName;
    string motherName;
    set<string> subjects;

public:
    Student(StudentBuilder* builder);  // Constructor declaration

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subjects: ";
        for (const auto& subject : subjects) {
            cout << subject << " ";
        }
        cout << endl;
    }
};

class StudentBuilder {
protected:
    int rollNumber;
    int age;
    string name;
    string fatherName;
    string motherName;
    set<string> subjects;

public:
    StudentBuilder* setRollNumber(int rollNumber) {
        this->rollNumber = rollNumber;
        return this;
    }

    StudentBuilder* setAge(int age) {
        this->age = age;
        return this;
    }

    StudentBuilder* setName(string name) {
        this->name = name;
        return this;
    }

    StudentBuilder* setFatherName(string fatherName) {
        this->fatherName = fatherName;
        return this;
    }

    StudentBuilder* setMotherName(string motherName) {
        this->motherName = motherName;
        return this;
    }

    virtual StudentBuilder* setSubjects() = 0;

    Student* build() {
        return new Student(this);
    }

    friend class Student;  // Allow Student to access private/protected members of StudentBuilder
};

Student::Student(StudentBuilder* builder) {
    this->rollNumber = builder->rollNumber;
    this->age = builder->age;
    this->name = builder->name;
    this->fatherName = builder->fatherName;
    this->motherName = builder->motherName;
    this->subjects = builder->subjects;
}

class EngineeringStudentBuilder : public StudentBuilder {
public:
    StudentBuilder* setSubjects() override {
        set<string> st;
        st.insert("DSA");
        st.insert("OS");
        st.insert("OOPS");
        st.insert("Computer Architecture");
        this->subjects = st;
        return this;
    }
};

class MBAStudentBuilder : public StudentBuilder {
public:
    StudentBuilder* setSubjects() override {
        set<string> st;
        st.insert("Microeconomics");
        st.insert("Business Studies");
        st.insert("Operations Management");
        this->subjects = st;
        return this;
    }
};

class Director {
    StudentBuilder* studentBuilder;

public:
    Director(StudentBuilder* studentBuilder) {
        this->studentBuilder = studentBuilder;
    }

    Student* createEngineeringStudent() {
        return studentBuilder->setAge(22)->setName("Gaurav")->setSubjects()->build();
    }

    Student* createMBAStudent() {
        return studentBuilder->setAge(25)->setName("Rahul")->setSubjects()->build();
    }
};

int main() {
    Director director(new EngineeringStudentBuilder());
    Student* engStudent = director.createEngineeringStudent();
    engStudent->display();

    Director director2(new MBAStudentBuilder());
    Student* mbaStudent = director2.createMBAStudent();
    mbaStudent->display();

    return 0;
}
