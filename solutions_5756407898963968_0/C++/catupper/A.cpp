#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void solve(){
  bool hoge[16];
  fill(hoge, hoge + 16, false);
  int a, x;
  vector<int> ans;
  cin >> a;
  for(int i = 0;i < 16;i++){
    cin >> x;
    if(i / 4 + 1 == a){
      hoge[x] = true;
    }
  }
  cin >> a;
  for(int i = 0;i < 16;i++){
    cin >> x;
    if(i / 4 + 1 == a && hoge[x]){
      ans.push_back(x);
    }
  }
  if(ans.size() == 0)cout << "Volunteer cheated!" << endl;
  if(ans.size() == 1)cout << ans[0] << endl;
  if(ans.size() > 1)cout << "Bad magician!" << endl;
}

int main(){
  int t;
  cin >> t;
  for(int i = 1;i <= t;i++){
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
