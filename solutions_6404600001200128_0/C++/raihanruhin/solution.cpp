///     Raihan Ruhin
///     CSE, Jahangirnagar University.
///     Dhaka-Bangladesh.
///     id: raihanruhin (topcoder / codeforces / codechef / hackerrank / uva / uvalive / spoj), 3235 (lightoj)
///     mail: raihanruhin@ (yahoo / gmail / facebook)
///     blog: ruhinraihan.blogspot.com

#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 100010

#define READ freopen("A-small-attempt0.in", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)

int main()
{
    READ;
    WRITE;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc,kk=1, n, arr[1010];

    cin>>tc;
    while(tc--)
    {
        cin>>n;
        int ans1=0, ans2=0;
        int maxRatio=0;
        cin>>arr[0];
        for(int i=1; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]<arr[i-1])
            {
                ans1+=(arr[i-1]-arr[i]);
                /*double tmp = (double) (arr[i-1] - arr[i]) / 10.0;
                int tmp2 = ceil(tmp*10.0);*/
                int tmp2=arr[i-1]-arr[i];

                maxRatio = max(maxRatio, tmp2);
            }
        }
        //cout<<maxRatio<<endl;
        for(int i=1; i<n; i++)
        {
            if(arr[i]>arr[i-1])
                ans2+=min(arr[i-1], maxRatio);
            else
                ans2+=min(arr[i-1], maxRatio);
        }

        cout<<"Case #"<<kk++<<": "<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}

