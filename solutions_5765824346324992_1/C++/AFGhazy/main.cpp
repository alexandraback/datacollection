#include <bits/stdc++.h>
using namespace std;

int A[1005], B, N;

long long check(long long time)
{

    long long ret = 0;

    for(int i = 0; i < B; i++)
    {

        ret += ((long long) time+A[i]-1)/A[i];

    }
    if(ret < N) return ret;


    return 0;

}

int main()
{

    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++)
    {


        scanf("%d", &B);


        scanf("%d", &N);

        for(int i = 0; i < B; i++)
        {

            cin >> A[i];


        }

        long long l = 0;
        long long h =100000000000000005;

        while(l+1<h)
        {
            double md = (l+h)>>1;
            if(check(md)) l = md;
            else h = md - 1;

        }

        long long ac = check(l);
        while(check(l+1)) ++l, ac = check(l);


        for(int i = 0; i < B; ++i)
        {

            if(l%A[i]==0)
            {

                ac++;

            }

            if(ac == N)
            {

                printf("Case #%d: %d\n", t, i+1);
                break;

            }

        }

    }


}
