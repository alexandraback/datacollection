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
#include<bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

namespace
{
	int bits(int x)
	{
		return bitset<32>(x).count();
	}

	bool filled[16][16];
}

//int main15R1B_B()
int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int a, b, n;
		fin >> a >> b >> n;

		int tot = a*b;
		int result = 99999;
		for (int m = 0; m < (1 << tot); ++m)
		{
			if (bits(m) != n)
				continue;

			int cur = 0;
			memset(filled, 0, sizeof(filled));
			for (int x = 0, i = 0, j = 0; x < tot; ++x)
			{
				if (m & (1 << x))
				{
					filled[i][j] = true;
					if (i > 0 && filled[i - 1][j])
						++cur;

					if (j > 0 && filled[i][j - 1])
						++cur;
				}

				++i;
				if (i == a)
				{
					i = 0;
					++j;
				}
			}

			result = min(result, cur);
		}

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
