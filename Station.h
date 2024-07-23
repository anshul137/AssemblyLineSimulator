
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
