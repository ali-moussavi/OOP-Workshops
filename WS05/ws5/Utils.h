//Student name : Seyed Mohammad Ali Lohmousavi
//Student num : 159309186
//Seneca ID : smalohmousavi

#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace sdds {

	template<typename T>
	T trim(const T& str)
	{
		const size_t strBegin = str.find_first_not_of(" ");
		if (strBegin == T::npos)
			return ""; // no content

		const size_t strEnd = str.find_last_not_of(" ");
		const size_t strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}
}