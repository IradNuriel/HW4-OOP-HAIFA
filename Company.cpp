#include <ostream>
#include <string>
#include <map>
#include "Definitions.h"


//default c'tor
Company::Company() {
	
}

//insertion operator.
void Company::operator+=(Employee* toInsert) {
	if (toInsert == NULL) {
		//if we need to insert null, it is illegal!!
		throw IllegalArguments();
	}
	else if(!this->contains(toInsert->getID())) {
		//if we don't have the id that we need to insert in the structure, we will insert.
		Employee* copy = toInsert->clone();
		std::pair<int, Employee*> pair(copy->getID(), copy);
		this->container.insert(pair);
	}
}

void Company::operator-=(int id) {
	//getting the iterator of the givven employee id.
	std::map<int, Employee*>::iterator element = this->container.find(id);
	if (element != this->container.end()) {
		//if the id is in the structure, we will remove the employee ffrom the structure
		Employee* valueOfElement = (*element).second;
		this->container.erase(element);
		delete valueOfElement;
	}
}

Employee* Company::operator[](int id) {
	//regular find method.
	std::map<int, Employee*>::iterator element = this->container.find(id);
	if (element != this->container.end()) {
		return (*element).second->clone();
	}
	else {
		return NULL;
	}
}


bool Company::contains(int id) {
	//regular contains method.
	return (*this)[id] != NULL;
}


std::ostream& operator<<(std::ostream& out, Company& toPrint) {
	//operator <<
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