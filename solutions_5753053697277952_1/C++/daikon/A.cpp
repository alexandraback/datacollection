#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> PLD;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(), (x).end()


int main()
{  
    int T;
    scanf("%d",&T);
    getchar();
    for(int ii = 1; ii<=T; ++ii)
    {
        int N;
        scanf("%d",&N);
        vector< PII > all;
        vector< char > ans;
        for(int i = 0; i<N; ++i)
        {
            int x;
            scanf("%d",&x);
            all.PB( MP(x,i) );
        }
        sort( ALL(all) );
        bool changed = true;
        while(changed)
        {
            changed = false;
            for(int i = N-1; i>=0; --i)
            {
                if( i>0 && all[i].F > all[i-1].F )
                {
                    ans.PB( (char)(all[i].S+65) );
                    ans.PB( ' ' );
                    --all[i].F;
                    changed = true;
                }
            }
        }
        if( all[0].F > 1 )
        {
            if( N%2 == 0 )
            {
                while( all[0].F > 1 )
                {
                    for(int i = 0; i<N; i+=2)
                    {
                        ans.PB( (char)(all[i].S+65));
                        ans.PB( (char)(all[i+1].S+65));
                        ans.PB( ' ');
                    }
                    --all[0].F;
                }
            }
            else
            {
                while( all[0].F > 1 )
                {
                    ans.PB( (char)(all[0].S+65) );
                    ans.PB( ' ' );
                    for(int i = 1 ;i<N; i+=2)
                    {
                        ans.PB( (char)all[i].S+65 );
                        ans.PB( (char)all[i+1].S+65 );
                        ans.PB( ' ' );
                    }
                    --all[0].F;
                }
            }
        }
        if( N%2 == 0 )
        {
            for(int i = 0; i<N; i+=2)
            {
                ans.PB( (char)(all[i].S+65));
                ans.PB( (char)(all[i+1].S+65));
                ans.PB( ' ');
            }
        }
        else
        {
            ans.PB( (char)(all[0].S+65) );
            ans.PB( ' ');
            for(int i = 1 ;i<N; i+=2)
            {
                ans.PB( (char)all[i].S+65 );
                ans.PB( (char)all[i+1].S+65 );
                ans.PB( ' ');
            }
        }
        printf("Case #%d: ",ii);
        for(int j = 0,n = ans.size(); j<n-1; ++j)
        {
            printf("%c",ans[j]);
        }
        printf("\n");
    }
}

