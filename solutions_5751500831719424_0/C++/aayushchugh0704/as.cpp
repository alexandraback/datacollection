#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>

typedef long long int ll;
typedef long double ld;
#define SLL(x) scanf("%lld",&(x))
#define REP(i,n) for(i=0;i<(n);i++)
#define SI(x) scanf("%d",&(x))
using namespace std;
void pans(int n, string s){
  cout<<"Case #"<<n<<": "<<s<<endl;// %d: %d
}
void pans(int n, int s){
  cout<<"Case #"<<n<<": "<<s<<endl;// %d: %d
}
char a[110],b[110];
int main(){
  int i,j,k,n,t;
  cin>>t;
  int ti;
  REP(ti,t){
    cin>>n;
    cin>>a;cin>>b;
    char a_[110],b_[110];
    int la=strlen(a);
    int lb=strlen(b);
    int ai=0;
    int acn[110],bcn[110];
    for(i=0;i<110;i++)acn[i]=bcn[i]=1;
    for(i=0;i<la;i++){
      if(i==0)a_[ai++]=a[i];
      else if(a[i]!=a[i-1])a_[ai++]=a[i];
      else acn[ai-1]++;
    }
    int bi=0;
    for(i=0;i<lb;i++){
      if(i==0)b_[bi++]=b[i];
      else if(b[i]!=b[i-1])b_[bi++]=b[i];
      else bcn[bi-1]++;
    }
    a_[ai]=0;b_[bi]=0;
    //cerr<<a_<<' '<<b_;
    if(strcmp(a_,b_)!=0){
      pans(ti+1,"Fegla Won");
    }else{
      int ans=0;
      for(i=0;i<110;i++){
	ans+=abs(acn[i]-bcn[i]);
      }
      pans(ti+1,ans);
    }
  }
  
  return 0;
}
