#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(i=a;i<b;i++)
#define vi vector<int>

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	int i,j,k;
	FOR(i,1,t+1)
	{
		vi freq(17,0);
		int r;
		FOR(j,0,2)
		{
			cin>>r;
			r--;
			int en;
			FOR(k,0,16)
			{
				cin>>en;
				if(k/4==r)
					freq[en]++;
			}
		}
		int cnt=0;
		int ans=1;
		FOR(j,1,17)
		{
			if(freq[j]==2)
			{
				cnt++;
				ans=j;
			}
		}
		cout<<"Case #"<<i<<": ";
		if(cnt==0)
			cout<<"Volunteer cheated!";
		else if(cnt==1)
			cout<<ans;
		else
			cout<<"Bad magician!";
		cout<<endl;
	}
				
	return 0;
}
	
