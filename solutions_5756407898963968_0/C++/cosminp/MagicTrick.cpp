#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int getRow(int val, int grid[4][4])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[i][j] == val) return i;

	return -1;
}

string solve(int grid[2][4][4], int firstAns, int secondAns)
{
	ostringstream 	out;
	int 			h[4];
	bool			isMagicianGood;
	bool 			isCheating;
	int 			value;

	memset(h, 0, sizeof(h));
	isMagicianGood 	= true;
	value 			= -1;
	for (int i = 0; i < 4; i++)
	{
		int row = getRow(grid[0][firstAns][i], grid[1]);

		if (row == secondAns)
		{
			value = grid[0][firstAns][i];

			if (h[row] == 0)
				h[row] = 1;
			else
				isMagicianGood = false;
		}
	}

	if (value == -1)
		out << "Volunteer cheated!";
	else if (isMagicianGood)
		out << value;
	else
		out << "Bad magician!";

	return string(out.str());
}


int main()
{
	fstream		f, g;
	int 		grid[2][4][4];
	int 		T, firstAns, secondAns;

	f.open("input.txt",  ios :: in);
	g.open("output.txt", ios :: out);

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> firstAns;
		firstAns--;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				f >> grid[0][i][j];

		f >> secondAns;
		secondAns--;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				f >> grid[1][i][j];

		g << "Case #" << test << ": " << solve(grid, firstAns, secondAns) << endl;
	}

	f.close();
	g.close();

	return 0;
}
