#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include "Station.h"
#include "CustomerOrder.h"
#include <deque>

extern std::deque<sdds::CustomerOrder> g_pending;
extern std::deque<sdds::CustomerOrder> g_completed;
extern std::deque<sdds::CustomerOrder> g_incomplete;

namespace sdds {
	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation{};

	public:
		Workstation(const std::string& str);
		Workstation(const Workstation& src) = delete;
		Workstation(Workstation&& src) = delete;
		Workstation& operator=(const Workstation& src) = delete;
		Workstation& operator=(Workstation& src) = delete;

		~Workstation() {}

		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
		bool empty() const;
	};
}

#endif