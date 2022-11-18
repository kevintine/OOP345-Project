#ifndef SDDS_UICONTROLLER_H
#define SDDS_UICONTROLLER_H
#include <iostream>

#include "Appointment.h"
#include "Service.h"
#include "Supplier.h"

namespace sdds {
	class UIController {
	private:
		void requestAddAppointment();
		// selects by supplier ID
		void selectSupplier(Supplier);
		// date selection
		void enterDate(Appointment);
		// selects appointment by time
		void selectTime(Appointment);
		// select services that apply
		void serviceSelector(Service);
		// saves appointment
		void save();
		// return to main menu
		void returnMainMenu();
		// abort 
		void abort();
	};
}

#endif