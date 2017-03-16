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

double a[20000];

void smain() {
	int T;
	cin>>T;

	int n, b;
	double d;
	bool v;
	forn(tt,T) {
		cout<<"Case #"<<(tt+1)<<": ";
		cin>>n;
		
		forn(i,n)
			cin>>a[i];

		int r=0;
		for (int i=1;i<n;i++) 
			if (a[i-1] > a[i])
				r += a[i-1]-a[i];

		cout<<r<<' ';		
		
		r = -1;
		for (int q=1;q<n;q++) {
			if (a[q-1]>a[q]) {
				d = (a[q-1]-a[q])/(10.0);
			}
			else 
				d=0;

			v= true;
			b = 0;
			for (int i=1;i<n;i++) {
				if (a[i-1]-10*d>a[i])
				{
					v = false;
					break;
				}

				b += min(a[i-1], 10*d);
			}

			if (v && (r==-1 || r>b)) 
				r = b;
		}
		cout<<r<<'\n';
	}
}