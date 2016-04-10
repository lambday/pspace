/**
 * http://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
 *
 * Merge two sorted arrays with O(1) extra space
 * We are given two sorted array. We need to merge these two arrays such that
 * the initial numbers (after complete sorting) are in the first array and the
 * remaining numbers are in the second array. Extra space allowed in O(1).
 *
 * Example:
 *
 * Input: ar1[] = {1, 5, 9, 10, 15, 20};
 *        ar2[] = {2, 3, 8, 13};
 *        Output: ar1[] = {1, 2, 3, 5, 8, 9}
 *                ar2[] = {10, 13, 15, 20}
 */

#include <lib/pspace.hpp>

using namespace pspace;

template <typename T, size_t N, size_t M>
void merge(T (&a)[N], T (&b)[M])
{
	for (size_t i = 0; i < N; ++i)
	{
		if (a[i] > b[0])
		{
			swap(a[i], b[0]);
			for (size_t j = 1; j < M; ++j)
			{
				if (b[j-1] > b[j])
				   swap(b[j-1], b[j]);
			}
		}
	}
}

int main()
{
	int a[] = {1,5,9,10,15,20};
	int b[] = {2,3,8,13};
	display(a);
	display(b);
	merge(a, b);
	display(a);
	display(b);
	return 0;
}
