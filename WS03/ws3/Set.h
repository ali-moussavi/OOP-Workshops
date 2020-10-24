#pragma once
#include <iostream>

namespace sdds {

	template<typename T,unsigned N>
	class Set
	{
	public:
		Set() { numberOfMembers = 0u; }
		
		size_t size() const {
			return numberOfMembers;
		}
		const T& operator[](size_t idx) const {
			return a[idx];
		}

		void operator+=(const T& item) {
			if (numberOfMembers < N )
			{
				a[numberOfMembers++] = item;
			}
		}
	private:
		T a[N];
		size_t numberOfMembers;
	};

}