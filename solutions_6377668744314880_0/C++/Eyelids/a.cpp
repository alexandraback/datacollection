#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1010;
typedef long long LL; 
struct node{  
    LL x,y, id;  
}e[maxn],res[maxn], p[maxn];  
int n, m;
int ans[1010];

int cmp(node a,node b)  
{  
    if(a.x==b.x)return a.y<b.y;  
    return a.x<b.x;  
}  
LL cross(node a,node b,node c)//向量积  
{  
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);  
}  

int convex(int n)//求凸包上的点  
{  
    sort(e,e+n,cmp);  
    int i,j,k;  
    m = 0;
    //求得下凸包，逆时针  
    //已知凸包点m个，如果新加入点为i，则向量(m-2,i)必定要在(m-2,m-1)的逆时针方向才符合凸包的性质  
    //若不成立，则m-1点不在凸包上。  
    for(i=0;i<n;i++)  
    {  
        while(m>1&&cross(res[m-1],e[i],res[m-2])<0)m--;  
        res[m++]=e[i];  
    }  
    k=m;  
    //求得上凸包  
    for(i=n-2;i>=0;i--)  
    {  
        while(m>k&&cross(res[m-1],e[i],res[m-2])<0)m--;  
        res[m++]=e[i];  
    }  
    if(n>1)m--;//起始点重复。  

    return m;  
}  

int main() {
        freopen( "b.in", "r", stdin );
        freopen( "b.out", "w", stdout );

        int T;
        cin >>T;
        for ( int cas = 1; cas <= T; cas ++ ) {
                //scanf( "%d", &n );
                cin >>n;
                for ( int i = 0; i < n; i ++ ) {
                        //scanf( "%d%d", &p[i].x, &p[i].y );
                        cin >>p[i].x>>p[i].y;

                        p[i].id = i;
                        e[i] = p[i];
                }
                convex( n );

                for ( int i = 0; i < n; i ++ ) ans[i] = n;
                for ( int i = 0; i < (1 << n); i ++ ) {
                        int cnt = 0;
                        for ( int j = 0; j < n; j ++ ) if ( (i >> j) &1 ) {
                                e[cnt] = p[j];
                                cnt ++;
                        }
                        convex( cnt );
                        for ( int j = 0; j < m; j ++ ) {
                                ans[res[j].id] = min( ans[res[j].id], n - cnt );
                        }
                }


                printf( "Case #%d:\n", cas );
                for ( int i = 0; i < n; i ++ ) {
                        printf( "%d\n", ans[i] );
                }
        }

        return 0;
}




