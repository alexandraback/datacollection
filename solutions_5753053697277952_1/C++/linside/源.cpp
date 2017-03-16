#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("result.txt");
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int m;
		cin >> m;
		fout << "Case #" << i << ": ";
		int a[27], s = 0, l[27], ln = m;
		for (int j = 1;j <= m;j++)
		{
			cin >> a[j];
			s += a[j];
			l[j] = 1;
		}
		if (m == 2)
		{
			for (int j = 1;j <= a[1] - a[2];j++)
			{
				fout << "A" << " ";
			}
			for (int j = 1;j <= a[2] - a[1];j++)
			{
				fout << "B" << " ";
			}
			int ss;
			ss = a[1] > a[2] ? a[2] : a[1];
			for (int j = 1;j <= ss - 1;j++)
			{
				fout << "AB ";
			}
			fout << "AB";
		}
		else
		{
			int max = 0, x = 0;
			do
			{
				max = 0;
				x = 0;
				for (int j = 1;j <= m;j++)
				{
					if (a[j] > max)
					{
						x = j;
						max = a[j];
					}
				}
				a[x]--;
				s--;
				fout << char(x + 64) << " ";
			} while (s > 2);
			for (int j = 1;j <= m;j++)
			{
				if (a[j] != 0)
				{
					fout << char(j + 64);
				}
			}
		}
		fout << endl;
	}
	system("pause");
	return 0;
}