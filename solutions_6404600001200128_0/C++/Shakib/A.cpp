//Bismillahir Rahmanir Rahmeem

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#include<set>
#include<iomanip>
#define INF 1e9
#define lld long long int
#define CLR(a) memset(a,0,sizeof(a))
#define RESET(a) memset(a,-1,sizeof(a))
#define act(a) memset(a,1,sizeof(a))
#define setinf(a) memset(a,0b01111111,sizeof(a));
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("output.txt","w",stdout);
#define ui unsigned int
#define came "came"
#define pii pair<int,int>
#define plii pair<long long int, int>
#define pll pair<long long,long long>
#define pic pair<int,char>
#define ninf (-1e9)-2
#define inf (1e9)+2
#include<fstream>
#include <assert.h>
#include <bitset>

#define foreach(x) for(__typeof(x.begin()) it=x.begin(); it!=x.end();it++)

using namespace std;
#define pid pair<int,double>
#define pdi pair<double,int>

#define PB push_back
#define MP make_pair
#define pri(x) printf("%d\n",x)
#define pi 3.14159265359
#define X first
#define Y second
#define vit vector<int>::iterator

int a[1005];

int main()
{
    FRO
    FROut
    int t;
    scanf("%d",&t);
    int ca;
    for(ca=1;ca<=t;ca++)
    {
        int n;
        scanf("%d",&n);
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int ans1,ans2;
        ans1=0;
        for(i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                ans1+=a[i-1]-a[i];
            }
        }
        int l,r;
        l=0,r=100000;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int sm=0;
            for(i=1;i<n;i++)
            {
                sm+=min(a[i-1],mid);
                if(a[i-1]-a[i]>mid)
                {
                    break;
                }
            }
            if(i==n)
            {
                // got an ans;
                ans2=sm;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("Case #%d: %d %d\n",ca,ans1,ans2);
    }
    return 0;
}
