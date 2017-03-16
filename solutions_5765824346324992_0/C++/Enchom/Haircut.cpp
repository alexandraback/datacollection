#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long Int;

int B;
Int M[1011];
Int N;
int Answer;
Int left_to_win;

vector<int> Help;

void Get(Int k)
{
    int i;

    Help.clear();

    for (i=1;i<=B;i++)
    {
        if ( k%M[i]==0 )
        Help.push_back(i);
    }

    sort(Help.begin(),Help.end());

    Answer=Help[ left_to_win-1 ];

    return;
}

Int Solve(Int k)
{
    int i;
    Int ans=0;

    for (i=1;i<=B;i++)
    {
        ans+=(k-1)/M[i]+1;
    }

    return ans;
}

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-output.txt","w",stdout);

    int t,test;
    int i;
    Int l,r,mid,best;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %lld",&B,&N);

        for (i=1;i<=B;i++)
        {
            scanf("%lld",&M[i]);
        }

        best=0;
        l=1;
        r=100000000000000000LL;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (Solve(mid)<N)
            {
                best=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        left_to_win=N-Solve(best);

        Get(best);

        printf("Case #%d: %d\n",test,Answer);
    }

    return 0;
}
