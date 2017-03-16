/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case #%d:",cs);
//}
//}
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int INF = 1<<29;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
string st[101];
int ans;
vector<pair< char, int>>v[101];
vector<int >vv;
int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
     freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t) {
        int n = II;
        int ret = INF;
        For(i,n) cin >> st[i];
        For(i,n) {
            int len = st[i].size();
            rep(j,len) {
                char ch = st[i][j];
                int cnt = 0;
                while(j<len && ch == st[i][j]) {
                    cnt++;
                    j++;
                }
                j--;
                v[i].pb(make_pair(ch,cnt));
            }
        }
        bool flag = true;
        set<int >s;
        For(i,n){
            int tmp = v[i].size();
            s.insert(tmp);
        }

        int tmp = s.size();
        if(tmp != 1) {
            flag = false;
        }
        else{
            tmp = v[1].size();
            rep(i,tmp){
                char  ch = v[1][i].first;
                int Max = 0;
                For(j,n){
                    Max = max(v[j][i].second,Max);
                    if(ch == v[j][i].first) continue;
                    flag = false;
                    break;
                }
                vv.pb(Max);
                if(!flag) break;
            }
            if(flag){

                ret = 0;
                int cnt = 0;
                forstl(it,vv){
                    int tmp = *it;
                    int Min = INF;
                    For(i,tmp){
                        int ans = 0;
                        For(j,n){
                            ans += abs(v[j][cnt].second - i);
                        }
                        Min = min(Min,ans);
                    }
                    cnt++;
                    ret += Min;
                }

            }
        }
        OC;
        if(!flag) cout << " Fegla Won\n";
        else cout << " " << ret << endl;
        For(i,n) v[i].clear();
        vv.clear();
    }
}
