#include <string>
#include <iostream>
#include "Restaurant.h"


using namespace std;

namespace sdds {
	ostream& operator<<(ostream& os, const Restaurant& r)
	{
		os << "--------------------------\n" << "Fancy Restaurant\n--------------------------" << endl;
		if (r.size() > 0)
		{
			for (size_t i = 0; i < r.size(); i++)
			{
				os << r.reservations[i];
			}
		}
		else
		{
			os << "The object is empty!\n";
		}

		os << "--------------------------" << endl;

		return os;
	}


	Restaurant::Restaurant()
	{
		reservations = nullptr;
		numberOfReservations = 0;
	}

	Restaurant::Restaurant(Restaurant& src)
	{
		reservations = nullptr;
		numberOfReservations = 0;
		if (src.numberOfReservations > 0)
		{
			numberOfReservations = src.numberOfReservations;
			reservations = new Reservation[src.numberOfReservations];
			for (size_t i = 0; i < numberOfReservations; i++)
			{
				reservations[i] = src.reservations[i];
			}
		}
	}

	Restaurant::Restaurant(Restaurant&& src)
	{
		reservations = nullptr;
		numberOfReservations = 0;
		if (src.numberOfReservations > 0)
		{
			numberOfReservations = src.numberOfReservations;
			src.numberOfReservations = 0;
			reservations = src.reservations;
			src.reservations = nullptr;
		}
	}

	Restaurant::Restaurant(Reservation* reservations_[], size_t cnt)
	{
		numberOfReservations = 0;
		reservations = nullptr;
		reservations = new Reservation[cnt];

		for (size_t i = 0; i < cnt; i++)
		{
			reservations[numberOfReservations++] = *reservations_[i];
		}
	}



	Restaurant::~Restaurant()
	{
		if (reservations != nullptr)
		{
			delete[] reservations;
			reservations = nullptr;
		}
	}

	size_t Restaurant::size() const
	{
		return numberOfReservations;
	}
}

