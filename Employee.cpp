#include <ostream>
#include <string>
#include "Definitions.h"


int Employee::numOfEmployeeThatConstructed = 1;

//constructors:
Employee::Employee(const std::string& description): id(Employee::numOfEmployeeThatConstructed){
	Employee::numOfEmployeeThatConstructed++;
	this->description = description;
}

Employee::Employee(const Employee& other): id(other.id){
	//copy c'tor, for the clone method
	this->description = other.description;
}

Employee::~Employee(){
	//d'tor
}

int Employee::getID() const{
	return this->id;
}

const std::string& Employee::getDescription() const{
	return this->description;
}

void Employee::setDescription(const std::string& description) {
	this->description = description;
}

std::ostream& operator<<(std::ostream& out, const Employee& toPrint) {
	//operator << for printing employee by run-time
	toPrint.print(out);
	return out;
}


void Employee::print(std::ostream& out) const {
	//method for printing the id of the employee
	out << "ID = " << this->id << ",";
}

