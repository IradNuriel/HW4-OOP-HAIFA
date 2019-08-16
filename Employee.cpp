#include <ostream>
#include <string>
#include "Definitions.h"


int Employee::numOfEmployeeThatConstructed = 1;

Employee::Employee(const std::string& description): id(Employee::numOfEmployeeThatConstructed){
	Employee::numOfEmployeeThatConstructed++;
	this->description = description;
}

Employee::Employee(const Employee& other): id(other.id){
	this->description = other.description;
}

Employee::~Employee(){

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
	toPrint.print(out);
	return out;
}


void Employee::print(std::ostream& out) const {
	out << "ID = " << this->id << ",";
}

