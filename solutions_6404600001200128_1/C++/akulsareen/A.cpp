#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
long long int A[MAXN];
int main()
{
	// freopen("input.txt", "r", stdin);
	freopen("a_large.in", "r", stdin);
	freopen("a_large.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		long long int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];
		}
		long long int tot1 = 0, max_drop = 0;
		for (int i = 1; i < n; ++i)
		{
			if(A[i] < A[i-1])
				tot1 += (A[i-1]-A[i]);
			max_drop = max(max_drop, (A[i-1]-A[i]));
		}
		long long int tot2 = 0;
		for (int i = 1; i < n; ++i)
		{
			tot2+=min(max_drop,A[i-1]);
		}
		cout<<"Case #"<<case_num<<": "<<tot1<<" "<<tot2<<"\n";
	}
	return 0;
}