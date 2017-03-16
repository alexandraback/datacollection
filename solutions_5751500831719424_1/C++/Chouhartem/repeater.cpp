#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool isPossible(string& s1, string& s2, vector<int>& v1, vector<int>& v2)
{
  v1.clear();
  v2.clear();
  char c = s1[0];
  v1.push_back(1);
  string s(1,c);
  for(int i = 1; i < s1.size(); ++i) {
    if (s1[i] != c) {
      s.push_back(s1[i]);
      v1.push_back(1);
      c = s1[i];
    }
    else {
      v1.back()++;
    }
  }
  c = s2[0];
  v2.push_back(1);
  int j = 0;
  if ( c != s[0] ) {
    return 0;
  }
  for (int i = 1; i < s2.size(); ++i) {
    if ( s2[i] != c ) {
      ++j;
      c = s2[i];
      v2.push_back(1);
      if ( c != s[j] )
        return 0;
    }
    else {
      v2.back()++;
    }
  }
  if ( j != s.size() - 1 )
    return 0;
  return 1;
}

int dist(vector<int> v1, vector<int> v2)
{
  assert(v1.size() == v2.size());
  int total = 0;
  for (int i = 0; i < v1.size(); ++i)
    total += abs(v1[i] - v2[i]);
  return total;
}

int distmin(vector<vector<int> > & v)
{
  int n = v[0].size();
  vector<int> vect(n,1);
  int total = 0;
  for (int j = 0; j < n; ++j) {
    long long mini = 100000;
    for (int i = 1; i <=100; ++i) {
      int sum = 0;
      for (int k = 0; k < v.size(); ++k) {
        sum += abs(v[k][j] - i);
      }
      if ( sum < mini ) {
        mini = sum;
      }
    }
    total += mini;
  }
  return total;
}

int main()
{
  int T;
  cin >> T;
  for (int C = 1; C <= T; ++C) {
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; ++i)
      cin >> s[i];
    vector<vector<int> > v(N);
    cout << "Case #" << C << ": ";
    bool ok = 1;
    for (int i = 1; i < N; ++i) {
      ok &= isPossible(s[0], s[i], v[0], v[i]);
    }
    if ( ok ) {
      cout << distmin(v) << endl;
    }
    else {
      cout << "Fegla Won" << endl;
    }
  }
}
