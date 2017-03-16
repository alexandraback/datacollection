#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int x[3001];
int y[3001];
int f[3001];

int N;

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    cin >> N;
    for(int i=0; i<N;i ++)
      cin >> x[i] >> y[i];

    for(int i=0; i<N; i++) {
      int cand1 = 0, cand2=0, cand3=0, cand4=0;
      vector<int> samexu, samexd, sameyr,sameyl;

      for(int j=0; j<N; j++) {
        if(i==j) continue;
        if(x[j] >= x[i] && y[j]>=y[i]) cand1 ++;
        if(x[j] >= x[i] && y[j]<=y[i]) cand2 ++;
        if(x[j] <= x[i] && y[j]>=y[i]) cand3 ++;
        if(x[j] <= x[i] && y[j]<=y[i]) cand4 ++;
        if(x[i]==x[j]) {
          if(y[j] > y[i])
            samexu.push_back(j);
          else 
            samexd.push_back(j);
        }
        if(y[i]==y[j]) {
          if(x[j] > x[i])
            sameyr.push_back(j);
          else
            sameyl.push_back(j);
        }
      }
      if(samexu.size()==0) {
        cand1 -= sameyr.size();
        cand3 -= sameyl.size();
      }
      if(samexd.size() ==0) {
        cand2 -= sameyr.size();
        cand4 -= sameyl.size();
      } 
      if(sameyr.size() ==0) {
        cand1 -= samexu.size();
        cand2 -= samexd.size();
      }
      if(sameyl.size() ==0) {
        cand3 -= samexu.size();
        cand4 -= samexd.size();
      }

      int ret = min(min(cand1, cand2) , min (cand3, cand4));
      f[i] = ret;


    }
    printf("Case #%d: \n",tc);
    for(int i=0; i<N;i ++)
      printf("%d\n", f[i]);


  }

  return 0;
}