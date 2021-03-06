/**
 * source : http://www.geeksforgeeks.org/count_subarrays-strictly-increasing-subarrays/
 *
 * Count Strictly Increasing Subarrays
 * Given an array of integers, count_subarrays number of subarrays (of size more than one) that are strictly increasing.
 * Expected Time Complexity : O(n)
 * Expected Extra Space: O(1)
 *
 * Examples:
 *
 * Input: arr[] = {1, 4, 3}
 * Output: 1
 * There is only one subarray {1, 4}
 *
 * Input: arr[] = {1, 2, 3, 4}
 * Output: 6
 * There are 6 subarrays {1, 2}, {1, 2, 3}, {1, 2, 3, 4}
 *                       {2, 3}, {2, 3, 4} and {3, 4}
 *
 * Input: arr[] = {1, 2, 2, 4}
 * Output: 2
 * There are 2 subarrays {1, 2} and {2, 4}
 */

#include <lib/pspace.hpp>

using namespace pspace;

template <class T, int N>
int count_subarrays(T const (&a)[N])
{
	size_t size = end(a) - begin(a);
	int count = 0;
	int current_increasing_subarray_len = 1;
	for (size_t i = 1; i < size; ++i)
	{
		if (a[i-1] < a[i])
			count += current_increasing_subarray_len++;
		else
			current_increasing_subarray_len = 1;
	}
	return count;
}

int main()
{
	int a[] = {1,2,2,4};
	display(a);
	cout << count_subarrays(a) << endl;
	int b[] = {1,2,3,4};
	display(b);
	cout << count_subarrays(b) << endl;
	int c[] = {6,5,1,3,4,2,1,2,4,8,7};
	display(c);
	cout << count_subarrays(c) << endl;
	cout << count_subarrays({4,3,2,1}) << endl;
	return 0;
}
