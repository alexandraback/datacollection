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
int cns[110][110];
char a[110];
int main(){
  int i,j,k,n,t;
  cin>>t;
  int ti;
  char b[110];
  REP(ti,t){
    REP(i,110)REP(j,110)cns[i][j]=1;
    cin>>n;
    cin>>a;
    char *s[n];
    REP(i,n)s[i]=new char[110];
    strcpy(s[0],a);
    char a_[110];
    int la=strlen(a);
    int ai=0;
    for(i=0;i<la;i++){
      if(i==0)a_[ai++]=a[i];
      else if(a[i]!=a[i-1])a_[ai++]=a[i];
      else cns[0][ai-1]++;
    }
    a_[ai]=0;
    int err=0;
    for(int cnt=1;cnt<n;cnt++){
      cin>>b;
      char b_[110];
      int lb=strlen(b);
      strcpy(s[cnt],b);
      int bi=0;
      for(i=0;i<lb;i++){
	if(i==0)b_[bi++]=b[i];
	else if(b[i]!=b[i-1])b_[bi++]=b[i];
	else cns[cnt][bi-1]++;
      }
      b_[bi]=0;
      if(strcmp(a_,b_)!=0){
	err=1;
      }
    }
    if(err)pans(ti+1,"Fegla Won");
    else{
      int ans=0;
      for(i=0;i<ai;i++){
	int bestval=1000000000;
	for(int tryval=1;tryval<110;tryval++){
	  int hereval=0;
	  for( j=0;j<n;j++){
	    hereval+=abs(tryval-cns[j][i]);
	  }
	  bestval=min(hereval,bestval);
	}
	ans+=bestval;
      }
      pans(ti+1,ans);
    }
    REP(i,n) delete s[i];
  }
  return 0;
}
