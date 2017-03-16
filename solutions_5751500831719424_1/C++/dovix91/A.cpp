#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

void solve(int test) {
  int i, j;
  
  int n;
  cin >> n;
  
  vector<string> s(n);
  for(i=0; i<n; i++) cin >> s[i];
  
  // remove duplicates in the first string
  string base = "";
  char c = ' ';
  for(i=0; i<s[0].size(); i++) {
    if(s[0].at(i) != c) {
      c = s[0].at(i);
      base += c;
    }
  }
  
  vector<vector<int> > freq(base.size());
  
  for(i=0; i<n; i++) {
    // Chack that the string has same pattern as first && compute frequency
    int pos = 0, cont = 0;
    for(j=0; j<s[i].size(); j++) {
      if(s[i].at(j) != base[pos]) {
        if(cont == 0) {
          cout << "Case #" << (test+1) << ": Fegla Won" << endl;
          return;
        }
        freq[pos].push_back(cont);
        cont = 0;
        pos++;
        if(pos >= base.size() || s[i].at(j) != base[pos]) {
          cout << "Case #" << (test+1) << ": Fegla Won" << endl;
          return;
        }
      }
      cont++;
    }
    if(cont == 0 || pos < base.size()-1) {
      cout << "Case #" << (test+1) << ": Fegla Won" << endl;
      return;
    }
    freq[pos].push_back(cont);
  }
  
  /*
  for(i=0; i<base.size(); i++) {
    for(j=0; j<n; j++) {
      cout << freq[i][j] << " ";
    }
    cout << endl;
  }
  */
  
  int tot = 0;
  for(i=0; i<base.size(); i++) {
    sort(freq[i].begin(), freq[i].end());
    int mid;
    if(n%2 == 1) mid = freq[i][n/2];
    else mid = (freq[i][n/2]+freq[i][n/2-1])/2;
    
    for(j=0; j<n; j++) {
      tot += abs(freq[i][j]-mid);
    }
  }

  cout << "Case #" << (test+1) << ": " << tot << endl;
}


int main() {
  int t, T;
  cin >> T;
  for(t=0; t<T; t++) solve(t);
  return 0;
}

