#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repf(i, a, b) for (long long i = (a); i <= (b); ++i)
#define repd(i, a, b) for (long long i = (a); i >= (b); --i)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const long long maxn=1010;
struct node{
    long long x,y;
}e[maxn],res[maxn],p[maxn];
long long cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
long long cross(node a,node b,node c)//向量积
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
long long convex(long long n)//求凸包上的点
{
    sort(e,e+n,cmp);
    long long m=0,i,k;
    //求得下凸包，逆时针
    //已知凸包点m个，如果新加入点为i，则向量(m-2,i)必定要在(m-2,m-1)的逆时针方向才符合凸包的性质
    //若不成立，则m-1点不在凸包上。
    for(i=0;i<n;i++)
    {
        while(m>1&&cross(res[m-1],e[i],res[m-2])<=0)m--;
        res[m++]=e[i];
    }
    k=m;
    //求得上凸包
    for(i=n-2;i>=0;i--)
    {
        while(m>k&&cross(res[m-1],e[i],res[m-2])<=0)m--;
        res[m++]=e[i];
    }
    if(n>1)m--;//起始点重复。
    return m;
}
bool cro( node x1 , node x2 , node y ) {
	long long s1=y.x-x1.x, t1=y.y-x1.y;        //Q-P1(s1,t1)
	long long s2=x1.x-x2.x,t2=x1.y-x2.y;       //P1-P2(s2,t2)
	return (s1*t2==t1*s2)?true:false ;
}
long long T , n ;
long long ret[10000] ;
int main() {
    freopen("C.out","w",stdout) ;
    scanf("%lld" , &T ) ;
    repf( t , 1  , T ) {
        memset(p,0,sizeof(p)) ;
        memset(e,0,sizeof(e)) ;
        scanf("%lld" , &n ) ;
        repf( i , 1 , n ) {
            scanf("%lld %lld" , &p[i].x , &p[i].y ) ;
            ret[i] = 10000 ;
        }
        if ( n == 1 ) {
            printf("Case #%lld:\n" , t ) ;
            puts("0") ;
            continue ;
        }
        rep( i , (1<<n) ) {
            long long top = 0 ;
            rep( j , n ) {
                if ( i & ( 1 << j ) ) {
                    e[top].x = p[j+1].x ;
                    e[top].y = p[j+1].y ;
                    top ++ ;
                }
            }
            if ( top != 0 ) {
                long long m = convex(top) ;
                repf( j , 1 , n ) {
                    repf( k , 1 , m - 1 )
                        if ( cro( res[k-1] , res[k] , p[j] ) ) 
                            ret[j] = min( ret[j] , n - top ) ;
                    if ( cro( res[0] , res[m-1] , p[j] ) )
                        ret[j] = min( ret[j] , n - top ) ;
                }
            }
        }
        printf("Case #%lld:\n" , t ) ;
        repf( i , 1 , n ) {
            printf("%lld\n" , ret[i] ) ;
        }
    }
    return 0;
}

