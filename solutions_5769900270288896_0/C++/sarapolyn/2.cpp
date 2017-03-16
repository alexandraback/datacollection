#include<bits/stdc++.h>
using namespace std;
int bitcount(int i)
{
  int res =0;
  while(i>0)
  {
    if(i&1)res++;
    i>>=1;
  }
  return res;
}
int main()
{
	int n,t,i,ans,r,c,j,k;
	cin>>t;
	for(int it=0;it<t;it++)
	{
		cin>>r>>c>>n;
		vector<vector<int> > arr(r+2, vector<int> (c+2,0));
		int finans = 1000000000;
		for(i=0;i<(1<<(r*c));i++)
		{
			if(bitcount(i)==n)
			{
				int l = i;
				for(j=1;j<=r;j++)
				{
					for(k=1;k<=c;k++)
					{
						arr[j][k]=l%2;
						l/=2;
					}
				}
				int ans = 0;
				for(j=1;j<=r;j++)
				{
					for(k=1;k<=c;k++)
					{
						if(arr[j][k])
						{
							ans+=arr[j-1][k]+arr[j+1][k]+arr[j][k-1]+arr[j][k+1];
						}
					}
				}
				finans = min(finans, ans);
			}
		}
		cout<<"Case #"<<it+1<<": "<<finans/2<<endl;
	}
	return 0;
}