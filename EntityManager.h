#ifndef SDDS_ENTITYMANAGER_H
#define SDDS_ENTITYMANAGER_H
#include <iostream>

#include "Appointment.h"
#include "Service.h"
#include "Supplier.h"

namespace sdds {
	class EntityManager {
	private:
		// gets list of suppliers using a supplier pointer
		Supplier* getSupplier();
		// gets list of already scheduled appointments using an appointment pointer
		Appointment* getAppointment();
		// gets list of services using a service pointer
		Service* getService();
		// Appointment contains Supplier and Service
		void persist(Appointment);
	};
}

#endif