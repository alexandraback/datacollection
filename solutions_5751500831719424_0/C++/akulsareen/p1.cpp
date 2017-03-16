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
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
string key_make(string a)
{
	string ans="";
	ans+=a[0];
	for (int i = 1; i < a.length(); ++i)
	{
		if(a[i]==a[i-1])
			continue;
		ans+=a[i];
	}
	return ans;
}
vector <int> key_cmake(string a)
{
	vector <int> ans(1,1);
	for (int i = 0; i < a.length(); ++i)
	{
		if(a[i]==a[i-1])
			ans.back()++;
		else
			ans.push_back(1);
	}
	return ans;
}
int main()
{
	freopen("as.in","r",stdin);
	freopen("a_small.out","w",stdout);
	int t,n;
	cin>>t;
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		cin>>n;
		vector <string> A(n),key(n);
		vector < vector <int> > key_count(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			key[i]="";
			key[i]=key_make(A[i]);
			key_count[i]=key_cmake(A[i]);
		}
		bool flag=false;
		for (int i = 1; i < n; ++i)
		{
			if(key[i]!=key[i-1])
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			cout<<"Case #"<<test_case<<": "<<"Fegla Won\n";
			continue;
		}
		int ans=0;
		for (int i = 0; i < key_count[0].size(); ++i)
		{
			int tot=1000000,temp;
			for (int j = 1; j <= 100; ++j)
			{
				temp=0;
				for (int k = 0; k < n; ++k)
				{
					temp+=abs(key_count[k][i]-j);
				}
				tot=min(tot,temp);
			}
			ans+=tot;
		}
		if(ans>=1000000)
			cout<<"Case #"<<test_case<<": "<<"Fegla Won\n";
		else
			cout<<"Case #"<<test_case<<": "<<ans<<"\n";
	}
	return 0;
}