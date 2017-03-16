#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ofstream outFile;
	ifstream inFile;
	inFile.open("input.txt");
	outFile.open("output.txt");

	int T;
	int rowNum, skip;
	int cards[2][4];
	int row , col, n, game;
	int c1,c2, count, ans;
	string s;
	inFile >> T;
	for (int caseNum = 0; caseNum<T; caseNum++)
	{
		for (game=0;game<2;game++)
		{
			inFile >> rowNum;
			for (row=0;row<4;row++)
			{
				for (col=0; col<4; col++)
				{
					inFile >> n;
					if (row == rowNum-1)
					{
						cards[game][col] = n;
					}
				}
			}
		}

		count = 0;
		for (c1=0;c1<4;c1++)
		{
			for (c2=0;c2<4;c2++)
			{
				if (cards[0][c1] == cards[1][c2])
				{
					count ++;
					ans = cards[0][c1];
				}
			}
		}

		outFile << "Case #" << caseNum+1 << ": ";
		if (count == 0)
			outFile << "Volunteer cheated!" << endl;
		if (count == 1)
			outFile << ans << endl;
		if (count >1)
			outFile << "Bad magician!" << endl;

	}


	return 0;
}