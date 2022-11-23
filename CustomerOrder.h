#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <iostream>
#include "Station.h"

namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};
	class CustomerOrder {

		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;
	public:
		CustomerOrder(const std::string& src);

		CustomerOrder();
		~CustomerOrder();
		//a CustomerOrder object should not allow copy operations. The copy constructor should throw an exception if called and the copy operator= should be deleted.
		CustomerOrder& operator=(CustomerOrder& src) = delete;
		//a move constructor. This constructor should "promise" that it doesn't throw exceptions. Use the noexcept keyword in the declaration and the definition.
		CustomerOrder(CustomerOrder&& src) noexcept;
		//a move assignment operator. This operator should "promise" that it doesn't throw exceptions. Use the noexcept keyword in the declaration and the definition.
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;
		//returns true if all the items in the order have been filled; false otherwise
		bool isOrderFilled() const;
		// returns true if all items specified by itemName have been filled. If the item doesn't exist in the order, this query returns true.
		bool isItemFilled(const std::string& itemName) const;
		//this modifier fills one item in the current order that the Station specified in the first parameter handles.
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif