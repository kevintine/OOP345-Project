#ifndef SDDS_APPOINTMENT_H
#define SDDS_APPOINTMENT_H
#include <iostream>

#include "Service.h"
#include "Supplier.h"

namespace sdds {
	class Appointment {
		std::string name;
		int phoneNumber;
		int date;
		int time;
		Supplier supplier;
		int consultationID;
		Service* service;
	public:
		Appointment();
		~Appointment();
		// copy assignment and constructor
		Appointment(const Appointment&);
		Appointment& operator=(const Appointment&);
		// move constructor and assignment
		Appointment(Appointment&&);
		Appointment& operator=(Appointment&&);
	};
}

#endif