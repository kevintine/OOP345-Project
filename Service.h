#ifndef SDDS_SERVICE_H
#define SDDS_SERVICE_H
#include <iostream>

namespace sdds {
	class Service {
		double price;
		int hours;
		std::string details;
	public:
		Service();
		~Service();
		// copy assignment and constructor
		Service(const Service&);
		Service& operator=(const Service&);
		// move constructor and assignment
		Service(Service&&);
		Service& operator=(Service&&);
	};
}

#endif