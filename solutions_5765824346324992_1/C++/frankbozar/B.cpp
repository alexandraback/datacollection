#include<cstdio>
typedef long long lld;

bool check(const int *a, const int m, const lld n, const lld t)
{
    lld cnt=0;
    
    for(int i=0; i<m; i++)
        cnt+=t/a[i]+1;
    
    return cnt>=n;
}

int solve(const int *a, const int m, const lld n)
{
    lld t;
    
    for(lld l=0, r=120000000000000; l<=r; )
    {
        t=(l+r)>>1;
        
        if( check(a, m, n, t) )
        {
            if( r==t )
                break;
            
            r=t;
        }
        else
        {
            l=t+1;
        }
    }
    
    lld cnt=0;
    
    for(int i=0; i<m; i++)
        cnt+=t/a[i]+(t%a[i]!=0);
    
    for(int i=0; i<m; i++)
    {
        if( t%a[i]==0 )
            cnt++;
        
        if( cnt==n )
            return i+1;
    }
    
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int cases=1; cases<=N; cases++)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        int a[m];
        
        for(int i=0; i<m; i++)
            scanf("%d", &a[i]);
        
        printf("Case #%d: %d\n", cases, solve(a, m, n));
    }
}