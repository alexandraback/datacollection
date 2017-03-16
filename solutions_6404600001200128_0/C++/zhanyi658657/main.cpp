// File Name: main.cpp
// Author: ***
// Created Time: 2015年04月11日 星期六 08时26分21秒

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <cassert>
#include <fstream>
#include <sstream>
#include <cmath>
#define FOR(i,a,b)  for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,a)  FOR(i,0,a)
#define PB push_back
#define MP make_pair
#define VC vector
#define PII pair <int, int>
#define VI VC < int >
#define VF VC < float >
#define VS VC < string >
#define VVS VC < VS >
#define DB(a) cerr << #a << ": " << (a) << endl;
#define VALID(ret) (!isnan(ret) && !isinf(ret))
using namespace std;

int solveA(VI &m)
{
  int ans = 0;
  REP (i, m.size() - 1) {
    if (m[i] > m[i + 1]) ans += m[i] - m[i + 1];
  }
  return ans;
}
int solveB(VI &m)
{
  int max = 0;
  REP (i, m.size() - 1) {
    if (m[i] > m[i + 1]) {
      if (m[i] - m[i + 1] > max) max = m[i] - m[i + 1];
    }
  }
  int ans = 0;
  REP (i, m.size() - 1) {
    ans += min(max, m[i]);
  }
  return ans;
}
int main()
{
  freopen("data.txt", "r", stdin);
  int T;
  cin>>T;
  REP (i, T) {
    int n;
    cin>>n;
    vector<int> m(n, 0);
    REP (j, n) cin>>m[j];
    int num1 = solveA(m);
    int num2 = solveB(m);
    cout<<"Case #"<<i + 1<<": "<<num1<<' '<<num2<<endl;
  }
    return 0;
}

