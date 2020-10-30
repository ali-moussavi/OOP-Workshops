//Student name : Seyed Mohammad Ali Lohmousavi
//Student num : 159309186
//Seneca ID : smalohmousavi

#pragma once
#include <iostream>
#include <string>


using namespace std;

namespace sdds {

	class Movie
	{
	public:
		Movie();
		Movie(const Movie& src);
		Movie(Movie&& src);
		Movie(const std::string& strMovie);
		~Movie();
		const std::string& title() const;
		Movie& operator=(const Movie& src);
		Movie& operator=(Movie&& src);
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend ostream& operator<<(ostream& os, const Movie& m);

	private:
		string m_title;
		size_t m_year;
		string m_description;
	};

}