#include "Student.h"
#include "Course.h"
using namespace std;

namespace BrooklynPoly {

	ostream& operator<<(ostream& os, const BrooklynPoly::Course& rhs) {
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

}
