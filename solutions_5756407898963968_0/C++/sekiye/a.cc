#include <iostream>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

typedef long long          ll;
typedef unsigned int       uint;
typedef unsigned long long ull;

using namespace std;

ostream& operator<<(ostream &s, vector<string> v)
{
  int cnt = v.size();
  s << "[ ";
  for (int i=0; i<cnt; i++) {
	if (i > 0) s << ", ";
	s << '"' << v[i] << '"';
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, vector<T> v)
{
  int cnt = v.size();
  s << "[ ";
  for (int i=0; i<cnt; i++) {
	if (i > 0) s << ", ";
	s << v[i];
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, list<T> ls)
{
  int cnt = 0;
  s << "( ";
  for (auto it=ls.begin(); it!=ls.end(); it++) {
	if (it != it.begin()) s << ", ";
	s << *it;
	cnt++;
  }
  return s << " )  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, deque<T> st)
{
  int cnt = st.size();
  s << "[ ";
  for (auto it=st.begin(); it!=st.end(); it++) {
	if (it != st.begin()) s << ", ";
	s << *it;
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T1, typename T2> ostream& operator<<(ostream &s, map<T1,T2> m)
{
  int cnt = m.size();
  s << "{ ";
  for (auto it=m.begin(); it!=m.end(); it++) {
	if (it != m.begin()) s << ", ";
	s << it->first << " => " << it->second;
  }
  return s << " }  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, set<T> st)
{
  int cnt = st.size();
  s << "[ ";
  for (auto it=st.begin(); it!=st.end(); it++) {
	if (it != st.begin()) s << ", ";
	s << *it;
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T1, typename T2> ostream& operator<<(ostream &s, pair<T1,T2> p)
{
  return s << "(" << p.first << "," << p.second << ")";
}

vector<int> ReadList() {
  vector<int> list(4);
  int n;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int m;
      cin >> m;
      if (i == n - 1) {
        list[j] = m;
      }
    }
  }
  return move(list);
}

string Solve() {
  vector<int> list1 = ReadList();
  vector<int> list2 = ReadList();
  int y = 0;
  int c = 0;
  for (int i = 0; i < 4; i++) {
    if (count(list2.begin(), list2.end(), list1[i]) == 1) {
      y = list1[i];
      c++;
    }
  }
  if (c == 1) {
    stringstream ss;
    ss << y;
    return ss.str();
  } else if (y == 0) {
    return "Volunteer cheated!";
  } else {
    return "Bad magician!";
  }
}

int main() {
  int T;
  cin >> T;
  for (int x = 0; x < T; x++) {
    cout << "Case #" << (x + 1) << ": " << Solve() << endl;
  }
}
