#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() 
{
	int t,n,p,cas=0;
	string s1,s2,st1,st2;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++cas<<": ";
		cin>>n;
		cin>>s1>>s2;
		st1=s1[0];p=0;
		for(int i=1;i<s1.length();i++)
		{
			if(s1[i]==st1[p])
				continue;
			st1+=s1[i];
			p++;
		}
		st2=s2[0];p=0;
		for(int i=1;i<s2.length();i++)
		{
			if(s2[i]==st2[p])
				continue;
			st2+=s2[i];
			p++;
		}
		int ans=0,p1=0,p2=0,d,c1=0,c2=0;
		if(st1.compare(st2)==0)
		{
			for(int i=0;i<st1.size();i++)
			{
				while(s1[p1]==st1[i])
				{
					p1++;c1++;
				}
				while(s2[p2]==st1[i])
				{
					p2++;c2++;
				}
				d=c1-c2;
				c1=0;c2=0;
				if(d<0)
					d*=(-1);
				ans+=d;
			}
			cout<<ans<<endl;
		}
		else 
			cout<<"Fegla Won"<<endl;
	}
	return 0;
}