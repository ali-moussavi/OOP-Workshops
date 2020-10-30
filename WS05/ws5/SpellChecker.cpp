//Student name : Seyed Mohammad Ali Lohmousavi
//Student num : 159309186
//Seneca ID : smalohmousavi

#include <fstream>

#include "SpellChecker.h"
#include "Utils.h"
using namespace std;

namespace sdds {


	SpellChecker::SpellChecker()
	{
	}

	SpellChecker::SpellChecker(const char* filename) {

		ifstream f(filename);
		if (f.is_open())
		{
			string line = "";
			int i = 0;
			while (std::getline(f, line, '\n') && i < 5)
			{
				line = trim<string>(line);
				this->m_badWords[i] = trim<string>(line.substr(0, line.find(' ')));
				line.erase(0, line.find(' ') + 1);
				this->m_goodWords[i] = trim<string>(line);
				i++;
			}
			f.close();
		}
		else
		{
			throw "Bad file name!";
		}

	}

	SpellChecker::~SpellChecker()
	{
	}

	void SpellChecker::operator()(std::string& text) const
	{
		for (size_t i = 0; i < 5; i++)
		{
			std::string::size_type n = 0;
			while (n != string::npos)
			{
				n = text.find(this->m_badWords[i]);
				if (n != string::npos) {
					text.replace(n, m_badWords[i].length(), m_goodWords[i]);
				}
			}
			
		}
	}
}

