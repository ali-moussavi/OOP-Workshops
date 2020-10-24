#pragma once

#include"Set.h"

namespace sdds {
	template<typename T, unsigned N>
	class SetSummable : public Set<T, N>
	{
	public:
		
		
		T accumulate(const std::string& filter) const {
			T temp(filter);
			for (size_t i = 0; i < this->size(); i++)
			{		
					temp += (*this)[i] ;
			}

			return temp;
		}
	
		
	};

	
}
