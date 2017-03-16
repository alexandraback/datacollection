#include<bits/stdc++.h>
#define ll long long
#define sz 1111
using namespace std;

ll t,n,a[sz],ans1,ans2,mxm;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("A-large.in","r",stdin);
    #endif // ONLINE_JUDGE
    ofstream fout ("output.txt");

    cin>>t;
    //cout<<"t:"<<t<<endl;
    for( ll ca = 1; ca <= t; ca++ ) {
        cin>>n;
        for( ll i = 0; i < n; i++ ) {
            cin>>a[i];
        }
        ans1=0;
        ans2=0;
        mxm=0;
        for( ll i = 0; i <n-1;i++){
            if(a[i]-a[i+1] > 0 ){
                ans1+=(a[i]-a[i+1]);
                mxm=max(mxm,a[i]-a[i+1]);
            }
        }
        for( ll i = 0; i <n-1;i++){
            ans2+=min(mxm,a[i]);
        }
        fout<<"Case #"<<ca<<": "<<ans1<<" "<<ans2<<"\n";


    }

    return 0;
}
