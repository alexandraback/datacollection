#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)

std::string comp(std::string s)
{
  assert(s.size());
  int i=0; REP(j,s.size()) if(s[i]!=s[j]) s[++i] = s[j];
  s.resize(i+1);
  return s;
}

std::vector<int> count(std::string s)
{
  int i=0,j=0;
  std::vector<int> r;
  while(j<s.size())
  {
    while(j<s.size() && s[i]==s[j]) j++;
    r.push_back(j-i); i = j;
  }
  return r;
}

int main()
{
  int t; std::cin >> t;
  FOR(_,1,t)
  {
    std::vector<std::string> V;
    {
      int n; std::cin >> n;
      while(n--){ V.emplace_back(); std::cin >> V.back(); }
    }

    bool ok = 1;
    std::string P = comp(V[0]);
    REP(i,V.size()) if(comp(V[i])!=P) ok = 0;
    
    if(!ok)
    {
      std::cout << "Case #" << _ << ": Fegla Won\n";
      continue;
    }
    
    int res = 0;
    std::vector<std::vector<int>> C;
    REP(i,V.size()) C.push_back(count(V[i]));
    REP(i,P.size())
    {
      std::vector<int> e; REP(j,C.size()) e.push_back(C[j][i]);
      std::sort(e.begin(),e.end());
      int d = e[e.size()/2];
      REP(j,e.size()) res += std::abs(e[j]-d);
    }
    std::cout << "Case #" << _ << ": " << res << "\n";
  }
  return 0;
}
