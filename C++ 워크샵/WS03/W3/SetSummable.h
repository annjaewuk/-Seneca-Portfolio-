#pragma once
#ifndef _SDDS_SETSUMMABLE_H
#define _SDDS_SETSUMMABLE_H
#include "Set.h"

namespace sdds
{
	template <typename T, int N, typename K, typename V>
	class SetSummable : public Set<T, N>
	{

	public:
		//accumulate function
		V accumulate(const K& key) const
		{
			auto sum = T::getInitialValue();
			for (size_t i = 0; i < this->size(); i++)
				sum = (*this)[i].sum(key, sum);
			return sum;
		} //End accumulate fuAnction
	};//End Class
} // namespace sdds
#endif