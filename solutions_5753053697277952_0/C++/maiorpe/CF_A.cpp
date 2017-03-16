//Шаблон

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <utility>

#define ll long long
#define MAXN 200100

using namespace std;

struct point
{
    ll t;
    ll r;
    ll c;
    ll x;
    point(ll a=0, ll b=0,ll cc=0,ll d=0){
        t=a;
        r=b;
        c=cc;
        x=d;
    }
};

double sqr(double a){return a*a;}

//int d[300][300];

int d[100];

int main()
{   
    ll n,ans=0,t;
    cin>>t;
    d[50]=-1;
    for(int tt=0;tt<t;tt++){
        cin>>n;
        ll s=0;
        for(int i=0;i<n;i++){
            cin>>d[i];
            s+=d[i];
        }
        cout<<"Case #"<<tt+1<<": ";
        while(s>0){
            int max1=50,max2=50,max3=50;
            for(int i=0;i<n;i++){
                if(d[i]>d[max1]){
                    max3=max2;
                    max2=max1;
                    max1=i;
                }else if(d[i]>d[max2]){
                    max3=max2;
                    max2=i;
                }else if(d[i]>d[max3]){
                    max3=i;
                }
            }
            if((d[max1]==d[max2])&&(d[max2]!=d[max3])){
                d[max1]--;
                d[max2]--;
                cout<<(char)('A'+max1)<<(char)('A'+max2)<<' ';
                s-=2;
            }else{
                d[max1]--;
                cout<<(char)('A'+max1)<<' ';
                s--;
            }
        }
        cout<<endl;   
    }
    //cout<<fixed<<setprecision(16)<<ans<<endl;
    return 0;
}













    