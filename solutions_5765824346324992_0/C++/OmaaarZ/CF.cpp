#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define LL long long
using namespace std;

long long gcd(long long x , long long y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
long long lcm(long long x , long long y)
{

    return x /gcd(x,y) * y;
}
long long b[1010],temp[1010];
int main()
{
 freopen("B-small-attempt0.in","r",stdin);freopen("output.in","w",stdout);
    ios_base::sync_with_stdio(0);
    int t ;
    cin >> t;
    for(int i = 0 ;i  <t;i++)
    {
        int n;
        int m;
        cin >>m;
        cin >> n;
        long long lc =1;
        for(int i = 0 ;i  <m;i++)
        {
            cin >> b[i];
            lc = lcm(lc,b[i]);
        }
        long long sum=0;
        for(int i = 0 ;i <m;i++)
        {
            sum+= lc/b[i];
            temp[i]=b[i];
        }
        n--;
         n = n%sum;
        int ans ;
        if(n<m)
            ans = n+1;

        else
        {
            n-=m;

            while(true)
            {
                int mi =INT_MAX;
                for(int j=0;j<m;j++)
                {
                    mi = min((long long)mi,temp[j]);
                }
                for(int j=0;j<m;j++)
                {
                    temp[j]-=mi;
                }
                int counter=0;
                for(int j=0;j<m;j++)
                {
                    if(temp[j]==0)
                        counter++;
                }
                if(n<counter)
                {
                    int c1=0;
                    for(int j=0;j<m;j++)
                    {
                        if(temp[j]==0)
                        {
                            if(c1 ==n)
                                ans = j+1;
                            c1++;
                        }
                    }
                    break;
                }
                else
                {
                    for(int j = 0 ; j < m;j++)
                        if(temp[j]==0)
                            temp[j]=b[j];
                    n-=counter;
                }
            }
        }
        cout <<"Case "<< "#"<<i+1<<": " <<ans<<endl;


    }
    return 0;
}


