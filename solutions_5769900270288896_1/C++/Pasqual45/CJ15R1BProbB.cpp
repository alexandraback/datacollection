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


//int main15R1B_B()
int main()
{
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int a, b, n;
		fin >> a >> b >> n;

		if (a > b)
		{
			swap(a, b);
		}

		int tot = a*b;
		int maxBad = a * (b - 1) + b * (a - 1);
		int spaces = tot - n;

		int result = 0;
		if (n > (tot + 1) / 2)
		{
			if (a == 1)
			{
				result = max(0, maxBad - 2 * spaces);
			}
			else if (a == 2)
			{
				int num3 = b - 2;
				int used3 = min(num3, spaces);
				result = maxBad - used3 * 3;

				spaces -= used3;
				result = max(0, result - spaces * 2);
			}
			else
			{
				int totalMoves = (tot + 1) / 2;
				bool bothOdd = (tot % 2) == 1;
				int aa = a - 2, bb = b - 2;

				int resultAlt = 999999;
				if (bothOdd)
				{
					int alt4 = (aa*bb) / 2;
					int used4 = min(alt4, spaces);

					int used3 = spaces - used4;
					resultAlt = maxBad - used4 * 4 - used3 * 3;
				}

				int num4 = (aa*bb + 1) / 2;
				int used4 = min(num4, spaces);
				result = maxBad - used4 * 4;
				spaces -= used4;

				int num2 = bothOdd ? 4 : 2;
				int num3 = totalMoves - num4 - num2;

				int used3 = min(num3, spaces);
				result -= used3 * 3;
				spaces -= used3;

				int used2 = min(num2, spaces);
				result -= used2 * 2;
				spaces -= used2;

				result = min(result, resultAlt);
				result = max(result, 0);
			}
		}

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
