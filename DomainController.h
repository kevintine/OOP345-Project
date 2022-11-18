#ifndef SDDS_DOMAINCONTROLLER_H
#define SDDS_DOMAINCONTROLLER_H
#include <iostream>

#include "Appointment.h"
#include "Service.h"
#include "Supplier.h"

namespace sdds {
	class DomainController {
	private:
		// request an appointment
		void requestAddAppointment();
		// select by supplier ID
		void selectSupplier(Supplier);
		Appointment displayConsultations();
		// generate a consulation ID
		long int generateID(Appointment);
		// displays all the services on the appointment
		void displayServices();
		// add service to the appointment by service ID
		void addService(Service);
		// hours X price
		double calculatePrice(Service);    
		// displaying current appointment details
		void displayAppointment();
		// save appointment
		void save();
		// abort 
		void abort();
	};
}

#endif