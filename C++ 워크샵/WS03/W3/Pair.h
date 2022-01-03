#pragma once
#ifndef _SDDS_PAIR_H
#define _SDDS_PAIR_H
#include <iostream>
namespace sdds
{
	template <typename K, typename V>
	class Pair
	{
		K m_key;
		V m_value;

	public:
		//Default Constructor
		Pair() : m_key{}, m_value{} {}

		//Constructor
		Pair(const K& key, const V& value) : m_key{ key }, m_value{ value } {}

		//key value
		const K& key() const
		{
			return this->m_key;
		} //End key value

		//value function
		const V& value() const
		{
			return this->m_value;
		} //End value function

		//virtual display function
		virtual void display(std::ostream& os) const
		{
			os << this->key() << " : " << this->value() << std::endl;
		} //End virtual display function
	};	  //End Class

	//overload operator<<
	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair)
	{
		pair.display(os);
		return os;
	} //End overload operator<<
} // namespace sdds
#endif