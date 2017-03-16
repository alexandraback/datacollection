#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

namespace
{
	int cnt[18];
}

//int main14RQ_A()
int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		memset(cnt, 0, sizeof(cnt));

		for (int k = 0; k < 2; ++k)
		{
			int r, x;
			fin >> r;

			for (int i = 1; i <= 4; ++i)
			{
				for (int j = 1; j <= 4; ++j)
				{
					fin >> x;
					if (i == r)
						++cnt[x];
				}
			}
		}

		fout << "Case #" << zz << ": ";
		int num = count(cnt, cnt + 18, 2);
		if (num == 0)
		{
			fout << "Volunteer cheated!";
		}
		else if (num > 1)
		{
			fout << "Bad magician!";
		}
		else
		{
			fout << (find(cnt, cnt + 18, 2) - cnt);
		}

		fout << endl;
	}

	return 0;
}
