#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream input("input1.in");
	ofstream output("answer1.txt");
	output << fixed;
	int t;
	input >> t;
	string strings[100];
	char letters[101];
	char letters2[101];
	int sums[101][101];
	int max[101];
	
	for( int k = 1; k <= t; ++k )
	{
		int n;
		input >> n;
		for( int j = 0; j < n; ++j )
		{
			input >> strings[j];
		}
		for( int l = 0; l < 101; ++l )
		{
			for( int j = 0; j < 101; ++j )
				sums[l][j] = 0;
			max[l] = 0;
		}

		letters[0] = strings[0][0];
		++sums[0][0];
		int s = 1;
		for( int i = 1; strings[0][i] != 0; ++i )
		{
			if(letters[s-1] != strings[0][i])
			{
				letters[s] = strings[0][i];
				max[s-1] = sums[0][s-1];
				++s;
			}
			sums[0][s-1]++;
		}
		max[s-1] = sums[0][s-1];

		bool good = true;
		for( int x = 1; x < n; ++x )
		{
			letters2[0] = strings[x][0];
			++sums[x][0];
			int s1 = 1;
			for( int i = 1; strings[x][i] != 0; ++i )
			{
				if(letters2[s1-1] != strings[x][i])
				{
					letters2[s1] = strings[x][i];
					if( max[s1-1] < sums[x][s1-1])
						max[s1-1] = sums[x][s1-1];
					++s1;
				}
				sums[x][s1-1]++;
			}
			if( max[s1-1] < sums[x][s1-1])
				max[s1-1] = sums[x][s1-1];
			for( int i2 = 0; i2 < s1; ++i2)
			{
				if( letters2[i2] != letters[i2])
					good = false;
			}
			if( s1 != s )
				good = false;
		}

		if( good )
		{
			int toChange = 0;
			for( int x1 = 0; x1 < s; ++x1)
			{
				int toChangeNow = 10000;
				for( int k1 = 1; k1 <= max[x1]; ++k1 )
				{
					int sum_k = 0;
					for( int x2 = 0; x2 < n; ++x2 )
					{
						sum_k += abs(sums[x2][x1] - k1);
					}
					if( sum_k < toChangeNow )
						toChangeNow = sum_k;
				}
				toChange += toChangeNow;
			}
			output << "Case #" << k << ": " << toChange << endl;
		}
		else
		{
			output << "Case #" << k << ": " << "Fegla won" << endl;
		}
	}
	input.close();
	output.close();
}