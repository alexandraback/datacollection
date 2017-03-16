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
int minv;
int mp[20][20];
int _r;
int _c;

bool valid(int r, int c)
{
  return (r >= 0 && r < _r) && (c >= 0 && c < _c);
}
void sc(int r, int c, int N)
{
  if (N == 0) {
    int p = 0;
    int cnt = 0;
    REP (i, _r) {
      REP (j, _c) {
        if (mp[i][j] &&valid(i + 1, j) && mp[i + 1][j]) p++;
        if (mp[i][j] &&valid(i, j + 1) && mp[i][j + 1]) p++;
        //if (mp[i][j]) cnt ++;
      }
    }
    if (p < minv) minv = p;
    return;
  } 
  if (!valid(r, c)) return;
    for (int j = c;j <_c;++j) {
      mp[r][j] = 1;
      if (j == _c - 1) {
        sc(r + 1, 0, N - 1);
      } else {
        sc(r, j + 1, N - 1);
      }
      mp[r][j] = 0;
    }
    if (r == _r - 1) return;

    for (int i = r + 1;i < _r;++i) {
      for (int j = 0;j < _c;++j) {
        mp[i][j] = 1;
        if (j == _c - 1) {
          sc(i + 1, 0, N - 1);
        } else {
          sc(i, j + 1, N - 1);
        }
        mp[i][j] = 0;
      }
    }

}
int solve(int R, int C, int N)
{
  _r = R;
  _c = C;
  REP (i, _r) {
    REP (j, _c) {
      mp[i][j] = 0;
    }
  }
  minv = 4 * N;
  sc(0, 0, N);
  
  return minv;
}
int main()
{
  freopen("data.txt", "r", stdin);
  int T;
  cin>>T;
  REP (i, T) {
    int R, C, N;
    cin>>R>>C>>N;
    int num = solve(R, C, N);
    cout<<"Case #"<<i + 1<<": "<<num<<endl;
  }
  return 0;
}

