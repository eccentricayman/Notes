#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
	friend ostream& operator << (ostream& os, const PrintedMaterial& pm) {
		os << pm.numOfPages;
		return os;
	}
public:
	PrintedMaterial( unsigned numPages )
		: numOfPages(numPages)
	{}
	
	//               LOOK AT THE = 0
	virtual void displayNumPages() const = 0;
private:
	unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
	cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
	Magazine( unsigned numPages )
		: PrintedMaterial(numPages)
	{}
	void displayNumPages() const
	{
		cout << "magazino: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book( unsigned numPages )
		: PrintedMaterial(numPages)
	{}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook( unsigned numPages, unsigned numIndxPgs  )
		: Book(numPages),
		  numOfIndexPages(numIndxPgs)
	{}
	void displayNumPages() const
	{
		cout << "Pages for textbuk: ";
		PrintedMaterial::displayNumPages();
		cout << "Index pages: ";
		cout << numOfIndexPages << endl; 
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel( unsigned numPages )
		: Book(numPages)
	{}
	void displayNumPages() const
	{
		cout << "novul: ";
		PrintedMaterial::displayNumPages();
	}

protected:
private:
};

void displayNumberofPages(const PrintedMaterial& pm) {
	pm.displayNumPages();
}

// tester/modeler code
int main()
{
	TextBook t(5430, 23);
	Novel n(213);
	Magazine m(6);

	cout << t << endl; 
	cout << n << endl;
	cout << m << endl;

	cout << endl;

	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();

	cout << endl;
	
	//PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
	//pm.displayNumPages();

	PrintedMaterial* pmPtr;
	pmPtr = &t;
	// instead of putting an actual PrintedMaterial
	// object into the vector, we put a pointer to
	// a PrintedMaterial object (t) into a vector
	// of pointers-to-PrintedMaterial
	// (that is, pointers to the Base class)
	// we'll be "managing" our objects by using
	// pointers to PrintedMaterial values.

	pmPtr->displayNumPages();

	cout << endl;
	
	cout << "vect" << endl;
	vector< PrintedMaterial* > allThemPrinties;
	allThemPrinties.push_back(&t);
	allThemPrinties.push_back(&n);
	allThemPrinties.push_back(&m);
	for( size_t ndx=0; ndx < allThemPrinties.size(); ++ ndx ) 
		{
			allThemPrinties[ndx]->displayNumPages();
			cout << endl;
		}
}
