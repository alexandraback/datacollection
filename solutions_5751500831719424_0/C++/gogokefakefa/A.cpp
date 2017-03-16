#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


vector < pair<int, char> > go(string str){
  vector < pair<int, char> > res;
  res.push_back( make_pair(0, str[0]));
  
  for(int i = 0; i < (int)str.size(); ++i)
    if(res.back().second == str[i]){
      ++res.back().first;
    }
    else{
      res.push_back( make_pair(1, str[i]));
    }
  
  return res;
}

int eq( vector < pair<int, char> > t1, vector < pair<int, char> > t2 ){
  if(t1.size() != t2.size())
    return 0;
  for(int i = 0; i < (int)t1.size(); ++i)
    if(t1[i].second != t2[i].second)
      return 0;
    
  return 1;
}

inline int ABS(int t1){
  if(t1 < 0)
    return -t1;
  return t1;
}

int calc(vector<int> v){
  sort(v.begin(), v.end());
  int x = v[(int)v.size() / 2], res = 0;
  
  for(int i = 0; i < (int)v.size(); ++i)
    res += ABS(v[i] - x);
  
  return res;
}
void solve(int i){
  cout << "Case #" << i << ": ";
  int N;
  
  cin >> N;
  
  vector<string> v;
  
  for(int i = 0; i < N; ++i){
    string str;
    cin >> str;
    v.push_back(str);
  }
  
  vector< vector < pair<int, char> > > t;
  
  for(int i = 0; i < (int)v.size(); ++i)
    t.push_back( go(v[i]) );
  /*
  for(int i = 0; i < t.size(); ++i){
    for(int j = 0; j < t[i].size(); ++j)
      cout << t[i][j].first << "," << t[i][j].second << " ";
    
    cout <<endl;
  }*/
  
  for(int i = 0; i < (int)v.size(); ++i)
    if(eq(t[i], t[0]) == 0){
      cout << "Fegla Won\n";
      return;
    }
  int res = 0;
  
  for(int i = 0; i < (int)t[0].size(); ++i){
    vector<int> p;
    for(int j = 0; j < (int)t.size(); ++j)
      p.push_back(t[j][i].first);
    
    res += calc(p);
  }
  
  cout << res << endl;
  
}
int main(){
  int tests;
  
  cin >> tests;
  
  for(int i = 1; i <= tests; ++i)
    solve(i);
}
