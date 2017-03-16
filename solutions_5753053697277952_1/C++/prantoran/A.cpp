
#include<bits/stdc++.h>
using namespace std;

int n,t,p[111111],sum,idx,mxm,mxi;

string ans[111111];


int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%d",&n);
        sum=0;
        for(int i = 0 ; i < n ;i ++ ) {
            scanf("%d",&p[i]);
            sum+=p[i];
        }
        idx=-1;
        while(sum){
            idx++;
            ans[idx]="";
            mxm = 0;
            mxi=0;

            for(int i = 0 ; i < n;i++){
                if(p[i]>mxm){
                    mxm=p[i];
                    mxi=i;
                }
            }
            p[mxi]--;
            sum--;
            ans[idx]+=(char)(mxi+'A');
            if(sum==0)break;

            mxm = 0;
            mxi=0;

            for(int i = 0 ; i < n;i++){
                if(p[i]>mxm){
                    mxm=p[i];
                    mxi=i;
                }
            }
            p[mxi]--;
            sum--;

            int mmxi=0;
            int mmxm=0;

            for(int i = 0 ;  i< n;i++){
                if(p[i]>mmxm){
                    mmxm=p[i];
                    mmxi=i;
                }
            }
            //cout<<"mmxm:"<<mmxm<<"\tsum:"<<sum<<endl;
            if(mmxm*2>sum){
                sum++;
                p[mxi]++;
            }
            else{
                ans[idx]+=(char)(mxi+'A');
            }



        }

        printf("Case #%d: ",ca);
        for(int i = 0 ; i<=idx;i++){
            if(i)cout<<" ";
            cout<<ans[i];
        }cout<<"\n";



    }



}
