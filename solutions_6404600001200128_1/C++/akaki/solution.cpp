#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int i,j,k,l,m,n, ans, cur , test,s,t, mx, a[1005],d, ii,x,r,c;
string str;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for (i=0;i<n;i++)
            cin>>a[i];
        int ans1 = 0, ans2 = 0,mx = 0;
        for (i=1;i<n;i++){
            if (a[i]<a[i-1]){
                ans1+=a[i-1]-a[i];
                if (mx<a[i-1]-a[i])
                    mx=a[i-1]-a[i];
            }
        }
        int cur = 0;
        for (i=0;i<n-1;i++){
            cur=a[i];
            if (cur>=mx) {ans2+=mx;cur-=mx;} else
            {ans2+=cur;cur=0;}    
        }
        test++;
        cout<<"Case #"<<test<<": "<<ans1<<" "<<ans2<<"\n";
    } 
    return 0;
}
