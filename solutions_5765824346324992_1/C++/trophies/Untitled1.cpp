#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair <int, int> 
int arr[1005]; 
int b, n; 
int ceilt (int a, int b)
{
	if (a%b==0) return a/b;
	return a/b+1; 
}
int check (int a)
{
	int cur=0;
	for (int g=1; g<=b; g++)
	{
		if (cur>1e16) break;
		cur+=ceilt(a,arr[g]); 
	}
	for (int g=1; g<=b; g++)
	{
		if (a%arr[g]) continue; 
		if (cur<n)
		{
			cur++; 
			if (cur==n) return g; 
		}
	}
	if (cur>=n) return 1e18; 
	return -1e18; 
}
main()
{
	freopen("in.txt", "r", stdin); 
	freopen("out.txt", "w", stdout);
	int T; cin >> T; 
	for (int g=0; g<T; g++)
	{
		memset(arr,0,sizeof(arr));
		cin >> b >> n; 
		for (int y=1; y<=b; y++) cin >> arr[y]; 
		int start=0, end=1e16;int flag=0; 
		while (end>start)
		{
			int mid=(end+start)/2; 
			int z=check(mid); 
			if (z==-1e18) // too early for this guy
			{
				start=mid+1; 
			}
			else if (z==1e18) // too late
			{
				end=mid-1; 
			}
			else
			{
				cout << "Case #" << g+1 << ": " << z << '\n'; flag=1; break; 
			}
		}
		if (!flag)
		{
			cout << "Case #" << g+1 << ": " << check(start) << '\n'; 
		}
	}
	return 0; 
}
