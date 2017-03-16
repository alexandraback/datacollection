/*    brioso     */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include<set>
#include<map>
#include<queue>

using namespace std;
#define MAXN 1005
#define inf 0x3f3f3f3f
typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);

struct node{
    int x,id;
    bool operator < (const node a) const{
        return x < a.x;
    }
} a[MAXN];;
int b[MAXN];
int c[MAXN];
char s[MAXN];
int dp[MAXN];
bool vis[MAXN];
int n,m;
int ans;


int main()
{
    freopen("A-large (2).in","r",stdin);
    freopen("1.out","w",stdout);
    int t,ca = 1;
    int p,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        priority_queue<node> que;
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&a[i].x);
            a[i].id = i;
            que.push(a[i]);
        }
        printf("Case #%d:",ca++);
        while(!que.empty()){
            node x = que.top();que.pop();
            node y = que.top();que.pop();
            if(x.x+y.x == 2 && que.empty()){
                printf(" %c%c\n",x.id+'A',y.id+'A');
                break;
            }
            else if(x.x == y.x && que.empty()){
                printf(" %c%c",x.id+'A',y.id+'A');
                if(x.x > 1)
                    que.push(node{x.x-1,x.id});
                if(y.x > 1)
                    que.push(node{y.x-1,y.id});
            }
            else {
                printf(" %c",x.id+'A');
                que.push(y);
                if(x.x > 1)
                    que.push(node{x.x-1,x.id});
            }
        }

        //printf("%d\n",ans);
    }
    return 0;
}


/*

unsigned   int   0～4294967295
int   2147483648～2147483647
unsigned long 0～4294967295
long   2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：18446744073709551615

__int64的最大值：9223372036854775807
__int64的最小值：-9223372036854775808
unsigned __int64的最大值：18446744073709551615

*/
