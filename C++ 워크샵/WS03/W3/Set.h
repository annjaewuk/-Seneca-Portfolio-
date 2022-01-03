#pragma once
#ifndef _SDDS_SET_H
#define _SDDS_SET_H

namespace sdds
{
	template <class T, int N>
	class Set
	{
		T m_array[N];
		size_t count{ 0 };

	public:
		//size function
		size_t size() const
		{
			return this->count;
		} //End size function

		//overload operator[]
		const T& operator[](size_t idx) const
		{
			return this->m_array[idx];
		} //End overload operator[]

		//overload operator+=
		void operator+=(const T& item)
		{
			if (this->count < N)
				this->m_array[this->count++] = item;
		} //End overload operator+=
	};//End Class
} // namespace sdds
#endif