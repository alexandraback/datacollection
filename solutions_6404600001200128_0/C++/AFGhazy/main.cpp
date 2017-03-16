#include <bits/stdc++.h>
using namespace std;

int A[100005], n;

bool check(double rate)
{

    int B = A[0];

    for(int i = 1; i < n; ++i)
    {

        if((double)B - 10 * rate > A[i])
            return false;

        B = A[i];

    }
    return true;
}

int main()
{

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    //freopen("A-large-attempt.out", "w", stdout);
    //freopen("A-large-attempt.out", "w", stdout);

    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++)
    {

        cin >> n;

        int ans1 = 0;
        double ans2 = 0;

        for(int i = 0; i < n; i++)
        {

            cin >> A[i];


            if(i && A[i-1] - A[i]>0)
                ans1 += A[i-1] - A[i];


        }

        double l = 0, h =10005;
        int it = 0;

        while(it++<300)
        {

            double md = (l+h)/2;
            if(!check(md)) l = md;
            else h = md;

        }


        for(int i = 0; i < n-1; i++)
        {

            ans2 += min(10*l,(double)A[i]);

        }

        printf("Case #%d: %d %.0lf\n", t, ans1, ans2);

    }


}
