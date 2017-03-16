//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;

#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base 10
#define fname ""
#define sz 1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define for(xx1 , yy1 , zz1) for(int zz1 = xx1 ; zz1 <= yy1 ; zz1++)
#define mp make_pair
const double PI  = acos(-1.0);

int T, c[sz], f, v[sz], ans, n, d[sz][sz], ch[sz][sz];
string s;

int main(){
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (1, T, t)
    {
    	cout << "Case #" << t << ": ";
    	for (0, 101, i)
    	{
    		c[i] = 0;
    		for (0, 101, j)
    			d[i][j] = 0;
    	}
    	cin >> n;
    	f = 1;
    	ans = 0;
    	for (1, n, i)
    	{
    		cin >> s;     
    		c[i] = 1;
    		d[i][1] = 1;
    		ch[i][1] = s[0];
    		for (1, len(s) - 1, j)
    		{
    			if (s[j] != s[j - 1])
    			{
    				d[i][++c[i]] = 1;
    				ch[i][c[i]] = s[j];
    			}
    			else
    				d[i][c[i]]++;
    		}
    		if (i > 1)
    			if (c[i] != c[i - 1])
    				f = 0;
    	}
    	for (1, c[1], i)
    	{
    		for (1, n, j)
    		{
    			v[j] = d[j][i];
    			if (ch[j][i] != ch[1][i])
    				f = 0;
    		}
    		sort(v + 1, v + 1 + n);
    		for (1, n, j)
    			ans += abs(v[(n + 1) / 2] - v[j]);
    	}
    	if (f)
    		cout << ans << "\n";
    	else
    		cout << "Fegla Won\n";
    }
    return 0;
}

