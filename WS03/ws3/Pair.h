#pragma once

#include <iostream>

using namespace std;

namespace sdds {

	template<typename K, class V>
	class Pair
	{
	public:
		Pair() {
			k = {};
			v = {};
		}
		

		Pair(const K& key, const V& value) {
			this->k = key;
			this->v = value;
		}

		const K& key() const {
			return k;
		}

		const V& value() const {
			return v;
		}

		virtual void display(std::ostream& os) const {
			os << key() << " : " << value() << endl;

		}

		
	protected:
		void setValue(const V& value) {
			v = value;
		}

		void setKey(const K& key) {
			k = key;
		}

	private:
		K k;
		V v;

		
	};


template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}

	
}