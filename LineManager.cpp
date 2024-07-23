//==============================================
// Name:           Anshul Gandhi
// Student Number: 140953191	
// Email:          agandhi29@myseneca.ca
// Section:        BTP305-NAA

// Date:		   4-dec-2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "LineManager.h"
#include "Utilities.h"
#include "Workstation.h"
using namespace std;
using namespace sdds;


sdds::LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
{
	std::ifstream n_file(file);

	if (!n_file)
	{
		std::cerr << "ERROR: Cannot open file [" << file << "].\n";
	}
	std::string new_data;
	Utilities temp_util;
	size_t pos;
	bool more;
	std::string new_item_name_1;
	size_t cnt = 0;




	auto lamda_func = [&new_item_name_1](const Workstation* w1)
	{
		bool test = false;


		if (w1->getItemName() == new_item_name_1)
		{
			test = true;
		}

		return test;
	};




	auto lamda_func2 = [=](const Workstation* w2)
	{

		bool test1 = false;
		std::string fn_test = w2->getItemName();

		auto it2 = [fn_test](const Workstation* w3)
		{
			bool test = true;
			Workstation* temp_w = w3->getNextStation();

			if (temp_w != nullptr)
			{
				if (temp_w->getItemName() != fn_test)
				{
					test = false;
				}

			}
			return test;
		};
		Workstation* temp_lamb_w = *(find_if(activeLine.begin(), activeLine.end(), it2));
		if (temp_lamb_w)
		{
			test1 = true;
		}
		return test1;
	};

	m_cntCustomerOrder = pending.size();


	while (!n_file.eof())
	{
		pos = 0;
		more = true;
		getline(n_file, new_data);
		new_item_name_1 = temp_util.extractToken(new_data, pos, more);


		activeLine.push_back(*(std::find_if(stations.begin(), stations.end(), lamda_func)));

		if (more)
		{
			new_item_name_1 = temp_util.extractToken(new_data, pos, more);
			activeLine[cnt]->setNextStation(*(std::find_if(stations.begin(), stations.end(), lamda_func)));
		}
		cnt++;
	}




	m_firstStation = *(std::find_if(stations.begin(), stations.end(), lamda_func2));


}



void sdds::LineManager::linkStations()
{
	std::vector<Workstation*> temp_vector;

	Workstation* new_temp_work = m_firstStation;

	while (new_temp_work->getNextStation() != nullptr)
	{
		temp_vector.push_back(new_temp_work);

		new_temp_work = new_temp_work->getNextStation();



	}

	temp_vector.push_back(new_temp_work);

	activeLine = temp_vector;
}


bool sdds::LineManager::run(std::ostream& os)
{
	bool test = false;
	static size_t num_of_count{ 1 };
	os << "Line Manager Iteration: " << num_of_count << endl;

	if (!pending.empty())
	{
		*m_firstStation += std::move(pending.front());
		pending.pop_front();
	}

	for (size_t i = 0; i < activeLine.size(); i++)
	{
		activeLine[i]->fill(os);
	}

	for (size_t i = 0; i < activeLine.size(); i++)
	{
		activeLine[i]->attemptToMoveOrder();
	}

	if (completed.size() + incomplete.size() == m_cntCustomerOrder)
	{
		test = true;
	}
	++num_of_count;
	return test;
}

void sdds::LineManager::display(std::ostream& os) const
{
	for (auto i = activeLine.begin(); i < activeLine.end(); ++i)
	{
		(*i)->display(os);
	}
}
