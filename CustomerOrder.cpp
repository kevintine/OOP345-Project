#define _CRT_SECURE_NO_WARNINGS

#include "Utilities.h"
#include "CustomerOrder.h"
#include <algorithm>
#include <string>
#include <iomanip>

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder() {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	CustomerOrder::~CustomerOrder() {
		if (m_lstItem) {
			for (size_t i = 0; i < m_cntItem; i++)
				delete m_lstItem[i];
			delete[] m_lstItem;
		}
		m_lstItem = nullptr;
	}
	CustomerOrder::CustomerOrder(std::string& input) {
		size_t curr_pos = 0;
		bool ok = true;
		Utilities utilities;

		if (input.length() < 0)
			return;

		m_name = utilities.extractToken(input, curr_pos, ok);
		m_product = utilities.extractToken(input, curr_pos, ok);
		m_cntItem = std::count(input.begin(), input.end(), utilities.getDelimiter()) - 1;
		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++) {
			Item* temp = new Item(utilities.extractToken(input, curr_pos, ok));
			m_lstItem[i] = std::move(temp);
			temp = nullptr;
		}
		if (CustomerOrder::m_widthField < utilities.getFieldWidth())
			CustomerOrder::m_widthField = utilities.getFieldWidth();
	}
	CustomerOrder::CustomerOrder(CustomerOrder& src) {
		throw "ERROR: Cannot make copies.";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
		*this = std::move(src);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
		if (this == &src)
			return *this;
		if (m_lstItem) {
			for (size_t i = 0; i < m_cntItem; i++)
				delete m_lstItem[i];
			delete[] m_lstItem;
		}
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;

		src.m_name = "";
		src.m_product = "";
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;

		return *this;
	}
	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == false)
				return false;
		}
		return true;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName)
				if (m_lstItem[i]->m_isFilled == false)
					return false;
		}
		return true;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled == false && m_lstItem[i]->m_itemName == station.getItemName()) {

				if (station.getQuantity() > 0)
				{
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << std::setw(11) << std::right;
					os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";

					break;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
				}
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const {
		if (m_lstItem) {
			os << m_name << " - " << m_product << std::endl;
			for (size_t i = 0; i < m_cntItem; i++) {
				os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] "
					<< std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName
					<< "   - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
			}
		}
	}
}