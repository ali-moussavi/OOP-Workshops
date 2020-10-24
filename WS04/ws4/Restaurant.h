#pragma once

#include "Reservation.h"
namespace sdds {
	class Restaurant
	{
	public:
		Restaurant();
		Restaurant(Restaurant& src);
		Restaurant(Restaurant&& src);
		Restaurant(Reservation* reservations[], size_t cnt);
		~Restaurant();
		size_t size() const;
		friend ostream& operator<<(ostream& os, const Restaurant& r);

	private:
		Reservation* reservations;
		size_t numberOfReservations;
	};

	
}