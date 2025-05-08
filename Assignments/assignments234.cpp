#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <exception>
using namespace std;

// ----------------------- BASE EXCEPTIONS -----------------------

class UniversitySystemException : public exception {
protected:
    string message;
public:
    UniversitySystemException(string msg) : message("UniversitySystemException: " + msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(string msg) : UniversitySystemException("Enrollment Error - " + msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(string msg) : UniversitySystemException("Grade Error - " + msg) {}
};

class PaymentException : public UniversitySystemException {
public:
    PaymentException(string msg) : UniversitySystemException("Payment Error - " + msg) {}
};

void logError(const string& error) {
    cerr << "[ERROR] " << error << endl;
}

// ----------------------- CLASS DEFINITIONS -----------------------

class Person {
protected:
    string name;
    int age;
    string ID;
    string contactInfo;

public:
    Person(string name, int age, string ID, string contact)
        : name(name), ID(ID), contactInfo(contact) {
        setAge(age);
    }

    virtual ~Person() {}

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID
             << ", Contact: " << contactInfo << endl;
    }

    virtual double calculatePayment() const {
        return 0.0;
    }

    void setName(string n) {
        if (n.empty()) throw UniversitySystemException("Name cannot be empty.");
        name = n;
    }

    void setAge(int a) {
        if (a <= 0 || a > 120) throw UniversitySystemException("Invalid age.");
        age = a;
    }

    void setContactInfo(string contact) { contactInfo = contact; }
    string getID() const { return ID; }
};

class Student : public Person {
private:
    string enrollmentDate, program;
    double GPA;

public:
    Student(string name, int age, string ID, string contact,
            string date, string prog, double gpa)
        : Person(name, age, ID, contact), enrollmentDate(date), program(prog) {
        setGPA(gpa);
    }

    void setGPA(double g) {
        if (g < 0.0 || g > 4.0) throw UniversitySystemException("GPA must be 0.0 - 4.0.");
        GPA = g;
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Program: " << program << ", Enrollment Date: " << enrollmentDate
             << ", GPA: " << GPA << endl;
    }

    double calculatePayment() const override {
        return 5000.00;
    }
};

class UndergraduateStudent : public Student {
private:
    string major, minor, expectedGraduationDate;

public:
    UndergraduateStudent(string name, int age, string ID, string contact,
                         string date, string prog, double gpa,
                         string major, string minor, string gradDate)
        : Student(name, age, ID, contact, date, prog, gpa),
          major(major), minor(minor), expectedGraduationDate(gradDate) {}

    void displayDetails() const override {
        Student::displayDetails();
        cout << "Major: " << major << ", Minor: " << minor
             << ", Expected Graduation: " << expectedGraduationDate << endl;
    }

    double calculatePayment() const override {
        return 4500.00;
    }
};

class Professor : public Person {
protected:
    string department, specialization, hireDate;

public:
    Professor(string name, int age, string ID, string contact,
              string dept, string spec, string hire)
        : Person(name, age, ID, contact), department(dept),
          specialization(spec), hireDate(hire) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << ", Specialization: " << specialization
             << ", Hire Date: " << hireDate << endl;
    }

    double calculatePayment() const override {
        return 75000.00;
    }
};

class AssistantProfessor : public Professor {
private:
    int yearsOfService;

public:
    AssistantProfessor(string name, int age, string ID, string contact,
                       string dept, string spec, string hire, int years)
        : Professor(name, age, ID, contact, dept, spec, hire),
          yearsOfService(years) {}

    double calculatePayment() const override {
        return 60000.00 + (yearsOfService * 500);
    }

    void displayDetails() const override {
        Professor::displayDetails();
        cout << "Rank: Assistant Professor, Years of Service: " << yearsOfService << endl;
    }
};

class AssociateProfessor : public Professor {
private:
    int publications;

public:
    AssociateProfessor(string name, int age, string ID, string contact,
                       string dept, string spec, string hire, int pubs)
        : Professor(name, age, ID, contact, dept, spec, hire),
          publications(pubs) {}

    double calculatePayment() const override {
        return 80000.00 + (publications * 250);
    }

    void displayDetails() const override {
        Professor::displayDetails();
        cout << "Rank: Associate Professor, Publications: " << publications << endl;
    }
};

class FullProfessor : public Professor {
private:
    bool isTenured;
    double grantAmount;

public:
    FullProfessor(string name, int age, string ID, string contact,
                  string dept, string spec, string hire, bool tenured, double grants)
        : Professor(name, age, ID, contact, dept, spec, hire),
          isTenured(tenured), grantAmount(grants) {}

    double calculatePayment() const override {
        return 100000.00 + grantAmount;
    }

