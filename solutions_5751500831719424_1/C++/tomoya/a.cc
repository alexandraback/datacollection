#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

string getUniqueCh(string str) {
  string uniqueCh = "";

  for (int i=0; i<(int)str.size(); i++) {
    if(i == 0) { uniqueCh += str[i]; }
    else if (str[i-1] != str[i]) {
      uniqueCh += str[i];
    }
  }
  return uniqueCh;
}

vector<int> getUniqueChNum(string str) {
  vector<int> uniqueChNum(1,1);
  int idx = 0;

  for (int i=1; i<(int)str.size(); i++) {
    if (str[i] == str[i-1]) {
      uniqueChNum[idx]++;
    } else {
      uniqueChNum.push_back(1);
      idx++;
    }
  }
  return uniqueChNum;
}

int main() {
  int totalTc;
  cin >> totalTc;
  for(int tc = 1; tc <= totalTc; tc++) {
    int n; cin >> n;
    vector<string> inputs(n);

    for(int i=0; i<n; i++) {
      cin >> inputs[i];
    }
    cout << "Case #" << tc << ": ";

    string uniqueCh = getUniqueCh(inputs[0]);

    for(int i=1; i<n; i++) {
      if (uniqueCh != getUniqueCh(inputs[i])) {
	uniqueCh = ""; break;
      }
    }
    if (uniqueCh == "") {
      cout << "Fegla Won" << endl;
      continue;
    }
    vector< vector<int> > uniqueChNums;
    for (int i=0; i<n; i++) {
      uniqueChNums.push_back(getUniqueChNum(inputs[i]));
    }
    int ans = 0;
    
    for(int i=0; i<uniqueChNums[0].size(); i++) {
      int cost = 1000000;
      for (int uidx = 0; uidx<(int)uniqueChNums.size(); uidx++) {
	int tmpCost = 0;
	for (int compIdx = 0; compIdx<(int)uniqueChNums.size(); compIdx++) {
	  tmpCost += abs(uniqueChNums[uidx][i] - uniqueChNums[compIdx][i]);
	}
	cost = min(tmpCost, cost);
      }
      ans += cost;
    }
    cout << ans << endl;
  }
  return 0;
}
