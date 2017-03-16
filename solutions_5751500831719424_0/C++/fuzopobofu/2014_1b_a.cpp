#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int, int> pii;

string uniq(string s) {
  char lastchar = s[0];
  string ret;
  ret += s[0];
  for (int i = 1; i < s.length(); i++) {
    if (s[i] != lastchar) {
      ret += s[i];
      lastchar = s[i];
    }
  }
  return ret;
}

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    
    std::vector<string> var;
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      var.push_back(s);
    }
    
    // first check
    bool b = false;
    for (int i = 0; i < var.size(); i++) {
      if (uniq(var[0]) != uniq(var[i])) {
	std::cout << "Case #" << (t+1) << ": " << "Fegla Won" << std::endl;
	b = true;
	break;
      }
    }
    if (b) continue;

    // 
    std::vector< std::vector<int> > vv(N, std::vector<int>(0));
    for (int i = 0; i < var.size(); i++) {
      char lastchar = var[i][0];
      int n = 1;
      for (int j = 1; j < var[i].length(); j++) {
	if (var[i][j] != lastchar) {
	  vv[i].push_back(n);
	  lastchar = var[i][j];
	  n = 1;
	} else {
	  n++;
	}
      }
      vv[i].push_back(n);
    }

    long sum_cost = 0;
    for (int j = 0; j < vv[0].size(); j++) {
      long max = 0;
      for (int i = 0; i < vv.size(); i++) {
	max = max > vv[i][j] ? max : vv[i][j];
      }

      long min_cost = LONG_MAX;
      // for (int n = 0; n <= max; n++) {
      for (int n = 0; n <= 100; n++) {
	int cost = 0;
	for (int i = 0; i < vv.size(); i++) {
	  cost += abs(n - vv[i][j]);
	}
	min_cost = min_cost < cost ? min_cost : cost;
      }
      
      sum_cost += min_cost;
    }
    
    std::cout << "Case #" << (t+1) << ": " << sum_cost << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
