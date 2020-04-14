/*
  Ayman Ahmed
  rec07 
  does registrar things
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course;
class Student;

class Course {
	friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
	Course(const string& courseName);
	const string& getName() const;
	bool addStudent(Student*);
	void removeStudentsFromCourse();
private:
    string name;
    vector<Student*> students;
};

class Student {
	friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
	Student(const string& name);
	const string& getName() const;
	bool addCourse(Course*);

    // Student method needed by Course
    void removedFromCourse(Course*);

private:
    string name;
    vector<Course*> courses;
};

class Registrar {
	friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string&);
    bool addStudent(const string&);
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);
    bool cancelCourse(const string& courseName);
	void purge();

private:
	size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
};

ostream& operator<<(ostream& os, const Course& rhs) {
	os << rhs.name << ": ";
	if (rhs.students.size() == 0) {
		os << "No Students";
	}
	else {
		for (Student* student : rhs.students) {
			os << student->getName() << " ";
		}
	}
	return os;
}

Course::Course(const string& courseName) : name(courseName) { };

const string& Course::getName() const { return name; }

bool Course::addStudent(Student* newS) {
	students.push_back(newS);
	return true;
}

void Course::removeStudentsFromCourse() {
	for (Student* student : students) {
		student->removedFromCourse(this);
	}
	students.clear();
}

ostream& operator<<(ostream& os, const Student& rhs) {
	os << rhs.name << ": ";
	if (rhs.courses.size() > 0) {
		for (Course* course : rhs.courses) {
			os << course->getName() << " ";
		}
	}
	else {
		os << "No Courses";
	}
	return os;
}

Student::Student(const string& name) : name(name) { };

const string& Student::getName() const { return name; }

bool Student::addCourse(Course* newC) {
	courses.push_back(newC);
	return true;
}

void Student::removedFromCourse(Course* course) {
	int index = -1;
	for (size_t a = 0 ; a < courses.size() ; a++) {
		if (courses[a]->getName() == course->getName()) {
			index = a;
		}
	}
	//last element
	if (index == courses.size() - 1) {
		courses.pop_back();
	}
	else {
		for (size_t b = index ; b < courses.size() - 1 ; b++) {
			courses[b] = courses[b + 1];
		}
		courses.pop_back();
	}
}

ostream& operator<<(ostream& os, const Registrar& rhs) {
	os << "Courses: \n";
	for (Course* course : rhs.courses) {
		os << *course << endl;
	}
	os << "Students: \n";
	for (Student* student : rhs.students) {
		os << *student << endl;
	}
	return os;
}

Registrar::Registrar() {};

bool Registrar::addCourse(const string& cName) {
	int exists = findCourse(cName);
	
	if (exists != -1) {
		return false;
	}
	else {
		courses.push_back(new Course(cName));
		return true;
	}
}
bool Registrar::addStudent(const string& sName) {
	int exists = findStudent(sName);

	if (exists != -1) {
		return false;
	}
	else {
		students.push_back(new Student(sName));
		return true;
	}
}
bool Registrar::enrollStudentInCourse(const string& studentName,
						   const string& courseName) {
	int student = findStudent(studentName);
	int course = findCourse(courseName);

	if (student != -1 && course != -1) {
		students[student]->addCourse(courses[course]);
		courses[course]->addStudent(students[student]);
		return true;
	}
	else {
		return false;
	}
}
bool Registrar::cancelCourse(const string& courseName) {
	int course = findCourse(courseName);
	if (course != -1) {
		courses[course]->removeStudentsFromCourse();
		delete courses[course];

		//last element
		if (course == courses.size() - 1) {
			courses.pop_back();
		}
		else {
			for (size_t a = course ; a < courses.size() - 1 ; a++) {
				courses[a] = courses[a + 1];
			}
			courses.pop_back();
		}
		return true;
	}
	return false;
}

void Registrar::purge() {
	for (Course* course : courses) {
		delete course;
	}
	for (Student* student : students) {
		delete student;
	}
	courses.clear();
	students.clear();
}

size_t Registrar::findStudent(const string& sName) const {
	for (size_t a = 0 ; a < students.size() ; a++) {
		if (students[a]->getName() == sName) {
			return a;
		}
	}
	return -1;
}
size_t Registrar::findCourse(const string& cName) const {
	for (size_t a = 0 ; a < courses.size() ; a++) {
		if (courses[a]->getName() == cName) {
			return a;
		}
	}
	return -1;
}

int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}
  
