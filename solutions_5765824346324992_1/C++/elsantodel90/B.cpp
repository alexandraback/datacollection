#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define all(c) (c).begin(),(c).end()

#define esta(x,c) ((c).find(x) != (c).end())
#define zMem(c) memset((c),0,sizeof(c))

typedef long long tint;
typedef long double tdbl;

typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;

const int MAXB = 1000000;

tint v[MAXB];
tint B,N;

tint f(tint c)
{
    tint x = B;
    forn(i,B) x += c / v[i];
    return x;
}

int main()
{
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
         cin >> B >> N;
        forn(i,B)
            cin >> v[i];
        tint res;
        if (N <= B)
            res = N;
        else
        {
            tint a = 0, b = v[0] * N; // propiedad que b cumple : Hay >= N personas "adentro"
            while (b - a > 1)
            {
                tint c = (a+b) / 2;
                tint x = f(c);
                if (x >= N)
                    b = c;
                else
                    a = c;
            }
            // b es el instante en que entramos.
            tint cant = f(a);
            forn(i,B)
            if (b % v[i] == 0)
            {
                cant++;
                if (cant == N)
                    res = i+1;
            }
        }
		cout << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}
