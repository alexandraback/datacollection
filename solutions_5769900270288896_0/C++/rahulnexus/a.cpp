#include<iostream>
#include<cstdio>
using namespace std;
int ans[258];
int main()
{
	int r,c,n;
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
	cin>>r>>c>>n;
	int mp[17][17];
	for(int i=0;i<258;i++)
		ans[i]=999999;
	for(int i=0;i<(1<<r*c);i++)
	{
		int j=i;
		int k=0;
		int cnt=0;
		while(k<r*c)
		{
			if(j&1)
			{
				mp[k/c][k%c]=1;
				cnt++;
			}
			else
			{
				mp[k/c][k%c]=0;
			}
			j>>=1;
			k++;
		}
		int temp=0;
		for(int ii=0;ii<r;ii++)
			for(int jj=0;jj<c;jj++)
			{
				if((ii+1<r&&mp[ii][jj]==1&&mp[ii+1][jj]==1))
				{
					temp++;
				}
				if((jj+1<c&&mp[ii][jj]==1&&mp[ii][jj+1]==1))
				{
					temp++;
				}
			}
		ans[cnt]=min(ans[cnt],temp);
	}
	cout<<"Case #"<<tc<<": "<<ans[n]<<"\n";
	}
	return 0;
}
