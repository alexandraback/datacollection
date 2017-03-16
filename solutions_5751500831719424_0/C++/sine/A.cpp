#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char ss[105][105], rs[105][105];
int p[105][105];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T, prob=1;
	for (cin >> T; T--;)
	{
		

		int n, i, j, k;
		int ans = 0;

		scanf("%d\n", &n);
		for(i=0; i<n; i++)
		{
			gets(ss[i]);
		}
		memset(p, 0, sizeof(p));
		memset(rs, 0, sizeof(rs));
		for(i=0; i<n; i++)
		{
			rs[i][0]=ss[i][0];
			p[i][0]=1;
			j=1; k=0;
			while(ss[i][j])
			{
				if(ss[i][j]!=ss[i][j-1])
				{
					k++;
					rs[i][k]=ss[i][j];
					p[i][k]=1;
				}
				else p[i][k]++;
				j++;
			}
		}
		int f=0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				if(strcmp(rs[i], rs[j])!=0)
				{
					f=1;
					break;
				}
			if(f) break;
		}

		cout << "Case #" << prob++ << ": ";
		if(f) cout << "Fegla Won";
		else
		{
			for(; k>=0; k--)
			{
				double sum=0;
				for(i=0; i<n; i++)
				{
					sum+=p[i][k];
				}
				for(i=0; i<n; i++)
					ans+=abs(p[i][k]-(int)(sum/n+0.5));
			}

			cout << ans;
		}
		cout << endl;
	}

	return 0;
}