#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <string.h>
#include <list>
#include <time.h>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define PI 3.14159265358979
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define L(s) (int)((s).size())
#define sz(s) (int)((s).size())
#define ms(x) memset(x,0,sizeof(x))
#define ms1(x) memset(x,-1,sizeof(x))
#define del(y,x) erase(y.begin()+x)

typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const ll MOD = 1000000007;

ll ABS(ll a) {
    if(a<0)
        return a*(-1);
    else
        return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int test = 1;
	while(T--)
	{
		int n;
		cin >> n;
		vector<pii> sen;
		for(int i = 0;i < n;i++)
		{
			int a;
			cin >> a;
			sen.pb(mp(a,i));
		}
		sort(ALL(sen));
		reverse(ALL(sen));
		printf("Case #%d: ",test++);
		while(sen[0].X!=sen[1].X)
		{
			sen[0].X--;
			printf("%c ", 'A' + sen[0].Y);
		}
		for(int i = 2;i < n;i++){
			for(int j = 0;j < sen[i].X;j++)
			{
				printf("%c ", 'A' + sen[i].Y);
			}
		}
		for(int i = 0;i < sen[0].X;i++)
		{
			printf("%c%c", 'A' + sen[0].Y,'A' + sen[1].Y);
			if(i!=sen[0].X-1)
			{
				cout << " ";
			}
		}
		cout << endl;

	}

    return 0;
}