#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long

int min(ll a, ll b){
    if(a<b){return a;}else{return b;}
}

void first(int n, int a[1000]){
     ll x=0;
     for(int i=1; i<n; i++){
             x+=max(0,a[i-1]-a[i]);
     }
     cout << x << " ";
}

void second(int n, int a[1000]){
     //find max of a[i-1]-a[i]
     ll v=0,x=0;
     for(int i=1; i<n; i++){
             if(a[i-1]-a[i]>v){v=a[i-1]-a[i];}
     }
     for(int i=0; i<n-1; i++){
             x+=min(v,a[i]);
     }
     cout << x << endl;
}

int asd(){
    int n, a[1000];
    cin >> n;
    for(int i=0; i<n; i++){
            cin >> a[i];
    }
    first(n,a); second(n,a);
}

int main(){
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.out","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
            cout << "Case #" << i << ": ";
            asd();
    }
    return 0;
}
