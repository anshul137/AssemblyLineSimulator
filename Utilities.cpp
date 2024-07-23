

#include <iostream>


#include "Utilities.h"
using namespace std;
using namespace sdds;




//static 
char sdds::Utilities::m_delimiter{};


sdds::Utilities::Utilities() :m_widthField{ 1 }
{
}

void sdds::Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth;
}

size_t sdds::Utilities::getFieldWidth() const
{
	return m_widthField;
}

std::string sdds::Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string token;

	if (str[next_pos] != m_delimiter)
	{
		size_t temp_ = str.find(m_delimiter, next_pos);
		if (temp_ != std::string::npos)
		{
			size_t _size = temp_ - next_pos;
			token = str.substr(next_pos, _size);
			next_pos += _size + 1;
			
			if (str.length() <next_pos)
			{
				more = false;
			}
			else
				more = true;
		}
		else
		{
			token = str.substr(next_pos);
			more = false;
		}
		if (m_widthField < token.length())
		{
			m_widthField = token.length();
		}
		return token;
	}
	else
	{
		more = false;
		next_pos++;
		throw "No token";

	}
}

void sdds::Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}

char sdds::Utilities::getDelimiter()
{
	return m_delimiter;
}
