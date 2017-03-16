#include <iostream>
using namespace std;

int T, Grid[2][4][4], Pos[2], match, matchCount;

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		for (int i=0; i<2; i++)
		{
			cin >> Pos[i];
			for (int j=0; j<4; j++)
				for (int k=0; k<4; k++)
					cin >> Grid[i][j][k];
		}
		
		matchCount = 0;
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				if (Grid[0][Pos[0]-1][i] == Grid[1][Pos[1]-1][j])
				{
					matchCount++;
					match = Grid[0][Pos[0]-1][i];
				}
		
		cout << "Case #" << t << ": ";
		switch (matchCount)
		{
			case 0: cout << "Volunteer cheated!" << endl; break;
			case 1: cout << match << endl; break;
			default: cout << "Bad magician!" << endl;
		}
	}
	
	return 0;
}
