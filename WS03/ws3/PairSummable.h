#pragma once
#include <iomanip>
#include "Pair.h"
#include <typeinfo>

using namespace std;

namespace sdds {
	template<typename K, typename V>
	class PairSummable : public Pair<K , V>
	{
	public:
		PairSummable(){
			minFieldWidth = 0;
		}

		PairSummable(const K& key, const V& value = initial) : Pair<K, V>(key, value) {

			if (key.size() > minFieldWidth)
			{
				minFieldWidth = key.size();
			}
		}


		PairSummable operator+=(const PairSummable& src){
			if (this->key() == src.key() && this != &src )
			{
				PairSummable temp(this->key(), this->value() + src.value());
				*this = temp;

			}

			return *this;
		}

		

		void display(std::ostream& os) const {
			os << left << setw(minFieldWidth); 
			this->Pair<K, V>::display(os);
			os << right;
		}

	private:
		static V initial;
		static size_t minFieldWidth;
	};

	template<typename K,typename V>
	size_t PairSummable<K, V>::minFieldWidth = 0;

	template<typename K,typename V>
	V PairSummable<K, V>::initial = "";

	template<>
	string PairSummable<string , string>::initial = "";

	template<>
	int PairSummable<string, int>::initial = 0;



	template<>
	PairSummable<string, string> PairSummable<string, string>::operator+=(const PairSummable<string, string>& src) {
		
		if (this->key() == src.key() && this != &src)
		{
			if (this->value() == "")
			{
				PairSummable temp(this->key(), src.value());
				*this = temp;
			}
			else
			{
				PairSummable temp(this->key(), this->value() + ", " + src.value());
				*this = temp;
			}
			
		}

		return *this;
	}

	
}
