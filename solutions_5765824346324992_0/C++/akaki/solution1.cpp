#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

long long i,j,k,l[1005],m[1005],n, ans, cur , test,t, mx, a,d, ii,x,r,c,b;
string str;
int gcd (int a, int b){
    if (b==0) return a; else
    return gcd(b, a%b);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w", stdout);
    cin>>t;
    while(t--){
        cin>>b>>n;
        memset(l, 0, sizeof(l));
        for (i=0;i<b;i++){
            cin>>m[i];
        }
        int usj = m[0];
        for (i=1;i<b;i++){
            usj = usj*m[i] / gcd(usj,m[i]);
        }
        test++;
        int mod = 0;
        for (i=0;i<b;i++){
            mod+=usj/m[i];
        }
        n=n%mod;
        if (n==0){n=mod;}
        //cout<<mod<<"\n";
        for (i=0;i<n;i++){
            int mn = 1000000000;
            for (j=0;j<b;j++){
                if (mn>l[j]) {mn=l[j];cur=j;}
            }
            l[cur]+=m[cur];
        }
        cout<<"Case #"<<test<<": "<<cur+1<<"\n";
        
    } 
    return 0;
}
