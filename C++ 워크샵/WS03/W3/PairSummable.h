#pragma once
#ifndef _SDDS_PAIRSUMMABLE_H
#define _SDDS_PAIRSUMMABLE_H
#include <iomanip>

#include "Pair.h"

namespace sdds
{
	template <typename K, typename V>

	class PairSummable : public Pair<K, V>
	{
		static V initSummation;
		static size_t minField;

	public:
		//getInitialValue function
		static const V& getInitialValue()
		{
			return initSummation;
		} //End getInitialValue function

		//Default Constructor
		PairSummable() {}

		//Constructor
		PairSummable(const K& key, const V& value) : Pair<K, V>(key, value)
		{
			if (this->minField < key.size())
				this->minField = key.size();
		} //End Constructor

		//sum function
		V sum(const K& key, const V& val) const
		{
			V returnVal{ val };
			if (this->key() == key)
				returnVal = val + this->value();
			return returnVal;
		} //End sum function

		//display
		void display(std::ostream& os) const
		{
			os << std::setw(this->minField) << std::left << this->key() << " : " << this->value() << std::right << std::endl;
		} //End display
	};	  //End class

	//Specialize initSummation <std::string, int>
	template <>
	int PairSummable<std::string, int>::initSummation{ 0 };

	//Specialize initSummation <std::string, std::string>
	template <>
	std::string PairSummable<std::string, std::string>::initSummation{ "" };

	//Initialize minField to 0
	template <typename K, typename V>
	size_t PairSummable<K, V>::minField{ 0 };

	//Specialize sum <std::string, std::string>
	template <>
	std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& val) const
	{
		std::string returnVal{ val };
		if (this->key() == key)
			if (val != "")
				returnVal = val + ", " + this->value();
			else
				returnVal = this->value();
		return returnVal;
	} //End sum <std::string, std::string>
} // namespace sdds
#endif