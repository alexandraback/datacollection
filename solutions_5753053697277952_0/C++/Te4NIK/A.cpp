#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz size()
#define x first
#define y second
#define forn(i, n) for(int i=0; i<(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;

int n,T,k;
pair <int,char> p[30];
int c;

int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	cin >>T;
	forn(I,T)
	{
		cin >>n;
		forn(i,30)
			p[i]=mp(0,0);
		k=0;
		forn(i,n)
		{
			cin >>c;
			k+=c;
			p[i].x=c;
			p[i].y=i+'A';
		}
		sort(p,p+n);
		reverse(p,p+n);
		
		cout <<"Case #"<<I+1<<": ";
		while(k>0)
		{
			if(2*(p[0].x-1)<=k-2 && 2*(p[1].x-1)<=k-2 && k%2==0)
			{
				cout <<p[0].y<<p[1].y;
				p[0].x--,p[1].x--;
				k-=2;
			}
			else
			{
				cout <<p[0].y;
				p[0].x--;
				k--;
			}
			if(k>0)
				cout <<' ';

			forn(i,n)
			{
				if(2*p[i].x>k)
					cout <<"ARGH";
			}
			
			sort(p,p+n);
			reverse(p,p+n);
		}
		cout <<endl;
	}

	return 0;
}
