#include <bits/stdc++.h>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N = 23333,MOD = 7+1e9;
P a[30];
int p[30];
bool cmp(P a, P b)
{
    return a.SD > b.SD;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while(T --)
    {
        int n, sum = 0;
        scanf("%d", &n);
        for(int i = 0;i < n;i ++) scanf("%d", &p[i]);
        for(int i = 0;i < n;i ++)
        {
            a[i] = MP(i, p[i]);
            sum += p[i];
        }
        printf("Case #%d:", ++ca);
        while(1)
        {
            sort(a, a + n, cmp);
            if(a[0].SD == 0) break;
            int _max = max(a[0].SD - 1, a[1].SD);
            if(_max <= (sum-1)/2)
            {
                printf(" %c", a[0].FT + 'A');
                a[0].SD --, sum --;
                continue;
            }
            _max = max(a[0].SD - 2, a[1].SD);
            if(_max <= (sum-2)/2)
            {
                printf(" %c%c", a[0].FT + 'A', a[0].FT + 'A');
                a[0].SD -= 2, sum -= 2;
                continue;
            }
            _max = max(max(a[0].SD - 1, a[1].SD - 1), a[2].SD);
            if(_max <= (sum-2)/2)
            {
                printf(" %c%c", a[0].FT + 'A', a[1].FT + 'A');
                a[0].SD --, a[1].SD --, sum -= 2;
                continue;
            }
        }
        printf("\n");
    }
    return 0;
}