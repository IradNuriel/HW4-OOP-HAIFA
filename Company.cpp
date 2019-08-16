#include <ostream>
#include <string>
#include <map>
#include "Definitions.h"



Company::Company() {
	
}


void Company::operator+=(Employee* toInsert) {
	if (toInsert == NULL) {
		throw IllegalArguments();
	}
	else if(!this->contains(toInsert->getID())) {
		Employee* copy = toInsert->clone();
		std::pair<int, Employee*> pair(copy->getID(), copy);
		this->container.insert(pair);
	}
}

void Company::operator-=(int id) {
	std::map<int, Employee*>::iterator element = this->container.find(id);
	if (element != this->container.end()) {
		Employee* valueOfElement = (*element).second;
		this->container.erase(element);
		delete valueOfElement;
	}
}

Employee* Company::operator[](int id) {
	std::map<int, Employee*>::iterator element = this->container.find(id);
	if (element != this->container.end()) {
		return (*element).second->clone();
	}
	else {
		return NULL;
	}
}


bool Company::contains(int id) {
	return (*this)[id] != NULL;
}


std::ostream& operator<<(std::ostream& out, Company& toPrint) {
	if (toPrint.container.empty()) {
		out << "Company is empty" << std::endl;
	}
	else {
		out << "Company employees: " << std::endl;
		for (std::map<int, Employee*>::iterator element = toPrint.container.begin();element!=toPrint.container.end();++element) {
			out << *((*element).second) <<std::endl;
		}
	}
	return out;
}