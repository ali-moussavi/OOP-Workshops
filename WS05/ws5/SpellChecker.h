#pragma once
#include <iostream>
#include <string>


using namespace std;

namespace sdds {

	class SpellChecker
	{
	public:
		SpellChecker();
		SpellChecker(const char* filename);
		~SpellChecker();
		void operator()(std::string& text) const;
		

	private:
		string m_badWords[5]{};
		string m_goodWords[5]{};
	};

	string trim(const string& str);
}