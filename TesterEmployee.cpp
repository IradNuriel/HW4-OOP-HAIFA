#include <ostream>
#include <string>
#include "Definitions.h"

//conctructors:
TesterEmployee::TesterEmployee(const std::string& description, const std::string& level) : Employee(description) {
	this->level = level;
}

TesterEmployee::TesterEmployee(const TesterEmployee& other) : Employee(other) {
	//copy c'tor, for clone ethod
	this->level = other.level;
}

TesterEmployee::~TesterEmployee() {
	//d'tor
}

void TesterEmployee::setLevel(const std::string& level) {
	this->level = level;
}


TesterEmployee* TesterEmployee::clone() {
	//clone method, using copy c'tor
	return new TesterEmployee(*this);
}

void TesterEmployee::print(std::ostream& out) const {
	//print method
	out << "Tester " << "";
	this->Employee::print(out);
	out << " level = " << this->level << "";
}
