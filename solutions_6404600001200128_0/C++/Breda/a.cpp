#include <stdio.h>
#include <stdlib.h>
#include <utility>

using namespace std;

pair<int, int> res()
{
    int n, t1, t2, i, v, a, tx, mtx=-1, ve[2000];
    t1 = 0;
    t2 = 0;
    scanf("%d", &n);
    scanf("%d", &a);
    ve[0] = a;
    for(i=1;i<n;i++)
    {
        scanf("%d", &v);
        ve[i] = v;
        if(v<a)
        {
            t1+=(a-v);
            tx = (a-v);
            //printf("TX: %d\n", tx);
            if(mtx==-1 || tx>mtx)
                mtx = tx;
        }
        a = v;
    }
    //printf("MTX: %d\n", mtx);
    for(i=0;i<n-1;i++)
    {
        if(ve[i]<mtx)
            t2+=ve[i];
        else if(mtx!=-1)
            t2+=mtx;
    }
    return make_pair(t1, t2);
}

int main()
{
    int t, i;
    pair<int, int> r;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        r = res();
        printf("Case #%d: %d %d\n", i, r.first, r.second);
    }
    return 0;
}
