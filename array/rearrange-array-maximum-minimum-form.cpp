/**
 * problem source : http://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/
 *
 * Given a sorted array of positive integers, rearrange the array alternately
 * i.e first element should be maximum value, second minimum value, third second max,
 * fourth second min and so on.
 *
 * Examples:
 *
 * Input  : arr[] = {1, 2, 3, 4, 5, 6, 7}
 * Output : arr[] = {7, 1, 6, 2, 5, 3, 4}
 *
 * Input  : arr[] = {1, 2, 3, 4, 5, 6}
 * Output : arr[] = {6, 1, 5, 2, 4, 3}
 *
 * Expected time complexity is O(n).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rearrange(vector<int>& a)
{
	auto to_index = [&a](size_t i)
	{
		if (i < a.size()/2)
			return i*2 + 1;
		else
			return (a.size()-i-1)*2;
	};
	for (size_t i = 0; i < a.size(); ++i)
	{
		auto tmp = a[i];
		auto tmp_i = i;
		while (tmp > 0)
		{
			tmp_i = to_index(tmp_i);
			swap(tmp, a[tmp_i]);
			a[tmp_i] *= -1;
		}
	}
	for_each(a.begin(), a.end(), [](int& val) { val *= -1; });
}

template <class T>
void display(T& a)
{
	cout << "[";
	for_each(a.begin(), a.end(), [](int& val) { cout << val << " "; });
	cout << "]" << endl;
}

int main()
{
	vector<int> a(7);
	iota(a.begin(), a.end(), 1);
	display(a);
	rearrange(a);
	display(a);

	a.resize(6);
	iota(a.begin(), a.end(), 1);
	display(a);
	rearrange(a);
	display(a);
	return 0;
}
