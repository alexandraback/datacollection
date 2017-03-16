#include <bits/stdc++.h>
using namespace std;
#define int long long
int ceilt (int a, int b)
{
	if (a%b==0) return a/b;
	else return a/b+1; 
}
main()
{
	freopen("in.txt", "r", stdin); 
	freopen("out.txt", "w", stdout);
	int a; cin >> a;
	for (int g=0; g<a; g++)
	{
		int b; cin >> b;
		vector <int> d;
		for (int y=0; y<b; y++)
		{
			int c; cin >> c; d.push_back(c); 
		}
		int ans1=0, ans2=0, maxceil=-1; 
		for (int g=0; g<d.size()-1; g++)
		{
			if (d[g+1]<d[g])
			{
				ans1+=d[g]-d[g+1]; 
				int r=d[g]-d[g+1];
				if (r>maxceil)maxceil=r; 
			}
		}
		if (maxceil!=-1)
		{
			for (int g=0; g+1<d.size(); g++)
			{
				if (d[g]>maxceil) ans2+=maxceil;
				else ans2+=d[g]; 
			}
		}
		cout << "Case #" << g+1 << ": " << ans1 << ' ' << ans2 << '\n'; 
	}
	return 0; 
}
