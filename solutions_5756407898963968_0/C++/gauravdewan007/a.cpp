#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>

#include <cmath>
#include <cstring>
using namespace std;

#if 0
#include "generic.h"
#define cin fin
#define cout fout
#endif

int main()
{
	int t,c;
	cin>>t;
	for(c=1;c<=t;c++)
	{
		set<int> s,r,ans;
		int a,b,i;
		cin>>a;
		for(i=0;i<16;i++)
		{
			cin>>b;
			if(i/4 + 1 == a)
				s.insert(b);
		}
		
		cin>>a;
		for(i=0;i<16;i++)
		{
			cin>>b;
			if(i/4 + 1 == a)
				r.insert(b);
		}
		set_intersection(s.begin(),s.end(),r.begin(),r.end(), inserter(ans, ans.begin()));
		cout<<"Case #"<<c<<": ";
		if(ans.empty())
			cout<<"Volunteer cheated!";
		else if(ans.size() == 1)
			cout<<*(ans.begin());
		else
			cout<<"Bad magician!";
		cout<<endl;
	}
	return 0;
}