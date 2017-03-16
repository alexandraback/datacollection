#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

const int max_n = 1e6+6, inf =1e9;
int dist[max_n], n;

void solve(int casee)
{
    int ans = inf;
    int r, c, n;
    scanf("%d%d%d", &r, &c, &n);
    if( n<2) ans =0;

    int sum=r*c;
    for( int i=1; i< (1<<sum);++i )
    {
        if(__builtin_popcount(i)!=n)continue;
        int curr=0;
        for( int bit =0; bit<sum; ++bit)
            if(i &(1<<bit) )
            {
                if( (i&(1<<(bit+1) ) ) and (bit/c) == ((bit+1)/c) ) curr++;
                if( i&(1<<(bit+c)) ) curr++;
            }
        ans = min(ans, curr);
    }

    printf("Case #%d: %d\n", casee, ans);
}

int main()
{
   int testy;
   scanf("%d", &testy);
   for( int i=1; i<=testy; ++i)
        solve(i);
}
