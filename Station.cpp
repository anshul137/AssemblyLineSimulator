
#include <iostream>
#include <string> 
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
using namespace std;
using namespace sdds;

//static 
int sdds::Station::m_widthField{ 0 };
int sdds::Station::id_generator{ 0 };

sdds::Station::Station() :m_station_id{ 0 }, m_item_name{}, m_station_des{}, m_serial_num{ 0 }, m_number_item_inStock{ 0 }
{
}

sdds::Station::Station(const std::string str) : Station()
{
	static int temp_id = 0;
	temp_id++;
	m_station_id = temp_id;
	std::string temp_str = str; // temp_copy of string
	size_t pos = 0; //position 
	std::string local_str; //local string
	bool temp_more = true;
	int temp_num = 0;
	Utilities temp_util_obj;
	m_item_name = temp_util_obj.extractToken(temp_str, pos, temp_more);
	local_str = temp_util_obj.extractToken(temp_str, pos, temp_more);
	m_serial_num = std::stoi(local_str);
	local_str = temp_util_obj.extractToken(temp_str, pos, temp_more);
	m_number_item_inStock = std::stoi(local_str);
	temp_num = temp_util_obj.getFieldWidth();

	if (Station::m_widthField < temp_num)
	{
		Station::m_widthField = temp_num;
	}

	m_station_des = temp_util_obj.extractToken(temp_str, pos, temp_more);

}

const std::string& sdds::Station::getItemName() const
{
	return m_item_name;
}

size_t sdds::Station::getNextSerialNumber()
{

	return m_serial_num++;
}

size_t sdds::Station::getQuantity() const
{
	return m_number_item_inStock;
}

void sdds::Station::updateQuantity()
{
	if (m_number_item_inStock > 0)
	{
		m_number_item_inStock--;

	}
}

void sdds::Station::display(std::ostream& os, bool full) const
{

	os << "[";
	os << std::setfill('0');
	os.width(3);
	os.setf(std::ios::right);
	os << m_station_id;
	os.unsetf(std::ios::right);
	os << setfill(' ');
	os << "] ";
	os << "Item: ";
	os.width(m_widthField);
	os.setf(std::ios::left);
	os << m_item_name;
	os.unsetf(std::ios::left);
	os << " [";
	os << std::setfill('0');
	os.width(6);
	os << m_serial_num;
	os << setfill(' ');
	os << "]";

	if (full)
	{
		os << " Quantity: ";
		os.width(m_widthField);
		os.setf(std::ios::left);
		os << m_number_item_inStock;
		os.unsetf(std::ios::left);
		os << " Description: ";
		os << m_station_des;
	}
	cout << endl;
}
