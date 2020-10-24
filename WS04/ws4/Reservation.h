#pragma once
#include <string>
using namespace std;

namespace sdds {
	class Reservation
	{
	public:
		Reservation();
		Reservation(const std::string& res);
		~Reservation();
		friend ostream& operator<<(ostream& os, const Reservation& r);

	private:
		char id[8];
		string name;
		string email;
		size_t numberOfPeople;
		size_t day; //between 1 and 31
		size_t hour; //between 1 and 24
	};

	//helper function
	string trim(const string& str);
}