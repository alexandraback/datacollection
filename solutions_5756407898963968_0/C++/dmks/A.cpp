#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

vector<int> read() {
  int s;
  cin>>s;
  vector<int> ret;
  for (int line = 1; line <= 4; line++) {
    vector<int> temp(4);
    for (int i = 0; i < 4; i++) cin>>temp[i];
    if (line == s) ret = temp;
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    vector<int> fv = read();
    vector<int> sv = read();
    vector<int> ret;
    for (int n = 1; n <= 16; n++) {
      if (find(fv.begin(), fv.end(), n) != fv.end() && find(sv.begin(), sv.end(), n) != sv.end()) {
        ret.push_back(n);
      }

    }
    if (ret.size() > 1) printf("Case #%d: Bad magician!\n", i);
    else if (ret.size() == 1) printf("Case #%d: %d\n", i, ret[0]);
    else printf("Case #%d: Volunteer cheated!\n", i);
  }
  return 0;
}
