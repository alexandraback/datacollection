#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int main() 
{
	int t,n,p,cas=0;
	string s,hlp;
	vector<string> s1;
	set<string> st;
	vector<int> v,pos;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++cas<<": ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			s1.push_back(s);
		}
		for(int i=0;i<s1.size();i++)
		{
			hlp=s1[i][0];p=0;
			for(int j=1;j<s1[i].length();j++)
			{
				if(s1[i][j]==hlp[p])
					continue;
				hlp+=s1[i][j];
				p++;
			}
			st.insert(hlp);
		}
//		cout<<hlp<<" ";
		int ans=0,d,c1=0,med;
		if(st.size()==1)
		{
			pos.clear();
			for(int j=0;j<n;j++)
				pos.push_back(0);
			for(int i=0;i<hlp.length();i++)
			{
				v.clear();
				for(int j=0;j<s1.size();j++)
				{
					c1=0;
					while(s1[j][pos[j]]==hlp[i])
					{
						pos[j]++;c1++;
					}
					v.push_back(c1);
				}
				sort(v.begin(),v.end());
				med=v[n/2];
				for(int j=0;j<n;j++)
				{
					d=v[j]-med;
					if(d<0)
						d*=(-1);
					ans+=d;
				}
//				cout<<ans<<" ";
			}
			cout<<ans<<endl;
		}
		else 
			cout<<"Fegla Won"<<endl;
		st.clear();s1.clear();
	}
	return 0;
}