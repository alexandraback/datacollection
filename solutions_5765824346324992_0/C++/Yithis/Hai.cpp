#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

long long NWD (long long a, long long b)
{
	while (b!=0)
	{
		if (a>=b)
		{
			a%=b;
		}
	swap (a, b);
	}
return a;
}


long long czasy [2005];
set <pair <long long, long long> > fryzjerzy;

int main()
{
	int powtorzenia;
	cin >> powtorzenia;
	for (int x=1; x<=powtorzenia; x++)
	{
		long long a, n, NWW, cykl;
		cykl=0;
		NWW=1;
		fryzjerzy.clear();
		cin >> a >> n;
		for (int i=1; i<=a; i++)
		{
			cin >> czasy[i];
			NWW=(NWW*czasy[i])/NWD(NWW, czasy[i]);
			fryzjerzy.insert(make_pair(0, i));
		}
		
		set <pair <long long, long long > >::iterator k;
		pair <long long, long long> y;
		
		for (int i=1; i<=a; i++)
		{
			cykl+=NWW/czasy[i];
		}
		n%=cykl;
		if (n==0) n=cykl;

		for (long long i=0; i<n; i++)
		{
			k=fryzjerzy.lower_bound(make_pair(0, 0));
			y=*k;
			y.first+=czasy[y.second];
			fryzjerzy.erase(k);
			fryzjerzy.insert(y);
		}
	
		cout << "Case #" << x << ": " << y.second << endl;
	}
}
