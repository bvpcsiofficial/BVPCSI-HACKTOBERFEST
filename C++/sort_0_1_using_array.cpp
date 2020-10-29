#include <iostream>
#include <algorithm>
using namespace std;

//1st method
void sortZeroesAndOne(int *input, int size)
{
    //Write your code here
	int i=0, j=size-1;
    while(i<j){
        while(input[i] == 0 && i<j){
            i++;
        }

        while(input[j] == 1 && i<j){
            j--;
        }

        if(i<j){
            input[i] = 0;
            input[j] = 1;
            i++;
            j--;
        }
    }
}

//2nd method
/*
void sortZeroesAndOne(int *input, int size)
{

    int count = 0; // Counts the no of zeros in arr

    for (int i = 0; i < size; i++) {
        if (input[i] == 0)
            count++;
    }

    // Loop fills the arr with 0 until count
    for (int i = 0; i < count; i++)
        input[i] = 0;

    // Loop fills remaining arr space with 1
    for (int i = count; i < size; i++)
        input[i] = 1;
}
*/

int main()
{

	int t;
	cin >> t;

	while (t--)
	{
		int size;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		sortZeroesAndOne(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}
