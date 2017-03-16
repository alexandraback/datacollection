#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair <int, int> 
int bitc [(1<<16)+5]; 
int arr[20][20]; 
main()
{
	freopen("in.txt", "r", stdin); 
	freopen("out.txt", "w", stdout); 
	int a; cin >> a;
	for (int g=0; g<(1<<16); g++) bitc[g]=__builtin_popcount(g); 
	for (int g=0; g<a; g++)
	{
		int b,c,n; cin >> b >> c >> n;
		int ans=1e9; 
		for (int y=0; y<(1<<(b*c)); y++)
		{ 
			if (bitc[y]!=n) continue; 
			memset(arr,0,sizeof(arr));
			for (int t=0; t<(b*c); t++)
			{
				if ((1<<t)&y)
				{
					arr[t/c][t%c]=1;
				}
				else arr[t/c][t%c]=0; 
			}
			int check=0; 
			for (int t=0; t<b; t++)
			{
				for (int r=0; r<c; r++)
				{
					if (!arr[t][r]) continue;
					if (arr[t][r+1]) check++; 
					if (r>=1 && arr[t][r-1]) check++;
					if (t>=1 && arr[t-1][r]) check++;
					if (arr[t+1][r]) check++; 
				}
			}
			check/=2; 
			if (check<ans)ans=check; 
		}
		cout << "Case #" << g+1 << ": " << ans << '\n';
	}
}
