#include <cstdio>
#include <algorithm>

using namespace std;

int tc;
int n;
int vals[1005];

int main()
{
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    scanf("%d",&tc);
    for (int it=1; it<=tc; it++)
    {
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            scanf("%d",&vals[i]);
        int rt1,rt2,mdif;
        rt1=0;
        mdif=0;
        for (int i=1; i<n; i++)
        {
            if (vals[i]>=vals[i+1])
            {
                rt1+=vals[i]-vals[i+1];
                mdif=max(mdif,vals[i]-vals[i+1]);
            }
        }
        rt2=0;
        for (int i=1; i<n; i++)
            rt2+=min(vals[i],mdif);
        printf("Case #%d: %d %d\n",it,rt1,rt2);

    }

}
