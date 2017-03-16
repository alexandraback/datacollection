#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

using namespace std;

int main(){
    freopen("A.in","r",stdin);
    freopen("output.txt","w",stdout);
    int TC;
    cin>>TC;
    for(int ZZ=1;ZZ<=TC;ZZ++){
        int b,n;
        cin>>b>>n;
        int ar[b];
        for(int i=0;i<b;i++){
            cin>>ar[i];
        }
        long long low = 0;
        long long high = pow(10,15);
        long long key ;
        while(low<=high){
            key = (high+low)/2;
            long long x = 0;
            for(int i=0;i<b;i++){
                x+=(key/ar[i]) + 1;
            }
            /*
            if(x == n - 1){
                low = key;
                break;
            }*/
            if(x<n){
                low = key+1;
            }
            else if(x>=n){
                high = key-1;
            }
        }
        key -= 2;
        long long key1;
        while(true){
            key1 = key+1;
            long long x = 0;
            for(int i=0;i<b;i++){
                x+=(key1/ar[i]) + 1;
            }
            if(x >= n){
                break;
            }
            key++;
        }
        long long xy[b];
        long long sum = 0;
        for(int i=0;i<b;i++){
            xy[i] = (key/ar[i]) + 1;
            sum+=xy[i];
        }
        int ans;
        for(int i=0;i<b;i++){
            long long x = (key1/ar[i]) + 1;
            if(x>xy[i])
            {
                sum-=xy[i];
                sum+=x;
            }
            if(sum == n){
                ans = i+1;
                break;
            }
        }
        cout<<"Case #"<<ZZ<<": "<<ans<<endl;
    }
    return 0;
}
