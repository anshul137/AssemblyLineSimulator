//==============================================
// Name:           Anshul Gandhi
// Student Number: 140953191	
// Email:          agandhi29@myseneca.ca
// Section:        BTP305-NAA

// Date:		   4-dec-2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
namespace sdds
{
	class Utilities
	{
		size_t m_widthField;
		static char m_delimiter;

	public:
		Utilities();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
		~Utilities() {};
	};

}
#endif // !SDDS_UTILITIES_H



