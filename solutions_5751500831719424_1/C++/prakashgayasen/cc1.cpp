#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long int int64;
int64 f[1000001];
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int64 i,j,k,n,m,t,ans,cnt=1,vl,fl,cn,mn,mx,mvl;
  char pr;
  string tp,tp1;
  cin>>t;
  while(t--){
    fl=1;ans=0;
    scanf("%lld",&n);
    vector <string> v(n);
    vector <vector <int64> > l(n,vector <int64>());
    for(i=0;i<n;i++)cin>>v[i];
    pr = '-';tp="";
    for(j=0;j<v[0].length();j++){
      if(v[0][j]==pr)continue;
      else {tp+=v[0][j];pr=v[0][j];}
    }
    tp1=tp;

    for(i=0;i<n;i++){
      pr = '-';tp="";
      for(j=0;j<v[i].length();j++){
        if(v[i][j]==pr)continue;
        else {tp+=v[i][j];pr=v[i][j];}
      } 
    if(tp!=tp1){fl=0;break;}
    }
    if(fl==0){printf("Case #%lld: Fegla Won\n",cnt);cnt++;continue;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////


    for(i=0;i<n;i++){
      pr = v[i][0];cn=0;
      for(j=0;j<v[i].length();j++){
        if(v[i][j]==pr)cn++;
        else {l[i].push_back(cn);cn=1;pr=v[i][j];}
      }
      l[i].push_back(cn);
    }
    //for(i=0;i<n;i++){for(j=0;j<l[i].size();j++)cout<<l[i][j]<<" ";cout<<endl; }
      
    for(j=0;j<l[0].size();j++){
      mn = 10000;mx=-1;
      for(i=0;i<n;i++){
        if(l[i][j]<mn)mn=l[i][j];
        if(l[i][j]>mx)mx=l[i][j];
      }
      mvl = 10000;
      for(k=mn;k<=mx;k++){
        vl=0;
        for(i=0;i<n;i++)vl+=abs(l[i][j]-k);
        if(vl<mvl)mvl=vl;
        //cout<<vl<<" ";
      }
      //cout<<mvl<<endl;
      ans+=mvl;
    }
    printf("Case #%lld: %lld\n",cnt,ans);
    cnt++;

  }
  return 0;
}

