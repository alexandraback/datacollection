#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cassert>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

string normalize(const char *s){
  string r;
  for(int i=0;s[i];i++)if(!r.size()||r[r.size()-1]!=s[i])r+=s[i];
  return r;
}
vi extract(const char *s){
  vector<int> r;
  int cnt=0;
  for(int i=0;s[i];i++)if(!i||s[i-1]==s[i])++cnt;else{r.push_back(cnt);cnt=1;}
  r.push_back(cnt);
  return r;
}
int n;
char s[110][110];
int main(){
  int c;
  scanf("%d",&c);
  for(int cc=1;cc<=c;cc++){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    string t=normalize(s[0]);
    bool ok=true;
    for(int i=0;i<n;i++)ok&=t==normalize(s[i]);
    printf("Case #%d: ",cc);
    if(!ok){printf("Fegla Won\n");continue;}
    vi c[110];
    for(int i=0;i<n;i++)c[i]=extract(s[i]);
    int ans=0;
    for(int i=0;i<n;i++)assert(c[0].size()==c[i].size());
    for(int i=0;i<c[0].size();i++){
      vi t;
      for(int j=0;j<n;j++)t.push_back(c[j][i]);
      sort(t.begin(),t.end());
      int median=t[t.size()/2];
      for(int j=0;j<t.size();j++)ans+=abs(t[j]-median);
    }
    printf("%d\n",ans);
  }
}
