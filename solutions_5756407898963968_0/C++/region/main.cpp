#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("magicin.txt");
	ofstream fout("magicout.txt");
	int T = 0;

	int a1, a2, t1[4][4], t2[4][4];

	fin >> T;

	for (int i = 0; i < T; i++)
	{
		fin >> a1; a1--;
		for (int i = 0; i < 4; i++)
		{
			fin >> t1[i][0] >> t1[i][1] >> t1[i][2] >> t1[i][3];
		}
		fin >> a2; a2--;
		for (int i = 0; i < 4; i++)
		{
			fin >> t2[i][0] >> t2[i][1] >> t2[i][2] >> t2[i][3];
		}

		int c = 0, num = -1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (t1[a1][i] == t2[a2][j])
				{
					c++;
					num = t1[a1][i];
				}
			}
		}
		if (c == 1)
			fout << "Case #" << i + 1 << ": " << num << '\n';
		else if (c == 0)
			fout << "Case #" << i + 1 << ": Volunteer cheated!\n";
		else
			fout << "Case #" << i + 1 << ": Bad magician!\n";
	}

	return 0;
}