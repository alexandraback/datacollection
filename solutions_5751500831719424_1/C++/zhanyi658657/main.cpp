// File Name: main.cpp
// Author: ***
// Created Time: 2014年04月12日 星期六 08时35分01秒

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
using namespace std;

int findmin(vector<int> &cnt)
{
  sort(cnt.begin(), cnt.end());
  int start = cnt[0];
  int end = cnt.back();
  
  int min = 10000000;
  for (int i = start;i <= end;++i) {
    int sum = 0;
    for (int j = 0;j < cnt.size();++j) {
      int dif = abs(cnt[j] - i);
      sum += dif;
    }
    if (sum < min) {
      min = sum;
    }
  }
  return min;
}
void solve()
{
  int n;
  cin>>n;
  vector<string> str;
  for (int i = 0;i < n;++i) {
    string tmp;
    cin>>tmp;
    str.push_back(tmp);
  }
  vector<int> top(str.size(), 0);
  int sum = 0;
  while (true) {
    int find = 0;
    char first = str[0][top[0]];
    for (int i = 0;i < n;++i) {
      if (str[i][top[i]] != first) {
        find = 1;
        break;
      }
    }
    if (find) {
      cout<<"Fegla Won"<<endl;
      return;
    } else {
      vector<int> cnt(n, 0);
      for (int i = 0;i < n;++i) {
        int c = 0;
        for (int j = top[i];j < str[i].size();++j) {
          if (str[i][j] != first) {
            break;
          } else {
            c++;
          }
          top[i]++;
        }
        cnt[i] = c;//
      }
      //for (int j = 0;j < cnt.size();++j) {
      //  cout<<cnt[j]<<' ';
      //}
      int min = findmin(cnt);
      //cout<<"min"<<min<<endl;//cin.get();
      sum += min;
    }
    find = 0;
    for (int i = 0;i < n;++i) {
      if (top[i] == str[i].size()) {
        find += 1;
      }
    }
    if (find == n) {
      break;
    } else if (find > 0) {
      cout<<"Fegla Won"<<endl;
      return;
    }
  }
  cout<<sum<<endl;
  
}
int main()
{
  freopen("/home/zhanyi/Downloads/A-small-attempt0.in", "r", stdin);
  //freopen("data.txt", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}

