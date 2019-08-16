#include <ostream>
#include <string>
#include "Definitions.h"


TesterEmployee::TesterEmployee(const std::string& description, const std::string& level) : Employee(description) {
	this->level = level;
}

TesterEmployee::TesterEmployee(const TesterEmployee& other) : Employee(other) {
	this->level = other.level;
}

TesterEmployee::~TesterEmployee() {

}

void TesterEmployee::setLevel(const std::string& level) {
	this->level = level;
}


TesterEmployee* TesterEmployee::clone() {
	return new TesterEmployee(*this);
}

void TesterEmployee::print(std::ostream& out) const {
	out << "Tester " << "";
	this->Employee::print(out);
	out << " level = " << this->level << "";
}
