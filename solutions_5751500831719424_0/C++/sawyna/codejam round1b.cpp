#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#define PB push_back
#define MP make_pair
#define LL long long int
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
using namespace std;

int main()
{
	int T,i,j,n,k;
	int ans,a[101],b[101][101];
	char ch;
	string temp,s[101],str[101];
	cin>>T;
	int temp1;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		str[i] = "";

		for(i=1;i<=n;i++)
		{
			cin>>s[i];
			k = 0;
			for(j=0;j<s[i].length();j++)
			{
				if(j == s[i].length()-1)
				{
					str[i] += s[i][j];
					b[i][k] = j;	
				}
				else
				{
					if(s[i][j] == s[i][j+1])
					{
						temp1 = j; 
						while(s[i][j] == s[i][j+1])
						{
							j++;
							if(j == s[i].length()-1)
							break;
						}
						str[i] += s[i][j];
						b[i][k] = temp1; 
						k++;
					}
					else
					{
						str[i] += s[i][j];
						b[i][k] = j;
						k++;
					}
				}
			}
			//cout<<str[i]<<endl;
			//system("pause");
		}
		temp = str[1];
		for(i=1;i<=n;i++)
		{
			if(str[i] != temp)
			break;
		}
		int f = 0;
		ans = 0;
		if(i <= n)
		{
			cout<<"Case #"<<t<<": ";
			cout<<"Fegla Won"<<endl;
			continue;
		}
		else
		{
			for(i=0;i<str[1].length();i++)
			{
				ch = str[1][i];
				for(j=1;j<=n;j++)
				{
					
					f = 0;
					k = b[j][i];
					while(s[j][k] == ch)
					{
						k++;
						f++;
						if(k == s[j].length())
						break;
					}
					a[j] = f;
				}
				sort(a+1,a+n+1);
				for(j=1;j<=n;j++)
				{
					//cout<<a[j]<<endl;
					//system("pause");
					ans += abs(a[j] - a[(n/2) + 1]);
				}
				//cout<<ch<<"next"<<endl;
			}
			cout<<"Case #"<<t<<": ";
			cout<<ans<<endl;
		}
	}
	
	return 0;
}

