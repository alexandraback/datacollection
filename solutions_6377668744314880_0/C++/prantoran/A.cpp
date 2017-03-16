#include<bits/stdc++.h>
#define ll long long
#define sz 1111
using namespace std;

ll gcd(ll a,ll b){
    if(!a)return b;
    return gcd(b%a,a);
}


struct item{
    ll id,time;
    bool operator<( const item& aa ) const {
        if(time == aa.time ) {
            return id > aa.id;
        }
        return time > aa.time;
    }
}tmp;

ll t,n,ans[sz],potv,netv,online;
ll xx[sz],yy[sz],dy,dx,mx,mn;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("C-small-attempt0.in","r",stdin);
    #endif // ONLINE_JUDGE
    ofstream fout ("output.txt");

    cin>>t;
    //cout<<"t:"<<t<<endl;
    for( ll ca = 1; ca <= t; ca++ ) {


        cin>>n;
        for( ll i = 0;i<n;i++) {

            ans[i]=n;
            cin>>xx[i]>>yy[i];
        }

        for(ll i = 0;i <n;i++){
            //cout<<"i:"<<i<<endl;
            for(ll j=i+1;j<n;j++){
                potv=0;
                netv=0;
                online=0;
                dy=yy[j]-yy[i];
                dx=xx[j]-xx[i];

                for(ll k = 0;k<n;k++){
                    if(k==i || k==j)continue;
                    ll dify=yy[k]-yy[i];
                    ll difx=xx[k]-xx[i];
                    ll factor=dify*dx-dy*difx;
                    //cout<<"\t\t\tfactor:"<<factor<<"\tk:"<<k<<"\tdify:"<<dify<<"\tdifx:"<<difx<<endl;
                    if(factor>0){
                        potv++;
                    }
                    else if(factor<0){
                        //cout<<"entered\n";
                        netv++;
                    }
                    else{
                        online++;
                    }
                }
                mn=min(potv,netv);
                mx=max(potv,netv);
                //cout<<"\t\tdx:"<<dx<<"\tdy:"<<dy<<"\t\tmn:"<<mn<<"\tmx:"<<mx<<"\tpotv:"<<potv<<"\tnetv:"<<netv<<"\tonline:"<<online<<endl;


                ans[i]=min(ans[i],mn);
                ans[j]=min(ans[j],mn);
            }
        }


        fout<<"Case #"<<ca<<":\n";
        for(int i=0;i<n;i++){
            fout<<ans[i]<<"\n";
        }


    }

    return 0;
}
