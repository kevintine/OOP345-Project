#define _CRT_SECURE_NO_WARNINGS

#include "CustomerOrder.h"

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder() {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	CustomerOrder::~CustomerOrder() {
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {

	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {

	}
	bool CustomerOrder::isOrderFilled() const {

	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {

	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {

	}
	void CustomerOrder::display(std::ostream& os) const {

	}
}