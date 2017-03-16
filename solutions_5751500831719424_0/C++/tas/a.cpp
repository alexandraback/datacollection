#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <assert.h>     /* assert */
#include <limits>
#include <set>
#include <map>

using namespace std;


template <typename T>
T read()
{
  std::string line;
  getline(std::cin, line);
  std::istringstream iss(line);
  T i;
  iss >> i;
  return i;
}

template <typename T>
vector<T> readv()
{
  std::string line;
  getline(std::cin, line);
  std::istringstream iss(line);
  T tmp;
  vector<T> v;
  while (iss >> tmp)
  {
    v.push_back(tmp);
  }
  return v;
}

template <typename T>
void printv(const vector<T>& v)
{
  for (auto i : v)
    cout << i << " ";
  cout << endl;
}


void calc_d( vector<int>& maxe, vector<int>& mine, string& clean, string& s, vector< map<int,int> >& mem)
{
  auto i = s.begin();
  for (int pos=0; pos < clean.size(); pos++)
  {
    char c= clean[pos];
    
    auto j = i;
    
    for ( ; j != s.end() && *j == c; ++j )
      ;
    
    int d = j - i;
    i = j;
    
    maxe[pos] = max( maxe[pos], d);
    mine[pos] = min( mine[pos], d);
    
    if ( mem[pos].count(d) )
    {
      mem[pos][d]++;
    }
    else
    {
      mem[pos][d] = 1;
    }
    
  }
}    

int get_cost( vector< map<int,int> >& mem, int pos, int q, int T)
{
  int cost = 0;
  int U =0 ;
  for ( auto& it : mem[pos] )
  {
    int val = it.first;
    int rep = it.second;
    cost += abs(q-val)*rep;
    U+=rep;
  }
  assert (U == T);
  return cost;
}

void proc_case()
{
  int n = read<int>();
  vector<string> words;
  set<string> cleaned;
  string clean;
  for (int i=0; i < n; i++)
  {
    string s = read<string>();
    words.push_back(s);
    clean = s;
    auto it = unique(clean.begin(), clean.end());
    clean.resize( distance( clean.begin(), it));
    cleaned.insert(clean);
    //cout << endl << "-->" << clean << endl;
  }
  //printv(words);
  //cout << cleaned.size() << endl;
  if (cleaned.size() > 1)
  {
    cout << "Fegla Won" << endl;
    return;
  }
  
  vector<int> maxe(clean.size(), 0);
  vector<int> mine(clean.size(), numeric_limits<int>::max());
  
  vector< map<int,int> > mem( clean.size());
  
  for (auto w : words)
  {
    calc_d( maxe, mine, clean, w, mem);
  }
  
  int moves = 0;
  for ( int pos=0; pos < clean.size(); pos++)
  {
    int cost = numeric_limits<int>::max();
    for (int i = mine[pos]; i <= maxe[pos]; i++)
    {
      cost = min(get_cost( mem, pos, i, words.size()), cost);
    }
    moves += cost;
  }
    
    
  //printv(maxe);
  //printv(mine);
  cout <<  moves <<endl;
  
  
  
}


int main()
{
  int t = read<int>();
  for (int i=0; i < t; i++)
  {
    cout << "Case #" << i+1 << ": " ;
    proc_case();
  }
}