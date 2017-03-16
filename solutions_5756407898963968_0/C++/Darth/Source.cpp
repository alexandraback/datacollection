#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int t;
	int i, r;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int cards[2][4][4];
	int ans1, ans2;

	fin >> t;
	for (int test = 0; test < t; test++)
	{
		fin >> ans1;
		for (i = 0; i < 4; i++)
			for (r = 0; r < 4; r++)
				fin >> cards[0][i][r];
		fin >> ans2;
		for (i = 0; i < 4; i++)
			for (r = 0; r < 4; r++)
				fin >> cards[1][i][r];

		int found = 0;
		int foundData;
		for (i = 0; i < 4; i++)
			for (r = 0; r < 4; r++)
				if (cards[0][ans1 - 1][i] == cards[1][ans2 - 1][r])
				{
					found++;
					foundData = cards[0][ans1 - 1][i];
				}
		
		fout << "Case #" << (test + 1) << ": ";
		if (found == 0)
			fout << "Volunteer cheated!" << endl;
		else if (found == 1)
			fout << foundData << endl;
		else fout << "Bad magician!" << endl;
	}
}