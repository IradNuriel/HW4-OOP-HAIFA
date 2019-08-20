#include <iostream>
#include <ostream>
#include <string>
#include <map>


//class Employee declerations:
class Employee {
private:
	//for the encapsulation, the derived class will know only what it realy need
	static int numOfEmployeeThatConstructed;
	const int id;
public:
	Employee(const std::string& description = "???");
	Employee(const Employee& other);
	virtual ~Employee();
	virtual Employee* clone()=0;
	int getID() const;
	const std::string& getDescription() const;
	void setDescription(const std::string& description = "???");
	friend std::ostream& operator<<(std::ostream& out, const Employee& toPrint);
protected:
	//for printable classes:
	std::string description;
	//helper method to the << operator
	virtual void print(std::ostream& out) const = 0;
};

//class DeveloperEmployee declerations:
class DeveloperEmployee: public Employee {
private:
	std::string project;
public:
	DeveloperEmployee(const std::string& description="???", const std::string& project="???");
	DeveloperEmployee(const DeveloperEmployee& other);
	virtual ~DeveloperEmployee();
	virtual DeveloperEmployee* clone();
	void setProject(const std::string& project = "???");
protected:
	virtual void print(std::ostream& out) const;
};

//class TesterEmployee declerations:
class TesterEmployee: public Employee {
private:
	std::string level;
public:
	TesterEmployee(const std::string& description="???", const std::string& level="???");
	TesterEmployee(const TesterEmployee& other);
	virtual  ~TesterEmployee();
	virtual TesterEmployee* clone();
	void setLevel(const std::string& level = "???");
protected:
	virtual void print(std::ostream& out) const;
};



//IllegalArguments exeption
class IllegalArguments: public std::exception {
	//IllegalArguments exeption:
	virtual const char* what() const throw() {
		return "";
	}
};



//class Company
class Company {
private:
	/*we need functionality of inserting+deliting+searching an item by one of his properties,
	but also the ability to pass sequencialy on the items, 
	so map is the most matched data structure*/ 
	std::map<int, Employee*> container;
public:
	Company();
	void operator+=(Employee* toInsert);
	void operator-=(int id);
	Employee* operator[](int id);
	friend std::ostream& operator<<(std::ostream& out, Company& toPrint);
	bool contains(int id);
};

//class Printable, using mixin!!!!!!(I'm a bit excited about that)
template <class Base>
class Printable: public Base {
protected:
	Printable(const Printable<Base>& other): Base(other) {

	}
public:
	Printable(): Base() {

	}
	void printDescription() {
		std::cout << this->Base::description << std::endl;
	}
};

//class PrintableDeveloper
class PrintableDeveloper : public Printable<DeveloperEmployee> {
protected:
	PrintableDeveloper(const PrintableDeveloper& other): Printable(other) {

	}
public:
	PrintableDeveloper(): Printable() {

	}
	virtual PrintableDeveloper* clone() {
		return new PrintableDeveloper(*this);
	}
};

//class PrintableTester
class PrintableTester : public Printable<TesterEmployee> {
protected:
	PrintableTester(const PrintableTester& other) : Printable(other) {

	}
public:
	PrintableTester() : Printable() {

	}
	virtual PrintableTester* clone() {
		return new PrintableTester(*this);
	}
};