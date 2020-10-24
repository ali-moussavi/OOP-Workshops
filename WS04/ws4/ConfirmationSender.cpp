#include <string>
#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {
	ConfirmationSender::ConfirmationSender()
	{
		reservations = nullptr;
		numberOfReservations = 0;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender& src)
	{
		reservations = nullptr;
		numberOfReservations = 0;
		if (src.numberOfReservations > 0)
		{
			numberOfReservations = src.numberOfReservations;
			reservations = new const Reservation * [src.numberOfReservations];
			for (size_t i = 0; i < numberOfReservations; i++)
			{
				reservations[i] = src.reservations[i];
			}
		}
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
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

	ConfirmationSender::~ConfirmationSender()
	{
		if (reservations != nullptr)
		{
			delete[] reservations;
			reservations = nullptr;
		}
	}


	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool haveResAlready = false;
		for (size_t i = 0; i < numberOfReservations; i++)
		{
			if (reservations[i] == &res)
			{
				haveResAlready = true;
				break;
			}
		}

		if (!haveResAlready)
		{
			const Reservation** temp;
			temp = new const Reservation * [++numberOfReservations];
			for (size_t i = 0; i < numberOfReservations - 1; i++)
			{
				temp[i] = reservations[i];
			}

			temp[numberOfReservations - 1] = &res;
			if (reservations != nullptr)
			{
				delete[] reservations;
			}
			reservations = temp;

		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		
		for (size_t i = 0; i < numberOfReservations; i++)
		{
			if (reservations[i] == &res)
			{
				reservations[i] = nullptr;
				break;
			}
		}


		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& c)
	{
		os << "--------------------------\n" << "Confirmations to Send\n--------------------------" << endl;
		if (c.numberOfReservations == 0)
		{
			os << "The object is empty!\n";
		}

		else
		{
			for (size_t i = 0; i < c.numberOfReservations; i++)
			{
				if (c.reservations[i] != nullptr)
				{
					os << *(c.reservations[i]);
				}

			}
		}
		os << "--------------------------" << endl;
		return os;
	}

}

