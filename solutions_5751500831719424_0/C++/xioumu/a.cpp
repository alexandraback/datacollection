/*
 * Author:  xioumu
 * Created Time:  2014/5/4 0:10:38
 * File Name: a.cpp
 * solve: a.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
#define out(x) printf(#x" %d\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const int maxint = -1u>>1;
const double eps = 1e-8;
const int maxn = 100 + 10;

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

vector<int> b[maxn];
int m;
string ss;

int main() {
    int T, ca = 1, n;
    freopen("A.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        bool haveAns = true;
        scanf("%d", &n);
        ss.clear();
        rep (i, n) {
            b[i].clear();
            string sa, sb;
            cin >> sa;
            int tmp = 0;
            rep (j, sz(sa)) {
                if (j == 0 || sa[j] != sa[j - 1])  {
                    sb.push_back(sa[j]);
                    if (j != 0) {
                        b[i].push_back(tmp);
                    }
                    tmp = 1;
                }
                else 
                    tmp++;
            } 
            b[i].push_back(tmp);
            if (i == 0) ss = sb;
            else if (sb != ss)
                haveAns = false;
        }
        printf("Case #%d: ", ca++); 
        if (!haveAns) 
            printf("Fegla Won\n");
        else {
            int ans = 0;
            rep (j, sz(b[0])) {
                vector<int> c;
                rep (i, n) {
                    c.push_back(b[i][j]);
                }
                sort(c.begin(), c.end());
                rep (i, sz(c))
                    ans += abs(c[i] - c[sz(c) / 2]);
            }       
            printf("%d\n", ans);
        }
    }
    return 0;
}
