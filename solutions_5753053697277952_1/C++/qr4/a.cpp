#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

#define debug(x) //cout << #x << ": " << x << endl;

template <typename A, typename B>
ostream& operator<<(ostream& ost, const pair<A,B> &m) {
  ost << "[";
  cout << m.first << "," << m.second;
  ost << "]";
  return ost;
};

template <typename T>
ostream& operator<<(ostream& ost, const vector<T> &vec) {
  ost << "[";
  for (auto&& a : vec) cout << a << ", ";
  ost << "]";
  return ost;
};

template <typename K, typename V>
ostream& operator<<(ostream& ost, const map<K,V> &m) {
  ost << "{";
  for (auto&& a : m) cout << a.first << " => " << a.second << ", ";
  ost << "}";
  return ost;
};

void solve() {
  int num;
  cin >> num;
  vector<pair<int,int>> senators;
  unsigned long long total = 0;
  for (int i = 0; i < num; ++i) {
    int temp;
    cin >> temp;
    total += temp;
    senators.push_back(make_pair(i,temp));
  }

  sort(senators.begin(), senators.end(), [](const pair<int,int> &f1, const pair<int,int> &f2) {
      return f1.second > f2.second;
      });

  debug(senators);

  auto& frst = senators.at(0);
  auto& scnd = senators.at(1);
  for (int i = 0; i < frst.second - scnd.second; ++i) {
    cout << (static_cast<char>('A' + frst.first)) << ' ';
  }

  for (int i = 2; i < senators.size(); ++i) {
    auto& s = senators.at(i);
    for (int j = 0; j < s.second; ++j) cout << (static_cast<char>('A'+s.first)) << ' ';
  }

  for (int i = 0; i < scnd.second; ++i) {
    cout << (static_cast<char>('A' + frst.first)) << (static_cast<char>('A' + scnd.first)) << ' ';
  }


}

int main()
{
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i)
  {
    cout << "Case #"<<i<<": ";solve(); cout << endl;
  }
}
