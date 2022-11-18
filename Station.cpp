#define _CRT_SECURE_NO_WARNINGS

#include "Station.h"


namespace sdds {
	Station::Station(std::string str) {

	}
	const std::string& Station::getItemName() const {
		return item_name;
	}
	size_t Station::getNextSerialNumber() {
		return serial_num;
	}
	size_t Station::getQuantity() const {
		return stock;
	}
	void Station::updateQuantity() {
		if (stock == 0)
			throw "Cannot drop below 0";

		else
			stock -= 1;

	}
	void Station::display(std::ostream& os, bool full) const {
		os << "ID | NAME | SERIAL | QUANTITY | DESCRIPTION\n";
	}
}