    void displayDetails() const override {
        Professor::displayDetails();
        cout << "Rank: Full Professor, Tenured: " << (isTenured ? "Yes" : "No")
             << ", Research Grants: $" << grantAmount << endl;
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic, thesisTitle;
    Professor* advisor;

public:
    GraduateStudent(string name, int age, string ID, string contact,
                    string date, string prog, double gpa,
                    string topic, string thesis, Professor* adv)
        : Student(name, age, ID, contact, date, prog, gpa),
          researchTopic(topic), thesisTitle(thesis), advisor(adv) {}

    void displayDetails() const override {
        Student::displayDetails();
        cout << "Research Topic: " << researchTopic << ", Thesis Title: " << thesisTitle << endl;
        if (advisor) {
            cout << "Advisor: ";
            advisor->displayDetails();
        }
    }

    double calculatePayment() const override {
        return 2000.00;
    }
};

class Course {
private:
    string code, title, description;
    int credits;
    Professor* instructor;

public:
    Course(string c, string t, int cr, string desc, Professor* prof = nullptr)
        : code(c), title(t), description(desc), instructor(prof) {
        setCredits(cr);
    }

    void setCredits(int c) {
        if (c <= 0) throw UniversitySystemException("Credits must be positive.");
        credits = c;
    }

    void display() const {
        cout << "Course: " << title << " [" << code << "], Credits: "
             << credits << "\nDescription: " << description << endl;
        if (instructor) {
            cout << "Instructor: ";
            instructor->displayDetails();
        }
    }
};

class Department {
private:
    string name, location;
    double budget;
    vector<Professor*> professors;

public:
    Department(string n, string loc, double b)
        : name(n), location(loc), budget(b) {}

    void addProfessor(Professor* p) {
        professors.push_back(p);
    }

    void display() const {
        cout << "Department: " << name << ", Location: " << location
             << ", Budget: $" << budget << endl;
        for (auto* p : professors) p->displayDetails();
    }
};

class GradeBook {
private:
    map<string, double> grades;

public:
    void addGrade(string studentID, double grade) {
        if (grade < 0 || grade > 100)
            throw GradeException("Invalid grade: " + to_string(grade));
        grades[studentID] = grade;
    }

    double calculateAverageGrade() {
        double sum = 0;
        for (auto& g : grades) sum += g.second;
        return grades.empty() ? 0 : sum / grades.size();
    }
};

class EnrollmentManager {
private:
    map<string, vector<string>> courseEnrollments;

public:
    void enrollStudent(string courseID, string studentID) {
        if (courseEnrollments[courseID].size() >= 30)
            throw EnrollmentException("Course " + courseID + " is full.");
        courseEnrollments[courseID].push_back(studentID);
    }
};

class UniversitySystem {
private:
    vector<Student*> students;
    vector<Professor*> professors;
    vector<Course> courses;
    vector<Department> departments;
    EnrollmentManager enrollmentManager;
    GradeBook gradeBook;

public:
    void addStudent(Student* s) { students.push_back(s); }
    void addProfessor(Professor* p) { professors.push_back(p); }
    void addCourse(const Course& c) { courses.push_back(c); }
    void enroll(string courseID, string studentID) {
        enrollmentManager.enrollStudent(courseID, studentID);
    }
    void addGrade(string studentID, double grade) {
        gradeBook.addGrade(studentID, grade);
    }
    void showReports() {
        cout << "--- University Report ---\n";
        for (auto* s : students) s->displayDetails();
        for (auto* p : professors) p->displayDetails();
        for (const auto& c : courses) c.display();
        cout << "Average Grade: " << gradeBook.calculateAverageGrade() << endl;
    }
};

void runMenu() {
    UniversitySystem uni;
    int choice;
    do {
        cout << "\n--- University Management Menu ---\n";
        cout << "1. Add Student\n2. Add Professor\n3. Enroll Student\n4. Add Grade\n5. Show Report\n0. Exit\n";
        cin >> choice;
        try {
            if (choice == 1) {
                string name, ID, contact, program, date;
                int age; double gpa;
                cin >> name >> age >> ID >> contact >> program >> date >> gpa;
                uni.addStudent(new Student(name, age, ID, contact, date, program, gpa));
            } else if (choice == 2) {
                string name, ID, contact, dept, spec, hire; int age;
                cin >> name >> age >> ID >> contact >> dept >> spec >> hire;
                uni.addProfessor(new Professor(name, age, ID, contact, dept, spec, hire));
            } else if (choice == 3) {
                string courseID, studentID;
                cin >> courseID >> studentID;
                uni.enroll(courseID, studentID);
            } else if (choice == 4) {
                string studentID; double grade;
                cin >> studentID >> grade;
                uni.addGrade(studentID, grade);
            } else if (choice == 5) {
                uni.showReports();
            }
        } catch (const UniversitySystemException& e) {
            logError(e.what());
        }
    } while (choice != 0);
}

int main() {
    runMenu();
    return 0;
}
