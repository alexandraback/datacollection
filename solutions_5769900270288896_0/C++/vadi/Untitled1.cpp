#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	
	for(int tt=1;tt<=t;tt++)
	{
		int ans1=100000;
		long long r,c,n;
		cin>>r>>c>>n;
		if(r*c==0)
		{
			cout<<"Case #"<<tt<<": "<<0<<endl;
			continue;
		}
		for(int i=0;i<pow(2,r*c);i++)
		{
			int a[r][c];
			int ans=0;
			int temp=i;
			int h=0;
			while(temp)
			{
				if(temp%2==1)
					h++;
				temp/=2;
			}
			if(h==n)
			{
			//	cout<<i<<" ";
				
				int x=0,y=0;
				int temp=i;
				while(temp)
				{
					if(temp%2==1)
						a[x][y]=1;
					else
						a[x][y]=0;
					temp/=2;
				//	cout<<x<<" "<<y<<"a"<<endl;
					y++;
					if(y==c)
					{
						y=0;
						x++;
					}
				}
				
				while(x<r)
				{
					if(x==r-1&&y==c)
						break;
					a[x][y]=0;
					y++;
					if(x==r-1&&y==c)
						break;
				//	cout<<x<<" "<<y<<endl;
					if(y==c)
					{
						y=0;
						x++;
					}
				}
			
			
		/*	for(int i=0;i<r;i++)
			{	for(int j=0;j<c;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}*/
			for(int i=0;i<r;i++)
				for(int j=0;j<c-1;j++)
				{
					if(a[i][j]==1&&a[i][j+1]==1)
						ans++;
				}
			for(int i=0;i<c;i++)
				for(int j=0;j<r-1;j++)
				{
					if(a[j][i]==1&&a[j+1][i]==1)
						ans++;
				}
				ans1=min(ans,ans1);
			}
			
		}
		
		cout<<"Case #"<<tt<<": "<<ans1<<endl;
			
	}
	
	return 0;
}
