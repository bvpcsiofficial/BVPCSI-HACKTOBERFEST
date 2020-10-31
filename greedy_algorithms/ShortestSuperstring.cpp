#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// Function to calculate maximum overlap in two given strings
int findOverlappingPair(string s1, string s2, string& str)
{
	// max will store maximum overlap i.e maximum length of the
	// matching prefix and suffix
	int max = INT_MIN;
	int m = s1.length();
	int n = s2.length();

	// check suffix of s1 matches with prefix of s2
	for (int i = 1; i <= min(m, n); i++)
	{
		// compare last i characters in s1 with first i characters in s2
		if (s1.compare(m - i, i, s2, 0, i) == 0)
		{
			if (max < i)
			{
				//update max and str
				max = i;
				str = s1 + s2.substr(i);
			}
		}
	}

	// check prefix of s1 matches with suffix of s2
	for (int i = 1; i <= min(m, n); i++)
	{
		// compare first i characters in s1 with last i characters in s2
		if (s1.compare(0, i, s2, n - i, i) == 0)
		{
			if (max < i)
			{
				//update max and str
				max = i;
				str = s2 + s1.substr(i);
			}
		}
	}

	return max;
}

// Function to calculate smallest string that contains
// each string in the given set as substring.
string findShortestSuperstring(vector<string> arr)	// no const, no-ref
{
	int n = arr.size();

	// run n-1 times to consider every pair
	while (n != 1)
	{
		// to store  maximum overlap
		int max = INT_MIN;

		// to store array index of strings involved in maximum overlap
		int p, q;

		// to store resultant string after maximum overlap
		string res_str;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				string str;

				// r will store maximum length of the matching prefix and
				// suffix. str is passed by reference and store the result
				// string after maximum overlap of arr[i] and arr[j], if any
				int r = findOverlappingPair(arr[i], arr[j], str);

				// check for maximum overlap
				if (max < r)
				{
					max = r;
					res_str.assign(str);
					p = i, q = j;
				}
			}
		}

		// ignore last element in next cycle
		n--;

		// if no overlap, append arr[n] to arr[0]
		if (max == INT_MIN)
			arr[0] += arr[n];
		else
		{
			// copy resultant string to index p
			arr[p] = res_str;

			// copy string at last index to index q
			arr[q] = arr[n];
		}
	}

	return arr[0];
}

// Shortest Superstring Problem
int main()
{
	vector<string> arr = { "CATGC", "CTAAGT", "GCTA", "TTCA", "ATGCATC" };

	cout << "The Shortest Superstring is " << findShortestSuperstring(arr);

	return 0;
}