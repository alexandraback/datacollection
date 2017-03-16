//this is the default for Google code jam only
#include <string>
#include <vector>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define pii pair<int, int>

using namespace std;

ifstream fi("A-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;

int n;
string s[200];
long long res;

void input();
void solve();
void output();

int main() {
  int ntest;
  fi >> ntest;
  for (test = 1; test <= ntest; test ++) {
    input();
    solve();
    output();
  }
  fi.close();
  fo.close();
  return 0;
}

void input() {
  //start code here
  fi >> n;
  for (int i = 0; i < n; i ++) {
    fi >> s[i];
  }
}

vector< pair<char, int> > conv(string x) {
  vector<pair<char, int> > cx;
  cx.push_back(pair<char, int>(x[0], 1));  
  for (int i = 1; i < x.length(); i ++) {
    if (x[i] != cx[cx.size() - 1].first) {
      cx.push_back(pair<char, int>(x[i], 1));
    }
    else {
      cx[cx.size() - 1].second++;
    }
  }
  return cx;
}

int count(string x, string y) {
  vector<pair<char, int> > cx = conv(x);
  vector<pair<char, int> > cy = conv(y);
  int ret = 0;
  if (cx.size() != cy.size()) {
    return -1;
  }
  for (int i = 0; i < cx.size(); i ++) {
    if (cx[i].first != cy[i].first) {
      return -1;
    }
    ret = ret + fabs(cx[i].second - cy[i].second);
  }
  return ret;
}

void solve() {
  res = -1;
  if (n == 2) {
    res = count(s[0], s[1]);
  }
}

void output() {
  if (res == -1) {
    fo << "Case #" << test << ": Fegla Won" << endl;
  }
  else {
    fo << "Case #" << test << ": " << res << endl;
  }
}
