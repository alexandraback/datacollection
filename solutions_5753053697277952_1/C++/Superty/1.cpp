#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <cstring>
#include <tuple>
#include <cassert>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int cs = 1; cs <= t; cs++)
	{
		int n;
		cin >> n;
		int p[30];
		int left = n;
		p[n] = -1;
		for(int i = 0; i < n; i++)
		{
			cin >> p[i];
		}

		cout << "Case #" << cs << ": ";
		while(left > 0)
		{
			int hi = n, sechi = n;
			for(int i = 0; i < n; i++)
			{
				if(p[i] > p[hi])
				{
					sechi = hi;
					hi = i;
				}
				else if(p[i] > p[sechi]) sechi = i;
			}

			if(left == 2 && p[hi] == p[sechi])
			{
				cout << (char)('A' + hi) << (char)('A' + sechi) << ' ';
				p[hi]--;
				p[sechi]--;
			}
			else
			{
				cout << (char)('A' + hi) << ' ';
				p[hi]--;
			}
			if(p[hi] == 0) left--;
			if(p[sechi] == 0) left--;
		}
		cout << '\n';
	}

	return 0;
}