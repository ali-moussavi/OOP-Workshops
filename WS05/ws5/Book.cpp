//Student name : Seyed Mohammad Ali Lohmousavi
//Student num : 159309186
//Seneca ID : smalohmousavi


#include <iomanip>
#include "Book.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	ostream& operator<<(ostream& os, const Book& b)
	{
		os << setw(20) << right << b.m_author << " | " << setw(22) << right <<
			b.m_title << " | " << setw(5) << b.m_country << " | " << setw(4) << b.m_year <<
			" | " << setw(6) << fixed <<setprecision(2) << b.m_price << " | " << b.m_summary << endl;

		return os;
	}


	

	Book::Book() {
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0;
		m_summary = "";
	}

	Book::Book(const string& strBook)
	{
		string temp = strBook;

		m_author = trim<string>(temp.substr(0, temp.find(','))).c_str();
		temp.erase(0, temp.find(',') + 1);
		m_title = trim<string>(temp.substr(0, temp.find(',')));
		temp.erase(0, temp.find(',') + 1);
		m_country = trim<string>(temp.substr(0, temp.find(',')));
		temp.erase(0, temp.find(',') + 1);
		m_price = stod(trim<string>(temp.substr(0, temp.find(','))));
		temp.erase(0, temp.find(',') + 1);
		m_year = stoi(trim<string>(temp.substr(0, temp.find(','))));
		temp.erase(0, temp.find(',') + 1);
		m_summary = trim<string>(temp);
	}

	Book::Book(const Book& src)
	{
		*this = src;
	}

	Book::Book(Book&& src)
	{
		*this = move(src);
	}

	Book::~Book() {

	}

	const string& Book::title() const
	{
		return m_title;
	}

	const string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	Book& Book::operator=(const Book& src)
	{
		if (this != &src)
		{
			if (src.year() > 0) {
				m_author = src.m_author;
				m_title = src.m_title;
				m_country = src.m_country;
				m_year = src.m_year;
				m_price = src.m_price;
				m_summary = src.m_summary;
				
			}
		}

		return *this;
	}

	Book& Book::operator=(Book&& src)
	{
		if (this != &src)
		{
			if (src.year() > 0) {
				m_author = src.m_author;
				m_title = src.m_title;
				m_country = src.m_country;
				m_year = src.m_year;
				m_price = src.m_price;
				m_summary = src.m_summary;
				src.m_author = "";
				src.m_title = "";
				src.m_country = "";
				src.m_year = 0;
				src.m_price = 0;
				src.m_summary = "";
			}
		}

		return *this;
	}

	

}