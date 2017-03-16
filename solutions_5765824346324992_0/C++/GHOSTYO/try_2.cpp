/*
Prashant Gupta(GHOST_YO)
IIITA
*/
/*
start of libraries to be included in the program
*/
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <ctime>
#include <stack>
#include <sstream>
#include <limits.h>
/*
end of libraries to be included in the program
*/
using namespace std;
/*
start of MACRO definition
*/
#define For(i,a,b) for(i=a;i<=b;i++)
#define Ford(i,a,b) for(i=a;i>=b;i--)
#define Rep(i,c) for((i=c.begin());i!=c.end();i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sr(x) (int)x.size()
#define modul 1000000007
#define nmax 500100
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {For(i,a,b) cout << x[i] << ' '; cout << endl;}
#define fillchar(x,a,b,delta) For(_,a,b) x[_]=delta;
#define FILL(a) memset(a,0,sizeof(a));
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scc(a) scanf("%c", &a)
#define scs(a) scanf("%s", a)
#define Bit(s,i) ((s&(1<<i))>0)
#define Two(x) (1<<x)
#define pii pair<int,int>
#define ll long long
#define e 1e-6
#define PI acos(-1)
#define piii pair < pii ,int >
#define make(a,b,c) mp(mp(a,b),c)
#define gc getchar

#define pc putchar


int cost[10];

int rec(int *vis, int b, int x, int n)
{
    if (x == (n-1)) {
        int minval = 10000007, pos;
        for (int  i = 0; i < b; i++) {
            if (vis[i] < minval) {
                minval = vis[i];
                pos = i;
            }
        }

        //cout << pos << endl;

        return (pos+1);
    }

    int i, retval, flag = 0;

    for (i = 0; i < b; i++) {
        if (vis[i] == 0) {
            flag = 1;

            break;
        }
    }

    if (flag) {
        for (i = 0; i < b; i++) {
            if (vis[i] == 0) {
                vis[i] += cost[i];

                break;
            }
        }

        return rec(vis, b, x+1, n);
    }

    else {
        for (i = 0; i < b; i++)
            vis[i]--;

        return rec(vis, b, x, n);
    }
}

int main()
{
    int t;

    freopen("inp.txt", "r", stdin);
    freopen("op.txt", "w", stdout);

    cin >> t;



    for (int lol = 1; lol <= t; lol++) {
        int b, n, i, vis[10];

        memset(vis, 0, sizeof(vis));

        cin >> b >> n;

        cin >> cost[0];
        int  gcd = cost[0];
        int temp = cost[0];
        For(i, 1, b - 1) {
            cin >> cost[i];
            gcd = __gcd(temp, cost[i]);
            temp *= cost[i];
            temp /= gcd;
        }

        int t1 = 0;
        For(i, 0, b - 1) {
            t1 += (temp / cost[i]);
        }

        n %= t1;

        if (n == 0)
            n += t1;

        //cout << n << endl;

        int k = 1;
        int ans = -1, j;
        for (i = 0; i < 1000005; i++) {
            for (j = 0; j < b; j++) {
                if (i % cost[j] == 0) {
                    if (k == n) {
                        ans = j+1;

                        break;
                    }

                    k++;

                }
            }

            if (ans != -1)
                break;
        }

        cout << "Case #" <<lol << ": " << ans << endl;
    }

    return 0;
}
