#define _CRT_SECURE_NO_WARNINGS

#include "Workstation.h"
std::deque<sdds::CustomerOrder> g_pending{};
std::deque<sdds::CustomerOrder> g_completed{};
std::deque<sdds::CustomerOrder> g_incomplete{};

namespace sdds {
	Workstation::Workstation(const std::string& str) : Station(str) {}

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) 
			m_orders.front().fillItem(*this, os);
		
	}

	bool Workstation::attemptToMoveOrder() {
		if (m_orders.empty())
			return false;
		CustomerOrder& order = m_orders.front();
		if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0) {
			// if there is next station, move object there
			if (m_pNextStation != nullptr)
				*m_pNextStation += (std::move(order));
			// if at the end of manager line
			else {
				// if complete as all orders filled, move to g_complete
				if (order.isOrderFilled())
					g_completed.push_back(std::move(order));
				// if not, move to g_incomplete
				else
					g_incomplete.push_back(std::move(order));
			}
			// finished ealing with front, pop order out of queue
			m_orders.pop_front();
			return true;
		}
		return false;
	}

	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << getItemName();
		os << " --> ";

		if (m_pNextStation == nullptr)
		{
			os << "End of Line";
		}

		else
		{
			os << m_pNextStation->getItemName();
		}
		os << std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
	bool Workstation::empty() const
	{
		return m_orders.empty();
	}

}
