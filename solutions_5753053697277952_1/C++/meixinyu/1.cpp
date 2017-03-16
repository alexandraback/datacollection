/*  ^^ ====== ^^ 
ID: meixiuxiu
PROG: test
LANG: C++11
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
#define pi acos(-1.0)
#define maxn 40000
#define maxv 100005
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define LOCAL
struct node
{
    int cnt;
    int pos;
}a[30];
bool cmp(node a,node b){
    return a.cnt > b.cnt;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    int kase = 1;
    while(t--){
        printf("Case #%d:",kase++);
        int n;cin >> n;
        int tot = 0;
        for(int i=0;i<n;i++){
            cin >> a[i].cnt;
            a[i].pos = i;
            tot += a[i].cnt;
        }
        sort(a,a+n,cmp);
        int aa = 0;
        while(tot>0){
            if(++aa>5)break;
            sort(a,a+n,cmp);
            int ok = 0;
            int pos1 = 0,pos2 = 1;
            if(a[pos1].cnt>=2){
                tot -= 2;
                a[pos1].cnt -= 2;
                ok = 1;
                for(int i=0;i<26;i++){
                    if(!tot || a[i].cnt*2<=tot);
                    else ok = 0;
                }
                if(ok){
                    printf(" %c%c",'A'+a[pos1].pos,'A'+a[pos1].pos);
                }
                else tot += 2,a[pos1].cnt+=2;
            }
            if(ok)continue;
            else{
                if(a[pos1].cnt && a[pos2].cnt){
                    tot -= 2;
                    a[pos1].cnt -=1;
                    a[pos2].cnt -= 1;
                    ok =1;
                    for(int i=0;i<26;i++){
                        if(!tot || a[i].cnt*2<=tot);
                        else ok = 0;
                    }
                    if(ok){
                        printf(" %c%c",'A'+a[pos1].pos,'A'+a[pos2].pos);
                    }
                    else tot+=2,a[pos1].cnt+=1,a[pos2].cnt+=1;
                }
                if(!ok){
                    if(a[pos1].cnt){
                        tot -= 1;
                        a[pos1].cnt -= 1;
                        printf(" %c",'A'+a[pos1].pos);
                    }
                }
            }
        }
        printf("\n");
    }
	return 0;
}