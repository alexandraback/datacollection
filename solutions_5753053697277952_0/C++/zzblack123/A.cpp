/***************************************
      zzblack                         **
      2016-05-08                      **
      Orz                             **
****************************************/
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls id<<1,l,mid
#define rs id<<1|1,mid+1,r
#define OFF(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(x) memset(x,0x3f,sizeof x)
typedef long long ll ;
typedef pair<int,int> pii ;
const int maxn = 1e5 + 50 ;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f ;
const int MOD = 1e9+7 ;

inline int read(){
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

struct Party{
    int id;
    int num;
    Party(int id = 0, int num = 0):id(id), num(num){}
    bool operator < (const Party &rhs) const{
        return num < rhs.num;
    }
} p[30];

int main () {
#ifdef LOCAL
	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);
      freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);
#endif
    int cas = 1, T = read();
    while (T--) {
        int n = read();
        int tot = 0;
        priority_queue<Party> pq;
        for (int i = 1; i <= n; i++) {
            int x = read();
            tot += x;
            p[i] = Party(i, x);
            if (x) pq.push(p[i]);
        }
//        printf("%d\n", tot);
        printf("Case #%d: ", cas++);
        while (tot > 0) {
//                printf("%d\n", tot);
            Party u = pq.top(); pq.pop();
            Party v = pq.top(); pq.pop();
            int ans1 = u.id, ans2 = v.id;
            if ((u.num - 1) * 2 > tot - 2) ans2 = ans1;
            else {
                if (pq.size() && pq.top().num * 2 > tot - 2) ans2 = 0;
                else ans2 = v.id;
            }
            tot--;
            if (ans2) tot--;
            u.num--;
            if(ans2 == u.id) u.num--;
            else if (ans2 == v.id) v.num--;
            if (u.num) pq.push(u);
            if (v.num) pq.push(v);
            printf("%c", ('A' + ans1 - 1));
            if (ans2) printf("%c", ('A' + ans2 - 1));
            if (pq.size()) printf(" ");
            else printf("\n");
        }



    }


	return 0;
}
