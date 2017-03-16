#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void printSolution(unsigned int T, const string& solution)
{
	cout << "Case #" << T << ": " << solution << endl;
}

void solve(unsigned int T)
{
	int N;							// Number of parties
	cin >> N;
	vector<int> partySizes(N,0);

	for (int i = 0; i < N; ++i)
		cin >> partySizes[i];

	string solution;
	bool notEmpty = true;
	while (notEmpty)
	{
		notEmpty = false;
		int largest = 0, largestIndex = 0;
		int second = 0, secondIndex = 0;
		int third = 0, thirdIndex = 0;

		for (int i = 0; i < N; ++i)
		{
			if (partySizes[i] >= largest && partySizes[i] > 0)
			{
				notEmpty = true;
				third = second;
				second = largest;
				largest = partySizes[i];

				thirdIndex = secondIndex;
				secondIndex = largestIndex;
				largestIndex = i;
			}
		}

		if (notEmpty)
		{
			if (!solution.empty()) solution += ' ';

			solution += (char)('A' + largestIndex);
			--partySizes[largestIndex];
			
			if (third < second)
			{	
				solution += (char)('A' + secondIndex);
				--partySizes[secondIndex];
			}
		}

	}
	printSolution(T,solution);
}

int main( int argc, char** argv )
{
	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) solve(i);
	return 0;
}
