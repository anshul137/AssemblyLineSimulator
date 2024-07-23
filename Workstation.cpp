

#include <iostream>
#include<deque>


#include"Workstation.h"
#include "Station.h"
#include "CustomerOrder.h"
using namespace std;
using namespace sdds;

std::deque<CustomerOrder> pending{};
std::deque<CustomerOrder> completed{};
std::deque<CustomerOrder> incomplete{};



sdds::Workstation::Workstation(const std::string& str) :Station{ str }
{

}

void sdds::Workstation::fill(std::ostream& os)
{
	if (m_orders.size() > 0)
	{

		m_orders.front().fillItem(*this, os);
	}

}

bool sdds::Workstation::attemptToMoveOrder()
{
	bool test = false;
	if (m_orders.empty())
	{
		return false;
	}

	if (m_pNextStation && m_orders.front().isItemFilled(getItemName()))
	{
		*m_pNextStation += std::move(m_orders.front());
		m_orders.pop_front();
	}
	else if (!m_pNextStation && m_orders.front().isItemFilled(getItemName()))
	{

		if (m_orders.front().isFilled())
		{
			completed.push_back(std::move(m_orders.front()));
			m_orders.pop_front();

		}
		else
		{
			incomplete.push_back(std::move(m_orders.front()));
			m_orders.pop_front();
		}
	}
	else if (getQuantity() == 0)
	{

		if (!m_pNextStation) {
			incomplete.push_back(std::move(m_orders.front()));
		}
		else
		{
			*m_pNextStation += std::move(m_orders.front());

		}
		m_orders.pop_front();
		test = true;
	}
	return test;
}


void sdds::Workstation::setNextStation(Workstation* station)
{
	m_pNextStation = station;

}

Workstation* sdds::Workstation::getNextStation() const
{
	return m_pNextStation;
}

void sdds::Workstation::display(std::ostream& os) const
{
	if (m_pNextStation == nullptr)
	{
		os << this->getItemName() << " --> End of Line" << endl;
	}
	else
	{
		os << this->getItemName() << " --> " << m_pNextStation->Station::getItemName() << endl;
	}
}

Workstation& sdds::Workstation::operator+=(CustomerOrder&& newOrder)
{
	m_orders.push_back(std::move(newOrder));
	return *this;
}
