#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
long long int A[MAXN];
int main()
{
	// freopen("input.txt", "r", stdin);
	freopen("b_small.in", "r", stdin);
	freopen("b_small.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		int b;
		long long int n;
		cin>>b>>n;
		for (int i = 0; i < b; ++i)
		{
			cin>>A[i];
		}
		long long int lo = 0, hi = 100000000000000000ll, mid;
		while(lo < hi)
		{
			mid = (lo+hi+1)/2ll;
			long long int tot = 0;
			for (int i = 0; i < b; ++i)
				tot += (mid+A[i]-1ll)/A[i];
			if(tot >= n)
				hi = mid - 1;
			else
				lo = mid;
		}
		long long int tot = 0;
		for (int i = 0; i < b; ++i)
			tot += (hi+A[i]-1ll)/A[i];
		int ans = -1;
		for (int i = 0; i < b; ++i)
		{
			if(hi%A[i] == 0)
			{
				tot++;
				if(tot == n)
				{
					ans = i+1;
					break;
				}
			}
		}
		assert(ans != -1);
		cout<<"Case #"<<case_num<<": "<<ans<<"\n";
	}
	return 0;
}