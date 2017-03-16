#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second
#define      pb(x)             push_back(x)


typedef long long LL;
LL MOD = 1000000007;
int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=0; tt<t; tt++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: ",tt+1 );
        std::vector<pii> v;
        for(int i=0; i<n; i++)
        {
            int c;
            scanf("%d",&c);
            v.pb(mp(c,i));
        }
        while(true)
        {
            sort(v.begin(), v.end(), greater<pii>());
            if(v[0].X == 0) break;
            assert(v[1].X > 0);
            if(v[0].X >= v[1].X + 1)
            {
                printf("%c ",'A'+v[0].Y);
                v[0].X -= 1;
            }
            else
            {
                if(n > 2 and v[2].X > 0)
                {
                    printf("%c ",'A'+v[0].Y);
                    v[0].X -= 1;
                }
                else
                {
                    printf("%c%c ",'A'+v[0].Y, 'A'+v[1].Y);
                    v[0].X -= 1;
                    v[1].X -= 1;
                }
            }

        }
        printf("\n");
    }
    return 0;
}
