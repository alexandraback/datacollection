#include <iostream>
#include <vector>
#include <string>
#include <queue>


struct Party
{
  Party(int mem, char n)
    : mem(mem)
    , n(n)
  {}

  int mem;
  char n;
};


bool operator<(Party const &p1, Party const &p2)
{
  return p1.mem < p2.mem;
}


using namespace std;

using QSen = priority_queue<Party>;
vector<string> simulate(QSen q)
{
  vector<string> r;
  while ( !q.empty() )
  {
    Party p1 = q.top();
    q.pop();
    if ( !q.empty() )
    {
      Party p2 = q.top();
      if ( p2.mem == p1.mem && (p1.mem > 1 || q.size() != 2) )
      {
        q.pop();
        --p1.mem;
        if ( p1.mem > 0 )
          q.push(p1);
        --p2.mem;
        if ( p2.mem > 0 )
          q.push(p2);
        string e(2, ' ');
        e[0] = p1.n;
        e[1] = p2.n;
        r.push_back(e);
        continue;
      }
      else if ( p2.mem <= p1.mem - 2 )
      {
        p1.mem -= 2;
        string e(2, ' ');
        e[0] = p1.n;
        e[1] = p1.n;
        r.push_back(e);
        q.push(p1);
        continue;
      }
    }
    --p1.mem;
    string e(1, p1.n);
    r.push_back(e);
    if ( p1.mem > 0 )
      q.push(p1);
  }
  return r;
}


int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N;
    cin >> N;
    QSen q;
    for ( int i = 0; i < N; ++i )
    {
      int p;
      cin >> p;
      q.emplace(p, 'A' + i);
    }
    cout << "Case #" << t << ':';
    for ( auto &s: simulate(q) )
      cout << ' ' << s;
    cout << '\n';
  }
  return 0;
}
