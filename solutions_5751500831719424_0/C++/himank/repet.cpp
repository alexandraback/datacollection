#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cstring>
using namespace std;
int freq[101][101];
int main()
{
	int t;
	cin>>t;
	for(int te=1;te<=t;te++)
	{
		int n;
		cin>>n;
		string s;
		//int m=s.length();
		string let[n];
		memset(freq,0,sizeof(freq));
		for(int i=0;i<n;i++)
		{
			cin>>s;
			int m=s.length();
			let[i]=let[i]+s[0];
			freq[i][let[i].length()-1]=1;
			for(int j=1;j<m;j++)
			{
				if(s[j]!=s[j-1])
				{
					let[i]=let[i]+s[j];
					freq[i][let[i].length()-1]=1;
				}
				else
				{
					freq[i][let[i].length()-1]++;	
				}

			}
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(let[i]!=let[0])
			{
				cout<<"Case #"<<te<<": "<<"Fegla Won"<<endl;
				flag=1;
				break;
			}
			//cout<<let[i].length()<<endl;
		}
		if (flag==1)
		continue;
		int m=let[0].length();
		int ans=0;
		for(int i=0;i<m;i++)
		{
			int maxi=freq[0][i];
			for(int j=0;j<n;j++)
			{
				maxi=max(freq[j][i],maxi);
				//cout<<freq[j][i]<<endl;
			}
			int x=0,temp=1000000;
			for(int k=1;k<=maxi;k++)
			{
				x=0;
				for(int j=0;j<n;j++)
					x=x+abs(k-freq[j][i]);
				temp=min(temp,x);
			}	
			ans=ans+temp;
			
		}
		cout<<"Case #"<<te<<": "<<ans<<endl;
	}
}