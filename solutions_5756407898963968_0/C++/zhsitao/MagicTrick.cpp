#define IOSTREAM_TO_FSTREAM

#include<iostream>
#ifdef IOSTREAM_TO_FSTREAM
#include<fstream>
#endif

using namespace std;

int main()
{
#ifdef IOSTREAM_TO_FSTREAM
	ifstream fin;
	fin.open("A-small-attempt0.in");
	cin.rdbuf(fin.rdbuf());
	ofstream fout;
	fout.open("A-small-attempt0.out");
	cout.rdbuf(fout.rdbuf());
#endif
	int n;
	int a1, a2;
	int s1[4][4], s2[4][4];
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		//while (true);
		int r = -1;
		cin >> a1;
		for (int j = 0 ; j < 4 ; j++)
		{
			for (int k = 0 ; k < 4 ; k++)
			{
				cin >> s1[j][k];
			}
		}
		cin >> a2;
		for (int j = 0 ; j < 4 ; j++)
		{
			for (int k = 0 ; k < 4 ; k++)
			{
				cin >> s2[j][k];
			}
		}
		for (int j = 0 ; j < 4 ; j++)
		{
			int t = s1[a1 - 1][j];
			for (int k = 0 ; k < 4 ; k++)
			{
				if (s2[a2 - 1][k] == t)
				{
					if (r == -1)
						r = t;
					else
						r = -2;
				}
			}
		}
		cout << "Case #" << i << ": ";
		if (r == -1)
			cout << "Volunteer cheated!" << endl;
		else if (r == -2)
			cout << "Bad magician!" << endl;
		else
			cout << r << endl;
	}
	return 0;
}
