#include<bits/stdc++.h>
using namespace std;
int m[1005];
int solve1(int n){
    int ans=0;
    for(int i=0; i<n-1; i++){
        if(m[i]>m[i+1]){
            ans+=m[i]-m[i+1];
        }
    }
    return ans;
}
int solve2(int n){
    int ans=0, maxx=0;
    for(int i=0; i<n-1; i++){
        if(m[i]>m[i+1]) maxx=max(maxx,m[i]-m[i+1]);
    }
    for(int i=0; i<n-1; i++){
        ans+=min(m[i],maxx);
    }
    return ans;
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t; cin>>t;
    for(int cs=1; cs<=t; cs++){
        int n; cin>>n;
        for(int i=0; i<n; i++){
            scanf("%d",&m[i]);
        }
        printf("Case #%d: %d %d\n",cs,solve1(n),solve2(n));
    }
    return 0;
}
