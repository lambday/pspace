#ifndef PSPACE_LIB_HPP__
#define PSPACE_LIB_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <functional>

using namespace std;

namespace pspace
{

template <class T>
struct scalar_trait
{
	using value_type = typename T::value_type;
};

template <> template <typename T, size_t N>
struct scalar_trait<T[N]>
{
	using value_type = T;
};

template <class T>
void display(T& a)
{
	using scalar_type = typename scalar_trait<T>::value_type;
	cout << "[";
	for_each(begin(a), end(a), [](scalar_type& val) { cout << val << " "; });
	cout << "]" << endl;
}

}

#endif // PSPACE_LIB_HPP__
