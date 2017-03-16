#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> ii;
#define A first
#define B second

string NOPE = "Fegla Won";

int main() {
  int tests;
  cin >> tests;
  for(int test = 1; test <= tests; ++test) {
    int n;
    cin >> n;
    cout << "Case #" << test << ": ";
    string t[100];
    string c[100];
    int idx[100] = {0};
    for(int i = 0; i < n; ++i) {
      cin >> t[i];
      c[i] = t[i];
      c[i].erase(unique(c[i].begin(), c[i].end()), c[i].end());
    }
    bool valid = true;
    for(int i = 1; i < n; ++i) {
      if(c[i] != c[0]) {
	cout << NOPE << "\n";
	valid = false;
	break;
      }
    }
    if(valid) {
      int countt[100][100] = {0};
      for(int i = 0; i < n; ++i) {
	int idx = 0;
	for(int j = 0; j < t[i].size(); ++j) {
	  if(j > 0 && t[i][j] != t[i][j - 1]) {
	    ++idx;
	  }
	  ++countt[i][idx];
	}
      }
      int finalAns = 0;
      for(int k = 0; k < c[0].size(); ++k) {
	int minAns = 2000000000;
	for(int j = 1; j <= 100; ++j) {
	  int ans = 0;
	  for(int i = 0; i < n; ++i) {
	    ans += abs(countt[i][k] - j); 
	  }
	  minAns = min(minAns, ans);
	}
	finalAns += minAns;
      }
      cout << finalAns << "\n";
    }
  }
  return 0;
}

