#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#define maxn 100010
#define ll long long
using namespace std;
vector<int> vec;
int a[maxn];
int solve(int n,ll m,ll limit){
    ll mi=0,ma=limit,mid;
    while(mi<=ma){
        vec.clear();
        mid=(mi+ma)>>1;
        int num=0;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            if(mid%a[i]==0)
            {
                vec.push_back(i);
                num++;
            }
            sum+=(mid/a[i])+1;
        }
        if(sum>=m)
        {
            if(sum-num<m){
                //printf("%I64d %I64d %I64d\n",mid,sum,m);
                return vec[m+num-sum-1];
            }
            else
            ma=mid-1;
        }
        else
        mi=mid+1;
    }
}
int main(){
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        int n;
        ll m;
        scanf("%d%I64d",&n,&m);
        int Ma=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            Ma=max(Ma,a[i]);
        }
        printf("%d\n",solve(n,m,Ma*m));
    }
    return 0;
}
