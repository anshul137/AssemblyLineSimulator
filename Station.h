//==============================================
// Name:           Anshul Gandhi
// Student Number: 140953191	
// Email:          agandhi29@myseneca.ca
// Section:        BTP305-NAA

// Date:		   4-dec-2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

namespace sdds {

	class Station {
		int m_station_id;
		std::string m_item_name;
		std::string m_station_des;
		int m_serial_num;
		int m_number_item_inStock;
		static int m_widthField;
		static int id_generator;
	public:
		Station();
		Station(const std::string str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
		~Station() {};

	};

}
#endif // !SDDS_STATION_H
