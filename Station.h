#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

namespace sdds {
	class Station {
		int station_id;
		std::string item_name;
		std::string station_description;
		size_t serial_num;
		size_t stock;
		// class variables
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(std::string str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif