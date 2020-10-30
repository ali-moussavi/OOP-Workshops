//Student name : Seyed Mohammad Ali Lohmousavi
//Student num : 159309186
//Seneca ID : smalohmousavi

#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace sdds {
	class Book
	{
	public:
		Book();
		Book(const string& strBook);
		Book(const Book& src);
		Book(Book&& src);
		~Book();
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book& operator=(const Book& src);
		Book& operator=(Book&& src);
		friend ostream& operator<<(ostream& os, const Book& b);
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_summary);
		}

	private:
		string m_author;
		string m_title;
		string m_country;
		size_t m_year;
		double m_price;
		string m_summary;
	};

	
}