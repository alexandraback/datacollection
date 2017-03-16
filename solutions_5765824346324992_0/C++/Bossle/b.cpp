#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int lli;

lli b,n;
vector<lli> m;

bool isenoughtime(lli t)
{
	lli served=0;
	for(int i=0;i<b;++i)
		served+=(t/m[i])+1;
	return served>=n;
}

int main()
{
	int t;
	cin >> t;
	for(int ta=1;ta<=t;++ta)
	{
		cout << "Case #" << ta << ": ";
		cin >> b >> n;
		m.resize(b);
		for(int i=0;i<b;++i)
			cin >> m[i];
		lli mintime=0, maxtime=100000LL*n;
		while(maxtime-mintime>1)
		{
			lli mid = (mintime+maxtime)/2;
			if(isenoughtime(mid))
				maxtime=mid;
			else
				mintime=mid;
		}
		lli righttime = (isenoughtime(mintime)?mintime:maxtime);
		lli served = 0;
		int resp;
		for(int i=0;i<b;++i)
			served+=(righttime-1)/m[i]+1;
		for(int i=0;i<b;++i)
			if(righttime%m[i]==0)
				if(served==n-1)
				{
					resp=i;
					break;
				}
				else
					served++;
		cout << resp+1 << endl;
	}
}
