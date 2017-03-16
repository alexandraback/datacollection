#include "bits/stdc++.h"
using namespace std;
struct ele
{
	int val;
	char c;
};

bool comp( ele a , ele b)
{
	return a.val < b.val;
}
int main()
{
	int t;
	int n;
	ele p[26];
	cin>>t;
	int sum = 0;
	for (int i = 1; i <=t; ++i)
	{
		cin>>n;
		sum = 0;
		for(int j=0; j<n; j++)
		{
			cin>>p[j].val;
			p[j].c = char(65 + j);
			sum += p[j].val;
		}

		sort(p, p+n, comp);
		cout<<"Case #"<<i<<": ";
		while(sum > 0 )
		{
			cout<<p[n-1].c;
			p[n-1].val--;
			sum--;
			sort(p, p+n, comp);
			if( p[n-2].val * 2 <= sum -1)
			{
				cout<<p[n-1].c<<" ";
				p[n-1].val--;
				sum--;
				sort(p, p+n, comp);
			}
			else
				cout<<" ";
		}
		cout<<endl;
	}
}