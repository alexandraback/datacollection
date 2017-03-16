#include <bits/stdc++.h>
#define N 128

using namespace std;
int t,n;
int p[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>p[i];
		int sum = 0;
		for(int i=0;i<n;++i)
			sum+=p[i];
		cout<<"Case #"<<c<<":";
		while(sum>0)
		{
			int maximum1 = 0;
			int maximum2 = 0;
			int maximum3 = 0;
			int pos1=0,pos2=0, pos3 = 0;
			for(int i=0;i<n;++i)
			{
				if(maximum1<=p[i])
				{
					maximum3 = maximum2;
					maximum2 = maximum1;
					pos2 = pos1;
					maximum1 = p[i];
					pos1 = i;
				}
			}
			if(maximum1>=2 && maximum1-2<=(sum-2)/2 && maximum2<=(sum-2)/2)
			{
				char c = 'A'+pos1;
				cout<<" "<<c<<c;
				p[pos1]-=2;
				sum-=2;
			}
			else if(maximum2>0 && maximum1-1<=(sum-2)/2 && maximum2-1<=(sum-1)/2 && (maximum3<=(sum-2)/2 ||maximum3==0))
			{
				char c1 = 'A'+pos1;
				char c2 = 'A'+pos2;
				p[pos1]--;
				p[pos2]--;
				cout<<" "<<c1<<c2;		
				sum-=2;	
			}
			else
			{
				char c = 'A'+pos1;
				p[pos1]--;
				cout<<" "<<c;
				sum--;
			}
		}
		cout<<endl;
	}
	return 0;
}