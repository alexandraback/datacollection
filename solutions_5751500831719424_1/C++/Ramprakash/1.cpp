#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	k=t;
	while(t--)
	{
		int n,i,l,j,last;
		cin>>n;
		string s;
		cin>>s;
		char a[100];
		int b[100][n];
		a[0]=s[0];l=0;
		b[0][0]=1;
		for(i=1;i<s.length();i++)
			if(s[i]!=a[l])
			{
				a[++l]=s[i];
				b[l][0]=1;
			}
			else
				b[l][0]++;
		last=l;
		bool flag=true;
		for(i=1;i<n;i++)
		{
			cin>>s;
			if(flag)
			{
				l=0;b[l][i]=0;
				for(j=0;j<s.length();j++)
					if(s[j]==a[l])
						b[l][i]++;
					else
					{
						if(b[l][i]==0){flag=false;break;}
						l++;j--;
						if(l>last){flag=false;break;}
						b[l][i]=0;
					}
				if(l<last){flag=false;}
			}
		}
		int ans=0;
		cout<<"Case #"<<k-t<<": ";
		if(!flag)cout<<"Fegla Won"<<endl;
		else
		{
			for(i=0;i<=last;i++)
				sort(b[i],b[i]+n);
			int ans=0;
			for(i=0;i<=last;i++)
			{
//				cout<<a[i]<<": ";
//				for(j=0;j<n;j++)
//					cout<<b[i][j]<<" ";
//				cout<<endl;
				int m=(n-1)/2;
				for(j=0;j<m;j++)
					ans+=(b[i][m]-b[i][j]);
				for(j=m+1;j<n;j++)
					ans+=(b[i][j]-b[i][m]);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

