#include <bits/stdc++.h>
using namespace std;

long long times[1001],B,N;

long long test(long long t)
{
    long long sum = 0;
    for (int i=0;i<B;i++)
    {
        sum += (t+times[i]-1)/times[i];
    }
    return sum;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin >> T;
    for (int qq=1;qq<=T;qq++)
    {

        cin >> B >> N;
        for (int i=0;i<B;i++)
        {
            cin >> times[i];
        }
        long long lo = 0,hi = 10000000000000000;
        bool f = false;

        while (!f)
        {

            long long avg = (lo+hi)/2;

            long long tst = test(avg);
            if (tst>=N)
            {
                hi = avg-1;
            }
            else
            {
                for (int i=0;i<B;i++)
                {
                    if (avg % times[i]==0) tst++;
                    if (tst==N)
                    {
                        printf("Case #%d: %d\n",qq,i+1);
                        f = true;
                        break;
                    }
                }
                lo = avg+1;
            }
        }
    }
}
