#include<bits/stdc++.h>
int z=1;
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int aa=0,bb=0,maxi=0;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<0){
                aa+=(a[i-1]-a[i]);
            }
            maxi=max(maxi,a[i-1]-a[i]);
        }
        for(int i=0;i<n-1;i++){
            if(a[i]>=maxi)bb+=maxi;
            else bb+=a[i];
        }
        cout<<"Case #"<<z<<": "<<aa<<" "<<bb<<"\n";
        z++;
    }
    return 0;
}
