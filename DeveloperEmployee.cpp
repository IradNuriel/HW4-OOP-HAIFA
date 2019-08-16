#include <ostream>
#include <string>
#include "Definitions.h"


DeveloperEmployee::DeveloperEmployee(const std::string& description, const std::string& project) : Employee(description) {
	this->project = project;
}

DeveloperEmployee::DeveloperEmployee(const DeveloperEmployee& other):Employee(other) {
	this->project = other.project;
}

DeveloperEmployee::~DeveloperEmployee() {

}

void DeveloperEmployee::setProject(const std::string& project) {
	this->project = project;
}


DeveloperEmployee* DeveloperEmployee::clone() {
	return new DeveloperEmployee(*this);
}


void DeveloperEmployee::print(std::ostream& out) const{
	out << "Developer " << "";
	this->Employee::print(out);
	out << " project = " << this->project << "";
}