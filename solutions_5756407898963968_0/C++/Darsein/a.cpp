#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    int a[2],c[2][4][4];
    rep(k,2){
      cin >> a[k];
      rep(i,4)rep(j,4){
	cin >> c[k][i][j];
      }
    }

    vector<int> ans;
    rep(i,4)rep(j,4){
      if(c[0][a[0]-1][i] == c[1][a[1]-1][j]){
	ans.push_back(c[0][a[0]-1][i]);
      }
    }

    cout << "Case #" << casenum << ": ";
    if(ans.size()==0)cout << "Volunteer cheated!" << endl;
    else if(ans.size()==1)cout << ans[0] << endl;
    else cout << "Bad magician!" << endl;
  }
}
