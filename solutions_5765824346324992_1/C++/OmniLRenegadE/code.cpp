#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#define LL long long
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define mp make_pair
#define sqr(x) x*x
#define LL long long 

void smain();
int main() {
	ios_base::sync_with_stdio(false);

#ifdef _DEBUG
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
#endif

	smain();

	return 0;
}

#define int long long

void smain() {
	int T;
	cin>>T;

	forn(tt,T) {
		int n, m;
		int step, val, nx;
		int tm;

		cin>>m>>n;
		vector <int> a(m);
		forn(i,m)
			cin>>a[i];

		int barb=-1;
		val=-1;
		step = 1;
		int ll=0;

		while (step>0) {
			nx = val + step;

			ll=0;
			forn(i,m)
				ll += 1 + nx/a[i];

			if (ll>=n)
				step/=2;
			else {
				val = nx;
				step *= 2;
			}
		}

		ll=0;
		if (val>=0) {
			forn(i,m) {
				ll += 1 + val/a[i];
			}
		}

		val++;
		forn(i,m) {
			if (val%a[i]==0)
				ll++;

			if (ll==n) {
				barb = i;
				break;
			}
		}

		cout<<"Case #"<<(tt+1)<<": "<<(barb+1)<<'\n';
	}
}