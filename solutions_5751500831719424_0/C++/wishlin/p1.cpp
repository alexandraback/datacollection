#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int cas, N;
string arr[204];
string rs[204];
vector<int> bins[204];

int pre(int p) {
   int cnt=1;
   rs[p]+=arr[p][0];
   for (int i=1; i<arr[p].size(); ++i) {
      if (arr[p][i]==arr[p][i-1]) ++cnt;
      else {rs[p]+=arr[p][i]; bins[p].push_back(cnt); cnt=1;}
   }
   bins[p].push_back(cnt);
}

int sol_int(int p) {
  int cnts[120]={0}, res, minn=2147483647;
  for (int i=0; i<N; ++i) ++cnts[bins[i][p]];

  for (int ans=0; ans<120; ++ans) if (cnts[ans]) {
    res=0;
    for (int i=0; i<120; ++i) if (cnts[i]) {
      res += (ans>i? ans-i:i-ans) * cnts[i];
    }
    if (minn>res) minn=res;
  }
  return minn;
}

int sol() {
  for (int i=1; i<N; ++i)
    if (rs[i]!=rs[i-1] || bins[i].size()!=bins[i-1].size())
        return -1;
  int res=0;
  for (int i=0; i<bins[0].size(); ++i)
    res+=sol_int(i);
  return res;
}

int main() {
  int mov;
  scanf("%d",&cas);

  for (int k=1; k<=cas; ++k) {
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {cin>>arr[i]; rs[i]=""; bins[i].clear(); pre(i);}
    mov = sol();
    if (mov<0) printf("Case #%d: Fegla Won\n",k);
    else printf("Case #%d: %d\n",k,mov);
  }
  return 0;
}


