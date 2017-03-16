#include<bits/stdc++.h>
typedef long long int uli;
using namespace std;

const int mx=1000+10;
int m[mx];

int main(){
    freopen("bl1.in","r",stdin);
    freopen("bl1.out","w",stdout);
    int t,b;
    uli n;
    cin>>t;

    for(int tt=1;tt<=t;tt++){
        scanf("%d %lld",&b,&n);
        for(int i=0;i<b;i++)scanf("%d",m+i);
        uli li=0,ls=1e15,mid,ans=-1,nat=0;

        while(li<=ls){
            mid=(li+ls)>>1;
            uli q=0;
            for(int i=0;i<b;i++){
                q+=1ll+uli(mid/m[i]);
            }
            if(q<n){
                li=mid+1;
            }
            else{
                ls=mid-1;
                ans=mid;
                nat=q;
            }
        }
        int resp=-1;
        int idx=0;
        for(int i=b-1;i>=0;i--){
            if(ans%m[i]==0){
                if(idx==nat-n){
                    resp=i+1;
                    break;
                }
                idx++;
            }
        }
        printf("Case #%d: %d\n",tt,resp);
    }
    return 0;
;}
