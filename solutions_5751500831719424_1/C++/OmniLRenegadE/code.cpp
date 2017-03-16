#pragma comment(linker, "/STACK:64000000")
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define forn(i,n) for (LL i=0;i<n;i++)
#define rforn(i,n) for (LL i=n-1;i>=0;i--)
#define mp make_pair
#define __int64 long long
#define LL long long

int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int T;
	cin>>T;
	forn(t,T)
	{
		cout<<"Case #"<<(t+1)<<": ";
		int n;
		cin>>n;
		string s;
		vector <vector <pair <char, int> > > a(n);
		forn(i,n)
		{
			cin>>s;
			char c=' ';
			int col=0;
			forn(j,s.length())
			{
				if (col>0 && c!=s[j]){
					a[i].push_back(mp(c,col));
					col=0;
				}
				col++;
				c=s[j];
			}
			if (col>0)
			{
				a[i].push_back(mp(c,col));
			}
		}


		bool won=false;
		forn(i,n)
		{
			if (a[0].size() != a[i].size())
			{
				cout<<"Fegla Won\n";
				won=true;
				break;
			}
		}
		if (won)
			continue;

		int res=0;
		forn(j,a[0].size())
		{
			forn(i,n)
			{
				if (a[0][j].first != a[i][j].first) {
					won=true;
					break;
				}
			}
			if (won)
				break;

			int mn=-1, buf;
			for (int k=1;k<=100;k++)
			{
				buf=0;
				forn(i,n)
				{
					buf+=abs(k-a[i][j].second);
				}
				if (mn==-1 || mn>buf)
					mn=buf;
			}
			res+=mn;
		}

		if (won)
		{
			cout<<"Fegla Won\n";
		}
		else
		{
			cout<<res<<"\n";
		}
	}

}