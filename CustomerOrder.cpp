
#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"


#include "Utilities.h"
#include "Station.h"


using namespace std;
using namespace sdds;

size_t sdds::CustomerOrder::m_widthField{ 0 };


sdds::CustomerOrder::CustomerOrder() : m_name{}, m_product{}, m_cntItem{ 0 }, m_lstItem{ nullptr }
{
}

sdds::CustomerOrder::CustomerOrder(const std::string& cus_str) : CustomerOrder()
{

	std::string temp_str_cus = cus_str; // temp_copy of string
	size_t pos = 0; //position 
	bool temp_more = true;
	size_t cnt = 0;

	std::string local_t;

	Utilities temp_util_obj;
	m_name = temp_util_obj.extractToken(temp_str_cus, pos, temp_more);
	m_product = temp_util_obj.extractToken(temp_str_cus, pos, temp_more);

	size_t oldpos = pos;

	// to get item
	while (temp_more != false)
	{
		local_t = temp_util_obj.extractToken(temp_str_cus, pos, temp_more);
		cnt++;
	}

	m_lstItem = new Item * [cnt];
	pos = oldpos;
	temp_more = true;

	// var = new Item (local_t);
	Item* var = nullptr;
	for (size_t i = 0; i < cnt; i++)
	{
		local_t = temp_util_obj.extractToken(temp_str_cus, pos, temp_more);
		var = new Item(local_t);
		m_lstItem[i] = (var);

	}

	m_cntItem = cnt;
	// to update the width

	if (CustomerOrder::m_widthField < temp_util_obj.getFieldWidth())
	{
		CustomerOrder::m_widthField = temp_util_obj.getFieldWidth();
	}
}

sdds::CustomerOrder::CustomerOrder(const CustomerOrder&)
{
	throw "Cannot make copies";
}

//need to fix

sdds::CustomerOrder::CustomerOrder(CustomerOrder&& cus_obj) noexcept : m_name{}, m_product{}, m_cntItem{ 0 }, m_lstItem{ nullptr }
{
	*this = std::move(cus_obj);
}

CustomerOrder& sdds::CustomerOrder::operator=(CustomerOrder&& cus_obj) noexcept
{
	if (this != &cus_obj)
	{

		for (auto i = 0u; i < m_cntItem; ++i)
			delete m_lstItem[i];
		delete[] m_lstItem;
		m_cntItem = cus_obj.m_cntItem;
		m_lstItem = cus_obj.m_lstItem;
		m_name = cus_obj.m_name;
		m_product = cus_obj.m_product;
		cus_obj.m_cntItem = 0;
		cus_obj.m_product = "";
		cus_obj.m_name = "";
		cus_obj.m_lstItem = nullptr;

	}
	return *this;
}

sdds::CustomerOrder::~CustomerOrder() {

	for (auto i = 0u; i < m_cntItem; ++i)
		delete m_lstItem[i];
	delete[] m_lstItem;
	m_lstItem = nullptr;

}

bool sdds::CustomerOrder::isFilled() const
{
	bool test = true;;
	for (auto i = 0u; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_isFilled == false)
		{
			test = false;

		}
	}
	return test;
}

bool sdds::CustomerOrder::isItemFilled(const std::string& itemName) const
{
	bool test = true;;
	for (auto i = 0u; i < m_cntItem; i++)
	{
		if ((m_lstItem[i]->m_itemName == itemName) && (m_lstItem[i]->m_isFilled == false))
		{
			test = false;

		}
	}
	return test;

}

void sdds::CustomerOrder::fillItem(sdds::Station& station, std::ostream& os)
{
	for (size_t i = 0; i < m_cntItem; i++)
	{
		if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() >= 1))
		{
			m_lstItem[i]->m_isFilled = true;
			m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
			station.updateQuantity();
			os << "    " << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;

		}
		else if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() <= 1))
		{
			os << "    " << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
		}

	}
}

void sdds::CustomerOrder::display(std::ostream& os) const
{
	os << m_name;
	os << " - ";
	os << m_product << endl;
	for (size_t i = 0; i < m_cntItem; i++)
	{

		os << "[";
		os << std::setfill('0');
		os.width(6);
		os << m_lstItem[i]->m_serialNumber;
		os << std::setfill(' ');
		os << "] ";
		os.width(m_widthField);
		os.setf(std::ios::left);
		os << m_lstItem[i]->m_itemName;
		os.unsetf(std::ios::left);
		os << " - ";
		if (m_lstItem[i]->m_isFilled)
		{
			os << "FILLED";

		}
		else
		{
			os << "TO BE FILLED";
		}
		os << endl;

	}

}
