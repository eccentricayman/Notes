#include "Course.h"
#include "Student.h"
using namespace std;

namespace BrooklynPoly {

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

}
