/*
  Recitation 06
  CS2124
 
  Focus: Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary)
        : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position

class Entry {
    friend ostream& operator<<(ostream& os, const Entry& rhs) {
        os << rhs.name << ' ' << rhs.room
           << ' ' << rhs.phone << ", " << *rhs.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
        : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const { return name; }
    unsigned getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
    // Overload output operator
	friend ostream& operator << (ostream& os, const Directory& rhs) {
		for (size_t a = 0 ; a < rhs.size ; a++) {
			os << *rhs.entries[a] << endl;
		}
		return os;
	}
public:
    // Of course the first function you need to write for this (or
    // any) class is...
    // ???
    // ... 
	unsigned operator[] (const string& name) const {
		for (size_t a = 0 ; a < size ; a++) {
			if ((entries[a] -> getName()) == name) {
				return entries[a]->getPhone();
			}
		}
		cout << "Not found";
		return 99999999;
	}

	Directory() : size(0), capacity(1), entries(new Entry*[1]) { }

	//destrucc
	~Directory() {
		for (size_t a = 0 ; a < size ; a++) {
			delete(entries[a]);
		}
		delete [ ]entries;
		entries = nullptr;

		//size = 0;
		//capacity = 0;
	}

	//copy construcc
	Directory(const Directory& directory) :
		entries(new Entry*[directory.capacity]),
		size(directory.size),
		capacity(directory.capacity) {
		for (size_t a = 0 ; a < size ; a++) {
		    entries[a]  = new Entry(*directory.entries[a]);
		}
	}

	//assignment
	Directory& operator = (const Directory& directory) {
		//self assignment
		if (this != &directory) {
			for (size_t a = 0 ; a < size ; a++) {
				delete(entries[a]);
			}
			delete []entries;
			
			entries = new Entry*[directory.capacity];
			size = directory.size;
			capacity = directory.capacity;

			for (size_t a = 0 ; a < size ; a++) {
				entries[a] = new Entry(*directory.entries[a]);
			}
		}
		
		return *this;
	}
	
    // We'll get you started with the add method, but obviously you
    // have a lot of work to do here.
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)	{
            // something is missing!!!  Add it!
			Entry** newEntries = new Entry*[capacity * 2];
			for (size_t a = 0 ; a < size ; a++) {
				newEntries[a] = entries[a];
			}
			delete []entries;
			entries = newEntries;
			capacity *= 2;

        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add

private:	
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {
	
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
	
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2 = d;	// What function is being used??copycons
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    Directory d3;
    d3 = d2;

    // Should display 1592
    cout << d2["Carmack"] << endl;
	
} // main
