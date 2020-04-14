#include "Registrar.h"
using namespace std;

namespace BrooklynPoly {

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

}
