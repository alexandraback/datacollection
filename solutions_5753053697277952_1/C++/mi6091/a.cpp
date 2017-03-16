#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> a[50];
int n;


void solve()
{
  cin >> n;
  priority_queue< pair<int, int> > q;

  int i, total = 0;
  for(i = 0; i < n; i++)
  {
    a[i].second = i;
    cin >> a[i].first;
    q.push(a[i]);
    total += a[i].first;
  }

  while(!q.empty())
  {
    pair<int, int> top = q.top();
    q.pop();
    string s = "";
    s+= (char)('A' + top.second);
    top.first --;
    total--;
    if(top.first != 0)
    {
      q.push(top);
    }
    if(!q.empty())
    {
      top = q.top();
      q.pop();
      //cout << q.top().first()<< " " << q.top().second() << endl;
      if(!q.empty() && 2*q.top().first > total-1)
      {
        q.push(top);
        cout << s << " ";
        continue;
      }

      s+= (char) ('A' + top.second);
      top.first --;
      total--;
      if(top.first >0)
      {
        q.push(top);
      }
    }
    cout << s << " ";
  }
  cout << endl;
}
int main()
{
  int t;
  scanf("%d", &t);

  for(int i = 1; i<=t; i++)
  {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
