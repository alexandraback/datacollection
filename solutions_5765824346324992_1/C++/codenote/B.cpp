#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 10000
ll M[N + 1];
ll Customers(int i,ll T,int n)
{
    ll sum = 0;
    for(int j = 1 ; j<=i ; j++)
    {
        sum = sum + (T/M[j])+1;
    }
    for(int j = i+1 ; j<=n ; j++)
    {
        sum = sum + ((T-1)/M[j])+1;
    }
    return sum;
}
int main()
{
    int tc,t;
    ll INF = pow(10,18);
    freopen("C:\\Users\\dell\\Downloads\\inputb.txt","r",stdin);
    freopen("C:\\Users\\dell\\Desktop\\temp\\CODING\\REPOSITORY\\GCJ\\2015\\Round 1A\\outputB.txt","w",stdout);
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++)
    {
        int ans = 0;
        int b,i,j;
        ll n,mn;
        scanf("%d %lld",&b,&n);
        for(i = 1 ; i<=b ; i++)scanf("%lld",&M[i]);
        mn = INF;

        for(i = 1 ; i<=b ; i++)
        {
            ll cand = INF;
            ll l = 0,h=n;

            while(l <= h)
            {
                //printf("%lld %lld ",l,h);
                ll mid = (l+h)/2;
                ll T = mid*M[i];
                ll cust = Customers(i,T,b);
                //printf("%lld %lld\n",T,cust);
                if(cust == n)
                {
                    cand = mid;
                    break;
                }
                if(cust < n) l = mid+1;
                else h = mid-1;
            }
            if(mn > cand)
            {
                ans = i;
                mn = cand;
            }
        }
        // Printing Starts here for the Test Case
        printf("Case #%d: ",t);
        // Print the result of the code here
        printf("%d",ans);
        //Don't do anything after this.
        printf("\n");
    }
    return 0;
}
