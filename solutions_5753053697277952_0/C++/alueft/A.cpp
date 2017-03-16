#include <bits/stdtr1c++.h>
using namespace std;

int main() {
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    map<int,vector<char>> m;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      int p; cin >> p;
      m[-p].push_back('A'+i);
    }
    cout << "Case #" << T << ":";
    for (map<int,vector<char>>::iterator it = m.begin(); it != m.end(); it++) {
      if (it->first == 0)
        break;
      int ind = 0;
      if (it->second.size() % 2) {
        m[it->first+1].push_back(it->second[0]);
        cout << " " << it->second[0];
        ind = 1;
      }
      while (ind < it->second.size()) {
        m[it->first+1].push_back(it->second[ind]);
        m[it->first+1].push_back(it->second[ind+1]);
        cout << " " << it->second[ind] << it->second[ind+1];
        ind += 2;
      }
      //cout << it->first << ":";
      //for (char c : it->second)
      //  cout << " " << c;
      //cout << endl;
    }
    cout << "\n";
  }
  return 0;
}
