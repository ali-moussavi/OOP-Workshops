//Student name : Seyed Mohammad Ali Lohmousavi
//Student num : 159309186
//Seneca ID : smalohmousavi

#include <iomanip>
#include "Movie.h"
#include "Utils.h"
using namespace std;

namespace sdds {

	

	Movie::Movie()
	{
		m_title = "";
		m_description = "";
		m_year = 0;
	}

	Movie::Movie(const Movie& src)
	{
		*this = src;
	}

	Movie::Movie(Movie&& src)
	{
		*this = move(src);
	}

	Movie::Movie(const std::string& strMovie)
	{
		string temp = strMovie;

		m_title = trim<string>(temp.substr(0, temp.find(','))).c_str();
		temp.erase(0, temp.find(',') + 1);
		m_year = stoi(trim<string>(temp.substr(0, temp.find(','))));
		temp.erase(0, temp.find(',') + 1);
		m_description = trim<string>(temp);
	}

	Movie::~Movie(){

	}
	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie& Movie::operator=(const Movie& src)
	{
		if (this != &src)
		{
			if (src.m_year > 0) {
				m_title = src.m_title;
				m_year = src.m_year;
				m_description = src.m_description;

			}
		}

		return *this;
	}

	Movie& Movie::operator=(Movie&& src)
	{
		if (this != &src)
		{
			if (src.m_year> 0) {
				m_title = src.m_title;
				m_year = src.m_year;
				m_description = src.m_description;
				src.m_title = "";
				src.m_year = 0;
				src.m_description = "";
			}
		}

		return *this;
	}

	ostream& operator<<(ostream& os, const Movie& m)
	{
		os << setw(40) << right << m.m_title << " | " << setw(4) << m.m_year <<
			" | " << m.m_description << endl;

		return os;
	}
}