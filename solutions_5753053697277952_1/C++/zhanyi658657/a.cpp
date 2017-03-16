// File Name: a.cpp
// Author: ***
// Created Time: 2016年04月09日 星期六 08时44分10秒

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

void solve(int n)
{
  vector<pair<int, int> > num(n);
  int sum = 0;
  REP (i, n) {
    int s;
    cin>>s;
    num[i] = MP(s, i);
    sum += s;
  }
  sort(num.begin(), num.end(), greater<pair<int, int> > ());
  if (sum % 2 == 1) {
    cout<<(char)('A' + num[0].second)<<' ';
    num[0].first -= 1;
    sum -= 1;
  }
  while (sum > 0) {
    sort(num.begin(), num.end(), greater<pair<int, int> > ());
    cout<<(char)('A' + num[0].second);
    num[0].first -= 1;
    sum -= 1;
    sort(num.begin(), num.end(), greater<pair<int, int> > ());
    cout<<(char)('A' + num[0].second)<<' ';
    num[0].first -= 1;
    sum -= 1;
  }
  
  
}
int main()
{
  freopen("data", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    int N;
    cin>>N;
    cout<<"Case #"<<i<<": ";
    solve(N);
    cout<<endl;
    
  }
  return 0;
}

