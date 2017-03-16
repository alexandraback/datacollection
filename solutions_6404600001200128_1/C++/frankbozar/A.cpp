#include<cstdio>

int method1(const int *a, int n)
{
    int ans=0;
    
    for(int i=1; i<n; i++)
        if( a[i-1]>a[i] )
            ans+=a[i-1]-a[i];
    
    return ans;
}

int max(const int a, const int b)
{
    return a>b ? a : b ;
}

int min(const int a, const int b)
{
    return a<b ? a : b ;
}

int method2(const int *a, int n)
{
    int min_rate=0;
    
    for(int i=1; i<n; i++)
        if( a[i-1]>a[i] )
            min_rate=max(min_rate, a[i-1]-a[i]);
    
    int ans=0;
    
    for(int i=0; i<n-1; i++)
        ans+=min(min_rate, a[i]);
    
    return ans;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int cases=1; cases<=N; cases++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        
        printf("Case #%d: %d %d\n", cases, method1(a, n), method2(a, n));
    }
}