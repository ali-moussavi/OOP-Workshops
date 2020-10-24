#pragma once

#include "Reservation.h"

using namespace std;

namespace sdds {
	class ConfirmationSender
	{
	public:
		ConfirmationSender();
		ConfirmationSender(ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator<<(ostream& os, const ConfirmationSender& c);

	private:
		const Reservation** reservations;
		size_t numberOfReservations;
	};

	
}