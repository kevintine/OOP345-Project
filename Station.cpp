#define _CRT_SECURE_NO_WARNINGS

#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <algorithm> 
#include <iomanip>


namespace sdds {
	size_t Station::m_widthField = 1;
	size_t Station::id_generator = 1;
	Station::Station(std::string str) {
		Utilities utilities;
		size_t pos = 0;
		bool ok = true;
		station_id = id_generator++;
		item_name = utilities.extractToken(str, pos, ok);
		serial_num = std::stoi(utilities.extractToken(str, pos, ok));
		stock = std::stoi(utilities.extractToken(str, pos, ok));
		m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
		station_description = utilities.extractToken(str, pos, ok);
	}
	const std::string& Station::getItemName() const {
		return item_name;
	}
	size_t Station::getNextSerialNumber() {
		return serial_num++;
	}
	size_t Station::getQuantity() const {
		return stock;
	}
	void Station::updateQuantity() {
		if (stock == 0) {
			return;
			throw "Cannot drop below 0";
		}
		else
			stock -= 1;

	}
	void Station::display(std::ostream& os, bool full) const {
		os << std::right;
		os << std::setw(3) << std::setfill('0') << station_id << " | ";
		os << std::left << std::setfill(' ') << std::setw(m_widthField + 1) << item_name << " | ";
		os << std::right << std::setw(6) << std::setfill('0') << serial_num << " | ";

		if (full)
		{
			os << std::setfill(' ');
			os << std::right;
			os << std::setw(4) << stock << " | " << station_description;
		}
		os << "\n";
	}
}