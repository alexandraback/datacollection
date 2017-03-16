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

const double EPS=10E-7;
int ll[10000];
double x[10000], y[10000];

void smain() {
	int T;
	cin>>T;

	int n, qt;
	bool nx;
	double a, b, c, d;
	bool a1=false, a2=false;

	forn(tt,T) {		
		cin>>n;

		forn(i,n) {
			cin>>x[i]>>y[i];
			ll[i] = n-1;
		}

		nx=false;
		for (int qq=(1<<n)-1;qq>0;qq--) {
			nx = false;

			forn(i,n)
				if (qq==(1<<i)) {
					nx = true;
					break;
				}

			qt = 0;
			forn(i,n)
				if (qq & (1<<i))
					qt++;
			qt = n-qt;

			if (nx)
				continue;

			forn(i,n) if (qq & (1<<i))
				forn(j,n) if (i!=j && (qq & (1<<j))) {
					a = y[j]-y[i];
					b = x[i]-x[j];
					c = -a*x[i]-b*y[i];

					a1 = false;
					a2 = false;

					forn(k,n) if (qq & (1<<k)) {
						d = a*x[k] + b*y[k] + c;

						if (d<-EPS)
							a1 = true;

						if (d>EPS)
							a2 = true;
					}

					if (!a1 || !a2) {
						ll[i] = min(ll[i], qt);
						ll[j] = min(ll[j], qt);
					}
			}
		}

		cout<<"Case #"<<(tt+1)<<":\n";
		forn(i,n)
			cout<<ll[i]<<'\n';
	}
}