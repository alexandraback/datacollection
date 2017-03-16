#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int t,i,j,k,n,l,cnt,ans,med,ch;
	vector<int> which[100];
	vector<int> count[100];
	vector<int> test;
	string s[100];
	int possible;	
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		ans=0;
		possible=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{	s[i].clear();
			//scanf("%s",s[i]);
			cin>>s[i];
		}	
		for(i=0;i<n;i++)
		{	cnt=0;
			which[i].clear();
			count[i].clear();
			for(j=0;j<s[i].length();j++)
			{
				if(j==0)
				{
					ch = s[i][j]-'0';
					cnt=1;
				}
				else if(s[i][j]!=s[i][j-1])
				{
					which[i].push_back(ch);
					count[i].push_back(cnt);
					ch = s[i][j]-'0';
					cnt=1;
				}
				
				else
					cnt++;		
			}
			which[i].push_back(ch);
			count[i].push_back(cnt);
		}
		for(i=1;i<n;i++)
		{	if(which[i].size()!=which[0].size())
			{
				possible =-1;
				break;
			}
		}	
		for(i=0;i<which[0].size();i++)
		{	
			for(j=1;j<n;j++)
				if(which[j][i]!=which[0][i])
				{
					possible =-1;
					break;
				}
			if(possible==-1)
				break;
		}		
		if(possible!=-1)
		{for(i=0;i<which[0].size();i++)
		{	
			test.clear();
			for(j=0;j<n;j++)
				test.push_back(count[j][i]);
			sort(test.begin(),test.end());
			med = test[test.size()/2];
			for(j=0;j<n;j++)
				ans += test[j]-med > med-test[j]?test[j]-med:med-test[j];
				
		}
		printf("Case #%d: %d\n",k,ans);
		}
		else
			printf("Case #%d: Fegla Won\n",k);			
	}
}
