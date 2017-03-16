#include<cstdio>
#include<vector>
using namespace std;
typedef long long lld;

inline int min(const int a, const int b)
{
    return a<b ? a : b ;
}

struct point
{
     lld x, y;
};

struct line
{
    lld a, b, c;
    
    line(const point& P, const point& Q)
    {
        a=P.y-Q.y;
        b=Q.x-P.x;
        c=-a*P.x-b*P.y;
        
        if( a*P.x+b*P.y+c || a*Q.x+b*Q.y+c )
            printf("ERR");
    }
    
    int operator()(const point& P) const
    {
        lld val=a*P.x+b*P.y+c;
        
        if( val==0 )
            return 0;
        
        return val<0 ? 1 : 2 ;
    }
};

void solve(const vector<point>& a, const int n)
{
    vector<int> ans(n, n-1);
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            line L(a[i], a[j]);
            int cnt[3]={0};
            
            for(int k=0; k<n; k++)
                cnt[ L(a[k]) ]++;
            
            int m=min(cnt[1], cnt[2]);
            ans[i]=min(ans[i], m);
            ans[j]=min(ans[j], m);
        }
        
        printf("%d\n", ans[i]);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int cases=1; cases<=N; cases++)
    {
        int n;
        scanf("%d", &n);
        vector<point> a(n);
        
        for(int i=0; i<n; i++)
            scanf("%lld%lld", &a[i].x, &a[i].y);
        
        printf("Case #%d:\n", cases);
        solve(a, n);
    }
}