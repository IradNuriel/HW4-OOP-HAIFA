#include <ostream>
#include <string>
#include "Definitions.h"



//constructors:
DeveloperEmployee::DeveloperEmployee(const std::string& description, const std::string& project) : Employee(description) {
	this->project = project;
}

DeveloperEmployee::DeveloperEmployee(const DeveloperEmployee& other):Employee(other) {
	//copy c'tor, for clone method
	this->project = other.project;
}

DeveloperEmployee::~DeveloperEmployee() {
	//d'tor
}

void DeveloperEmployee::setProject(const std::string& project) {

	this->project = project;
}


DeveloperEmployee* DeveloperEmployee::clone() {
	//clone method, using copy c'tor
	return new DeveloperEmployee(*this);
}


void DeveloperEmployee::print(std::ostream& out) const{
	//print method
	out << "Developer " << "";
	this->Employee::print(out);
	out << " project = " << this->project << "";
}