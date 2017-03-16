#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int N=1010;
ll d[N];

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int T,B,n;
   cin >> T;
   for(int t=1;t<=T;t++){
        ll ans=0;
        cin >> B >> n;
        memset(d,0,sizeof(d));
        for(int i=0;i<B;i++){
            cin >> d[i];
        }
        if(B>=n){
            ans=n;
        }else{
            ll first=1,last=2e18;
            while(first<last){
                ll mid = (first+last)>>1;
                ll tn=0,tn1=0;
                for(int i=0;i<B;i++){
                    tn+=(mid-1)/d[i]+1;
                    if(mid%d[i]==0) tn1++;
                }
                if(tn>=n){
                    last =mid;
                }
                else{
                   if(n<=tn+tn1){
                     tn1=0;
                     for(int j=0;j<B;j++){
                       if(mid%d[j]==0 && tn+(++tn1)==n){ans=j+1;break;}
                     }
                     break;
                   }else{
                     first=mid;
                   }
                }
            }
        }
        printf("Case #%d: %ld\n",t,ans);
   }
    return 0;
}
