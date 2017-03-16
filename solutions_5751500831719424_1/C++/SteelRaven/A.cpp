#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Word {
  vector < char > chars;
  vector < int > counts;

  Word() {}

  Word(const string& s) {
    for(char c: s){
      if(chars.empty() || chars.back() != c){
        chars.push_back(c);
        counts.push_back(1);
      }else{
        ++counts.back();
      }
    }
  }

};

void solve() {
  int n;
  cin >> n;
  vector < Word > words(n);
  string s;
  for(int i = 0; i < n; ++i){
    cin >> s;
    words[i] = Word(s);
  }
  for(int i = 1; i < n; ++i){
    if(words[0].chars != words[i].chars){
      cout << "Fegla Won";
      return;
    }
  }
  vector < int > sizes(n);
  int res = 0;
  for(int i = 0; i < (int)words[0].chars.size(); ++i){
    for(int j = 0; j < n; ++j)
      sizes[j] = words[j].counts[i];
    nth_element(sizes.begin(), sizes.begin() + n / 2, sizes.end());
    for(int j = 0; j < n; ++j)
      res += abs(sizes[n / 2] - sizes[j]);
  }
  cout << res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for(int test = 1; test <= tests; ++test){
    cout << "Case #" << test << ": ";
    solve();
    cout << '\n';
  }
}
