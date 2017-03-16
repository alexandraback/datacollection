#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int A[4][4], B[4][4];
int row1, row2;

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++)
	{
		std::vector<int> possibleAnswers;
		cin >> row1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> A[i][j];
		cin >> row2;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> B[i][j];
		row1--,row2--;
		for (int i = 1; i <= 16; i++)
		{
			bool inRow1 = false, inRow2 = false;
			for (int j = 0; j < 4; j++)
			{
				if (A[row1][j] == i)
					inRow1 = true;
				if (B[row2][j] == i)
					inRow2 = true;
			}
			if (inRow1 && inRow2)
				possibleAnswers.push_back(i);
		}
		cout << "Case #" << z << ": ";
		if (possibleAnswers.size() == 1)
			cout << possibleAnswers.front() << endl;
		else if (possibleAnswers.size() == 0)
			cout << "Volunteer cheated!" << endl;
		else
			cout << "Bad magician!" << endl;
	}
	return 0;
}
