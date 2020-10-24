#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

namespace sdds {

	class RecordSet
	{
	public:
		RecordSet();
		RecordSet(char* fileName);
		RecordSet(const RecordSet& src);
		RecordSet(RecordSet&& src);
		~RecordSet();
		size_t size() const;
		string getRecord(size_t i) const;
		RecordSet& operator=(const RecordSet& src);
		RecordSet& operator=(RecordSet&& src);


	private:
		string* words;
		size_t numberOfWords{ 0 };
		void deleteWords();

	};

	
}


