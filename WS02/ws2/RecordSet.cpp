#include "RecordSet.h"

using namespace std;

namespace sdds {
	RecordSet::RecordSet() {
		words = nullptr;
		numberOfWords = 0;
	}

	RecordSet::RecordSet(const RecordSet& src) {
		words = nullptr;
		*this = src;
	}

	RecordSet::RecordSet(char* fileName) {
		words = nullptr;
		ifstream f(fileName);
		string word = "";
		int wordCount = 0;
		if (f.is_open())
		{


			while (getline(f,word,' '))
			{
				wordCount++;
			}
		}

		numberOfWords = wordCount;
		words = new string[wordCount];

		f.clear();
		f.seekg(0);

		if (f.is_open())
		{
			long int i = 0;
			while (getline(f, word, ' '))
			{
				words[i++] = word;
			}
		}

	}

	RecordSet::RecordSet(RecordSet&& src) {
		words = nullptr;
		*this = move(src);
		
	}


	RecordSet& RecordSet::operator=(const RecordSet& src) {
		if (this != &src)
		{
			if (words != nullptr || src.words == nullptr)
			{
				deleteWords();
				numberOfWords = 0;
			}
			else
			{
				numberOfWords = src.size();
				words = new string[src.size()];
				for (size_t i = 0; i < src.size(); i++)
				{
					words[i] = src.getRecord(i);
				}
			}

		}

		return *this;
	}

	RecordSet& RecordSet::operator=(RecordSet&& src) {
		if (this != &src)
		{
			if (words != nullptr || src.words == nullptr)
			{
				deleteWords();
				numberOfWords = 0;
			}
			if (src.words != nullptr)
			{
				numberOfWords = src.size();
				src.numberOfWords = 0;
				words = src.words;
				src.words = nullptr;
			}

		}

		return *this;
	}


	RecordSet::~RecordSet()
	{
		deleteWords();
	}

	size_t RecordSet::size() const {
		return numberOfWords;
	}

	string RecordSet::getRecord(size_t i) const {
		if (words != nullptr && i < size())
		{
			return words[i];
		}
		else
		{
			return "";
		}
	}

	void RecordSet::deleteWords() {
		if (words != nullptr)
		{
			delete[] words;
			
		}
	}
}