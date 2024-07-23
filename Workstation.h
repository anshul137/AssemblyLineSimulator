//==============================================
// Name:           Anshul Gandhi
// Student Number: 140953191	
// Email:          agandhi29@myseneca.ca
// Section:        BTP305-NAA

// Date:		   4-dec-2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include<iostream>
#include <deque>

#include"Station.h"
#include"CustomerOrder.h"

extern std::deque<sdds::CustomerOrder> pending;
extern std::deque<sdds::CustomerOrder> completed;
extern std::deque<sdds::CustomerOrder> incomplete;

namespace sdds
{


	class Workstation :public Station
	{
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{ nullptr };
	public:
		Workstation() {};
		Workstation(const std::string& str);
		//copy constructor 
		Workstation(Workstation&) = delete;
		//copy assignment delete
		Workstation& operator=(Workstation&) = delete;
		//move cosntructor delete
		Workstation(Workstation&&) = delete;
		//move opertor
		Workstation& operator=(Workstation&&) = delete;

		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
		~Workstation() {};
	};


}

#endif // !SDDS_WORKSTATION_H
