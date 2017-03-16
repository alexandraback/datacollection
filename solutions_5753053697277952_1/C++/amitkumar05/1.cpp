#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<limits.h>
#include<deque>
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define sf(n) scanf("%f",&n)

#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n)
#define pf(n) printf("%f\n",n)

#define ll long long int
#define r0 return 0
#define INF INT_MAX
#define FR(i,a,b) for(i=a;i<b;i++)
#define decit int i,j,k
int M=1000000000+7;
using namespace std;

int main()
{
    int t,it;
    decit;
    si(t);
    FR(it,1,t+1)
    {
        ll ans=0;

        cout<<"Case #"<<it<<": ";
        int a,b,n;
        cin>>n;
        int arr[n+5];
        FR(i,0,n)
            cin>>arr[i];
        int flag=1;
        while(flag)
        {
            a=0;
            FR(i,0,n)
            {
                if(arr[i]>arr[a])
                    a=i;
            }
            b=(a+1)%26;
            FR(i,0,n)
            {
                if(i==a)
                    continue;
                if(arr[i]>arr[b])
                    b=i;
            }
            int count=0;
            FR(i,0,n)
            {
                if(arr[i]>0)
                    count++;
            }
            if(arr[a]==arr[b] && arr[a]!=1 && arr[b]!=1)
            {
                cout<<(char)(a+'A')<<(char)(b+'A')<<" ";
                arr[a]--;arr[b]--;
            }
            else if(count==2 && arr[a]==arr[b] )
            {
                cout<<(char)(a+'A')<<(char)(b+'A')<<" ";
                arr[a]--;arr[b]--;
            }
            else
            {
                cout<<(char)(a+'A')<<" ";
                arr[a]--;
            }
            flag=0;
            FR(i,0,n)
            {
                if(arr[i]>0)
                    flag=1;
            }
        }
        cout<<endl;
    }
    return 0;
}