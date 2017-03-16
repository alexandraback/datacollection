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

int solve(vector<int> &m, long N)
{
  for (int i = 0;i < m.size();i++) {

    long left = 1;
    long right = N;
    while (left <= right) {
      
      long long mid = (right + left) / 2;
      long long time = (mid - 1) * (long long) m[i];
      long long sum = 0;
      for (int j = 0;j <= i;++j) {
        sum += (time / m[j]) + 1;
      }
      if (mid > 0) {
        for (int j = i + 1;j < m.size();j++) {
          sum += ((time - 1)/ m[j]) + 1;
        }
      }
      //cout<<sum<<' '<<N<<endl;
      if (sum < N) {
        left = mid + 1;
      } else if (sum > N) {
        right = mid - 1;
      } else {
        return i;
      }
    }
  }
  assert(0);
}
int solve0(vector<int> &m, long N)
{
  long mul = 1;
  REP (i, m.size()) mul *= m[i];

  long sum = 0;
  REP (i, m.size()) {
    sum += mul / m[i];
  }
  long t = N % sum;
  int B = m.size();

  if (t == 0) return B - 1;
  long cnt = 0;
  for (int i = 0;i < mul;++i) {
    REP (j, B) {
      if (i % m[j] == 0) {
        cnt += 1;
        if (cnt == t) return j;
      }
    }
  }
  assert(0);
  return 0;


#if 0
  vector<vector<int> > q(B, vector<int>(mul, 0));
  REP (i, B) REP (j, mul) {
    if (j % m[i] == 0) q[i][j] = 1;
  }
  long cs = 0;
  REP (i, B) REP (j, mul) {
    cs += q[i][j];
  }
  assert(cs == sum);

  long cnt = 0;
  if (t == 0) return B - 1;
  REP (i, mul) REP (j, B) {
    cnt += q[j][i];
    if (cnt == t) return j;
  }
  assert(0);
  return 0;
#endif
}
int main()
{
  freopen("data.txt", "r", stdin);
  int T;
  cin>>T;
  REP (i, T) {
    int B;
    long N;
    cin>>B>>N;
    vector<int> m(B, 0);
    REP (j, B) cin>>m[j];
    int num = solve(m, N);
    cout<<"Case #"<<i + 1<<": "<<num + 1<<endl;
  }
  return 0;
}

