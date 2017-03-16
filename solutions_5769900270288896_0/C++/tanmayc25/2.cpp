#include<bits/stdc++.h>
using namespace std;
int dp[1<<18];
void f1()
{
    int a,b,c;
}
int solve(int n, int r, int c)
{
    int res=0;
    for(int i=0;i<r;i++)
    {   
        for(int j=0;j<c;j++)
        {
            if(j>0 && (n&(1<<(i*c+j))) && (n&(1<<(i*c+j-1))))
                res++;
            if(i>0 && (n&(1<<(i*c+j))) && (n&(1<<(i*c+j-c))))
                res++;
            f1();
        }
    }
    return res;
}
int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t, r, c , n, temp;
    cin >> t;
    f1();
    for(int tt=1;tt<=t;tt++)
    {
        cin >> r >> c >> n;
        cout << "Case #" << tt << ": ";
        temp=r*c*n*100;
        f1();
        for(int i=1;i<(1<<(r*c));i++)
        {
            dp[i]=dp[i-(i&-i)]+1;
            if(dp[i]==n)
                temp=min(temp,solve(i,r,c));
            f1();
        }
        cout << temp << "\n";
    }
    return 0;
}
