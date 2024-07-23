
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include "Station.h"
namespace sdds
{
	class CustomerOrder
	{
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;
	public:
		CustomerOrder();
		explicit CustomerOrder(const std::string& cus_str);
		explicit CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator = (const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&& cus_obj) noexcept;
		CustomerOrder& operator=(CustomerOrder&& cus_order) noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(sdds::Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};


}
#endif // !SDDS_CUSTOMERORDER_H


