#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <string.h>
#include <iostream>
#include <iomanip> 
#include "Reservation.h"

using namespace std;

namespace sdds {

	//a hepler function that trims whitespace from beginnig and end of strings
	string trim(const string& str)
	{
		const size_t strBegin = str.find_first_not_of(" ");
		if (strBegin == string::npos)
			return ""; // no content

		const size_t strEnd = str.find_last_not_of(" ");
		const size_t strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}

	Reservation::Reservation()
	{
		id[0] = '\0';
		name = "";
		email = "";
		numberOfPeople = 0;
		day = 0;
		hour = 0;
	}

	Reservation::Reservation(const std::string& res) {
		string temp = res;

		

		strcpy(id, trim(temp.substr(0, temp.find(':'))).c_str());
		temp.erase(0, temp.find(':') + 1);
		name = trim(temp.substr(0, temp.find(',')));
		temp.erase(0, temp.find(',') + 1);
		email = trim(temp.substr(0, temp.find(',')));
		temp.erase(0, temp.find(',') + 1);
		numberOfPeople = stoi(trim(temp.substr(0, temp.find(','))));
		temp.erase(0, temp.find(',') + 1);
		day = stoi(trim(temp.substr(0, temp.find(','))));
		temp.erase(0, temp.find(',') + 1);
		hour = stoi(trim(temp));
	}

	Reservation::~Reservation()
	{
	}


	ostream& operator<<(ostream& os, const Reservation& r)
	{
		string suitableMeal;

		if (r.hour >= 6 && r.hour <= 9)
		{
			suitableMeal = "Breakfast";
		}
		else if (r.hour >= 11 && r.hour <= 15)
		{
			suitableMeal = "Lunch";
		}
		else if (r.hour >= 17 && r.hour <= 21)
		{
			suitableMeal = "Dinner";
		}
		else
		{
			suitableMeal = "Drinks";
		}

		os << "Reservation " << r.id << ":" << right << setw(11) << r.name << "  " << left << setw(20) << "<" + r.email + ">" << "    " << suitableMeal << " on day " << r.day << " @ " << r.hour << ":00 for " << r.numberOfPeople << " people." << endl;

		return os;
	}
}


