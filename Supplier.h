#ifndef SDDS_SUPPLIER_H
#define SDDS_SUPPLIER_H
#include <iostream>

namespace sdds {
	class Supplier {
		std::string name;
		int phoneNumber;
		int supplierID;
	public:
		Supplier();
		~Supplier();
		// copy assignment and constructor
		Supplier(const Supplier&);
		Supplier& operator=(const Supplier&);
		// move constructor and assignment
		Supplier(Supplier&&);
		Supplier& operator=(Supplier&&);
	};
}

#endif