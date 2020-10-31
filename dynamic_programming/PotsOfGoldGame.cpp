#include <iostream>
#include <string>
using namespace std;

// maximum number of pots
#define N 10

// Create a table to store solutions of subproblems
int lookup[N][N];

// Function to maximize the number of coins collected by a player,
// assuming that opponent also plays optimally
int optimalStrategy(int coin[], int i, int j)
{
	// base case: one pot left, only one choice possible
	if (i == j)
		return coin[i];

	// if we're left with only two pots, choose one with maximum coins
	if (i + 1 == j)
		return max(coin[i], coin[j]);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a lookup table
	if (lookup[i][j] == 0)
	{
		// if player chooses front pot i, opponent is left to choose
		// from [i+1, j].
		// 1. if opponent chooses front pot i+1, recur for [i+2, j]
		// 2. if opponent chooses rear pot j, recur for [i+1, j-1]

		int start = coin[i] + min(optimalStrategy(coin, i + 2, j),
								optimalStrategy(coin, i + 1, j - 1));

		// if player chooses rear pot j, opponent is left to choose
		// from [i, j-1].
		// 1. if opponent chooses front pot i, recur for [i+1, j-1]
		// 2. if opponent chooses rear pot j-1, recur for [i, j-2]

		int end = coin[j] + min(optimalStrategy(coin, i + 1, j - 1),
						optimalStrategy(coin, i, j - 2));

		// assign maximum of two choices
		lookup[i][j] = max(start, end);
	}

	// return the subproblem solution from the map
	return lookup[i][j];
}

// Pots of Gold Game using Dynamic Programming
int main()
{
	// pots of gold arranged in a line
	int coin[] = { 4, 6, 2, 3 };

	// number of pots (n is even)
	int n = sizeof(coin) / sizeof(coin[0]);

	cout << "Maximum coins collected by player is "
			<< optimalStrategy(coin, 0, n - 1);

	return 0;
}