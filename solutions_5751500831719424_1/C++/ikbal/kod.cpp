#include <algorithm>
#include <iostream>
#include <cstring>
#include <limits>
#include <complex>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <set>

#define type(x) __typeof((x).begin())
#define foreach(it,x) for(__typeof(x.begin()) it = x.begin() ; it!=x.end() ; it++ )

#ifdef KAZAR
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

using namespace std;

template<class T> inline void umax(T &a,T b){if(a<b) a = b ; }
template<class T> inline void umin(T &a,T b){if(a>b) a = b ; }
template<class T> inline T abs(T a){return a>0 ? a : -a;}
template<class T> inline T gcd(T a,T b){return __gcd(a,b);}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}

const int inf = 1e9 + 143;
const long long longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

const int N = 111;

vector<pair<char, int> > v[N];

vector<pair<char, int> > parse(string s){
    vector<pair<char, int> > res;
    for(int i = 0; i < s.size(); i++){
        int j = i;
        while(j + 1 < s.size() && s[j + 1] == s[i]) ++j;
        res.push_back(make_pair(s[i], j - i + 1));
        i = j;
    }
    return res;
}

int main(){

#ifdef KAZAR
	freopen("f.input","r",stdin);
	freopen("f.output","w",stdout);
	freopen("error","w",stderr);
#endif

    int tc = read();

    for(int it = 1; it <= tc; it++){
        printf("Case #%d: ",it);
        int n = read();
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            v[i] = parse(s);
        }
        bool ok = true;
        for(int i = 1; i < n; i++){
            if(v[i].size() != v[0].size()){
                ok = false;
                break;
            }
            for(int j = 0; j < v[i].size(); j++)
                if(v[i][j].first != v[0][j].first)
                    ok = false;
        }
        if(!ok){
            puts("Fegla Won");
            continue;
        }
        int ans = 0;
        for(int i = 0; i < v[0].size(); i++){
            int opt = inf;
            for(int len = 0; len <= 100; len++){
                int s = 0;
                for(int j = 0; j < n; j++){
                    s += abs(len - v[j][i].second);
                }
                umin(opt, s);
            }
            ans += opt;
        }
        printf("%d\n",ans);
    }

    return 0;
}
