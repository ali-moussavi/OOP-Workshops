//Student name : Seyed Mohammad Ali Lohmousavi
//Student num : 159309186
//Seneca ID : smalohmousavi

#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace sdds {
	template<typename T>
	class Collection
	{
	public:
		Collection() {
			m_name = "";
			m_items = nullptr;
			m_size = 0;
			m_observer = nullptr;
		}
		Collection(std::string name) {
			m_name = name;
			m_items = nullptr;
			m_size = 0;
			m_observer = nullptr;
		}

		~Collection(){
			if (m_items != nullptr)
			{
				delete[] m_items;
				m_items = nullptr;
			}
		}

		Collection(Collection&) = delete;
		Collection(Collection&&) = delete;
		Collection& operator=(const Collection&) = delete;
		Collection& operator=(Collection&&) = delete;

		const std::string& name() const{
			return m_name;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool contains = false;
			for (size_t i = 0; i < m_size; i++)
			{
				if (item.title() == m_items[i].title())
				{
					contains = true;
					break;
				}
			}

			if (!contains)
			{
				T* temp = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++)
				{
					temp[i] = m_items[i];
				}
				temp[m_size] = item;
				m_size++;
				if (m_items != nullptr)
				{
					delete[] m_items;
				}
				m_items = temp;
				if (m_observer)
				{
					m_observer(*this, item);
				}
			}

			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx < m_size)
			{
				return m_items[idx];

			}
			else
			{
				string message = "Bad index [" + to_string(idx) + "]. Collection has [" +
					to_string(m_size) + "] items.";
				throw out_of_range(message);
			}
		}

		T* operator[](std::string title) const {
			for (size_t i = 0; i < m_size; i++)
			{
				if (title == m_items[i].title()) {
					return &m_items[i];
				}
			}

			return nullptr;
		}

	private:
		string m_name;
		T* m_items;
		size_t m_size;
		void (*m_observer) (const Collection<T>&, const T&);
	};

	template<typename T>
	ostream& operator<<(ostream& os, const Collection<T>& c) {
		for (size_t i = 0; i < c.size(); i++)
		{
			os << c[i];
		}

		return os;
	}
}