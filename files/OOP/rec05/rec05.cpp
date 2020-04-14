/*
  rec05.cpp
  Ayman Ahmed
  this file creates sections, lab workers, time slots, and students
  and deals with their relationships to each other
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section;
class LabWorker;

class Section {
public:
	Section(string nm, string day, unsigned int hour) : name(nm),
														time(day, hour) { }
	
	string getName() { return name; }

	void setName(string nm) { name = nm; }

	//student class
	class Student {
	public:
		Student(string nm) : name(nm) {
			for (int a = 0 ; a < 14 ; a++) {
				grades.push_back(-1);
			}
		}
		
		string getName() { return name; }
		int getGrade(int week) { return grades[week]; }
		
		void setName(string nm) { name = nm; }
		void setGrade(int grade, int week) { grades[week] = grade; }
		
		friend ostream &operator << (ostream &output,
									 const Student &student) {
			output << "Name: " << student.name << ", Grades: ";
			for (int grade : student.grades) {
				output << grade << " ";
			}
			return output;
		}
	private:
		string name;
		vector<int> grades;
	};
	
	friend ostream &operator << (ostream &output,
								 const Section &section) {
		output << "Section: " << section.name <<
			", Time slot: " << section.time << ", Students: ";
		//if students > 0
		if (section.students.size() > 0) {
			for (const Student* student : section.students) {
				output << *student << endl;
			}
		}
		else {
			output << "None";
		}
		return output;
	}

	void addStudent(string name) {
		Student* student = new Student(name);
		students.push_back(student);
	}
private:
	//timeslot class
	class TimeSlot {
	public:
		TimeSlot(string dy, unsigned int hr) : day(dy), hour(hr) { };
		
		string getDay() { return day; }
		unsigned int getHour() { return hour; }
		
		void setDay(string newday) { day = newday; }
		void setHour(unsigned int newhour) { hour = newhour; }
		
		friend ostream &operator << (ostream &output,
									 const TimeSlot &timeslot) {
			//change to 12 hr format
			if (timeslot.hour > 12) {
				output << "[Day: " << timeslot.day << ", Start time: "
					   << timeslot.hour - 12 << "pm]";
			}
			else {
				output << "[Day: " << timeslot.day << ", Start time: "
					   << timeslot.hour << "am]";
			}
			return output;
		}
	private:
		string day;
		unsigned int hour;
	};
	
	//private vars
	string name;
	TimeSlot time;
	vector<Student*> students;
};

//defining a lab worker
class LabWorker {
public:
	LabWorker(string nm) : name(nm) { section = NULL; }

	string getName() { return name; }
	Section getSection() { return *section; }

	void setName(string nm) { name = nm; }
	void setSection(Section sec) { section = &sec; }

	friend ostream &operator << (ostream &output,
								 LabWorker &labworker) {
		output << labworker.name;
		//doesnt have a section
		if (labworker.section == NULL) {
			output << " does not have a section";
		}
		else {
			output << " has " << *(labworker.section);
		}
		return output;
	}

	void addSection(Section sec) {
		section = &sec;
	}
private:
	string name;
	Section* section;
};

// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    //cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    //cout << secA2 << endl;

    //cout << "\nTest 2: Adding students to a section\n";
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");
	//cout << secA2 << endl;

    //cout << "\nTest 3: Defining a lab worker.\n";
	LabWorker moe( "Moe" );
	//cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
	moe.addSection( secA2 );
	cout << moe << endl << endl;
	cout << secA2 << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    // LabWorker jane( "Jane" );
    // Section secB3( "B3", "Thursday", 11 );
    // secB3.addStudent("Thorin");
    // secB3.addStudent("Dwalin");
    // secB3.addStudent("Balin");
    // secB3.addStudent("Kili");
    // secB3.addStudent("Fili");
    // secB3.addStudent("Dori");
    // secB3.addStudent("Nori");
    // secB3.addStudent("Ori");
    // secB3.addStudent("Oin");
    // secB3.addStudent("Gloin");
    // secB3.addStudent("Bifur");
    // secB3.addStudent("Bofur");
    // secB3.addStudent("Bombur");
    // jane.addSection( secB3 );
    // cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    // moe.addGrade("John", 17, 1);  
    // moe.addGrade("Paul", 19, 1);  
    // moe.addGrade("George", 16, 1);  
    // moe.addGrade("Ringo", 7, 1);  
    // cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    // moe.addGrade("John", 15, 3);  
    // moe.addGrade("Paul", 20, 3);  
    // moe.addGrade("Ringo", 0, 3);  
    // moe.addGrade("George", 16, 3);  
    // cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    // doNothing(secA2);
    // cout << "Back from doNothing\n\n";

} // main
