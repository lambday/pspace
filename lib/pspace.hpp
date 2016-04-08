#ifndef PSPACE_LIB_HPP__
#define PSPACE_LIB_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace pspace
{

template <class T>
void display(T& a)
{
	cout << "[";
	for_each(a.begin(), a.end(), [](int& val) { cout << val << " "; });
	cout << "]" << endl;
}

}

#endif // PSPACE_LIB_HPP__
