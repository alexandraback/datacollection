#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	ifstream input ("input.in");
	ofstream output ("answers.txt");
	int possible[4], answer, nAns, n;
	input >> n;
	for( int k = 1; k <= n; ++k )
	{
		nAns = 0;
		answer = 0;
		int a1,a2;
		input >> a1;
		for( int i = 1; i < 5; ++i )
		{
			int x;
			if(i==a1)
			{
				input >> possible[0];
				input >> possible[1];
				input >> possible[2];
				input >> possible[3];
			}
			else
				input >> x >> x >> x >> x;
		}
		input >> a2;
		for( int i = 1; i < 5; ++i )
		{
			int x;
			if(i==a2)
			{
				for( int j = 0; j < 4; ++j )
				{
					input >> x;
					if(x == possible[0] || x == possible[1] || x == possible[2] || x == possible[3])
					{
						++nAns;
						answer = x;
					}
				}
			}
			else
				input >> x >> x >> x >> x;
		}
		output << "Case #" << k << ": ";
		if( nAns == 1 )
			output << answer << endl;
		if( nAns == 0 )
			output << "Volunteer cheated!\n";
		if( nAns > 1 )
			output << "Bad magician!\n";
	}
	input.close();
	output.close();
}
