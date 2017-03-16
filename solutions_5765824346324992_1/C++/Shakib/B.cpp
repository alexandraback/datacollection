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

vector< pii > v;

vector<lld> res;
vector<lld> rem;

int b,n;

lld bs()
{
    lld l=0,r=1e9;
    int ans=-1;
    int i,j;
    int car=-1;
    while(l<=r)
    {
        lld mid=(l+r)/2;
        lld sum=0;
        for(i=0;i<b;i++)
        {
            sum+=(mid*res[i]);
            sum+=((mid*rem[i])/v[i].X);
            if((mid*rem[i])%v[i].X)
            {
                //has sit for
                sum++;
            }
        }
        if(sum<n)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}

int main()
{
    FRO
    FROut
    int t,ca;
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        v.clear();
        res.clear();
        rem.clear();
        scanf("%d %d",&b,&n);
        int i;
        for(i=0;i<b;i++)
        {
            int x;
            scanf("%d",&x);
            v.PB(MP(x,i));
        }
        int ans;
        if(n<=b)
        {
            ans=n;
        }
        else
        {
            sort(v.begin(),v.end());
            for(i=0;i<b;i++)
            {
                res.PB(v[b-1].X/v[i].X);
                rem.PB(v[b-1].X%v[i].X);
            }
            lld round=bs();
            assert(round!=-1);
            {
                int l,r;
                l=0,r=v[b-1].X;
                lld sum;
                lld vs=0;
                int mint;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    sum=0;
                    for(i=0;i<b;i++)
                    {
                        sum+=(round*res[i]);
                        sum+=((round*rem[i]+mid))/v[i].X;
                        if((round*rem[i]+mid)%v[i].X)
                        {
                            //has sit for
                            sum++;
                        }
                    }
                    if(sum<n)
                    {
                        mint=mid;
                        vs=sum;
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
                lld indx=n-vs;
                vector<int> prob;
                for(i=0;i<b;i++)
                {
                    if((round*rem[i]+mint)%v[i].X ==0)
                    {
                        prob.PB(v[i].Y);
                    }
                }
                sort(prob.begin(),prob.end());
                ans=prob[indx-1]+1;
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
