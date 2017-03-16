#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int p;
	cin >> p;
	int a1, a2, c, v;
	int m1[4][4], m2[4][4];
	for (int n = 1; n <= p; n++)
	{
		cin >> a1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> m1[i][j];
			}
		}
		cin >> a2;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> m2[i][j];
			}
		}
		c = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (m1[a1 - 1][i] == m2[a2 - 1][j])
				{
					c++;
					v = m1[a1 - 1][i];
				}
			}
		}
		if (c == 0)
			cout << "Case #" << n << ": Volunteer cheated!\n";
		else if (c == 1)
			cout << "Case #" << n << ": " << v << "\n";
		else
			cout << "Case #" << n << ": Bad magician!\n";
	}
	return 0;
}

