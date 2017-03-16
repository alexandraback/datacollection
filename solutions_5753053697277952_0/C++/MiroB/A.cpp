#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef long long int ll;
void solve() {
  int n;
  cin>>n;
  vector<int> p(n);REP(i,n) cin>>p[i];
  int sum=0;
  REP(i,n) sum+=p[i];
  if(n==2) {
    REP(i,p[0]) {
      printf(" AB");
    }
    printf("\n");
    return;
  } 
  while(sum>0) {
    int c=-1;
    REP(i,n) if(p[i]>1) {
      if(c==-1 ||p[c]<p[i]) c=i;
    
    }
 
    if(c==-1) {
      break;
    }
    printf(" %c",'A'+c);

    p[c]--;
    --sum;
  }
  string f;
  REP(i,n) if(p[i]) f.push_back('A'+i);
  REP(i,f.size()-2) {
    printf(" %c",f[i]);
  }
  int k=f.size();
  printf(" %c%c\n",f[k-2],f[k-1]);


}
int main() {
  int t;cin>>t;REP(i,t) {
    printf("Case #%d:",(i+1));
    solve();
  }

}
