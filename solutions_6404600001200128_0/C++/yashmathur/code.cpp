#include<iostream>

using namespace std;

int main(){
    int t, n;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;++i)
            cin>>arr[i];
        
        int a=0,b=0,m=0;
        
        for(int i=1;i<n;++i){
            if(arr[i]-arr[i-1]<0)
                a+=(arr[i-1]-arr[i]);

            m = max(m, arr[i-1]-arr[i]);
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]>=m)
                b+=m;
            else 
                b+=arr[i];
        }
        cout<<"Case #"<<tt<<": "<<a<<" "<<b<<endl;
    }
    return 0;
}