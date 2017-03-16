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
#define sz 1000 * 1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define for(xx1 , yy1 , zz1) for(int zz1 = xx1 ; zz1 <= yy1 ; zz1++)
#define mp make_pair
const double PI  = acos(-1.0);

int w[100], a[100][100], b[100][100], c, ans, r1, r2, t;

int main(){
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    for (1, t, T)
    {
    	cin >> r1;
    	for (1, 4, i)
    		for (1, 4, j)
    			cin >> a[i][j];
       	cin >> r2;
       	for (1, 4, i)
       		for (1, 4, j)
       			cin >> b[i][j];
      	for (1, 4, i)
      	{
      		w[a[r1][i]]++;
      		w[b[r2][i]]++;
      	}
      	c = 0;
      	for (1, 16, i)
      	{
      		if (w[i] == 2)
      			c++, ans = i;
      		w[i] = 0;
      	}
      	cout << "Case #" << T << ": ";
      	if (!c)
      		cout << "Volunteer cheated!";
      	if (c == 1)
      		cout << ans;
      	if (c > 1)
      		cout << "Bad magician!";
      	cout << "\n";
    }
    return 0;
}

