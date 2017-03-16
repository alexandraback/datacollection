#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int mash[10010];

int main()
{
	int T;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("ras.out", "w", stdout);
	while(cin >> T)
	{
		for(int j = 1; j <= T; j++)
		{
			int n, tmp = -1;
			cin >> n;
			int rst1 = 0, rst2 = 0;
			cin >> mash[0];
			for(int i = 1; i < n; i++)
			{
				cin >> mash[i];
				if(mash[i-1] - mash[i] > 0)
					rst1 += mash[i-1] - mash[i];
				tmp = max(tmp, mash[i-1] - mash[i]);
			}
			for(int i = 0; i < n-1; i++)
			{
				if(mash[i] >= tmp)
					rst2 += tmp;
				else
					rst2 += mash[i];
			}
			cout << "Case #" << j << ": " << rst1 << " " << rst2 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
