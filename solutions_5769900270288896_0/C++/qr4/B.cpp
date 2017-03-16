#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T> std::ostream& operator<<(std::ostream& str, const std::vector<T>& v) { str << "["; for(auto n : v) str << n << ", "; str << "]"; return str; }
template<typename K, typename V> std::ostream& operator<<(std::ostream& str, const std::unordered_map<K,V>& m) { str << "["; for(auto n : m) str << n.first << " => " << n.second <<  ", "; str << "]"; return str; }

#define debug(x) cout <<  #x  << ": " << x << endl

using namespace std;

int solved[20][20][20];
bool a[20][20][20];
unordered_set<string> done;
int R,C,N;
int solve(string T,int cur, int sol)
{
  if (done.count(T+","+to_string(cur)+","+to_string(sol))) return 999999;
  done.insert(T+","+to_string(cur)+","+to_string(sol));
  if (a[R][C][N]) return solved[R][C][N];

  if (cur == N) return sol;

  int res = 99999;
  for (int y = 0; y < R; y++)
  {
    for (int x = 0; x < C; x++)
    {
      if (T.at(y*C+x) =='.')
      {
        string cpy = T;
        int sol_cp = sol;
        cpy.at(y*C+x) = 'X';
        if (x-1 >= 0 && T.at(y*C+x-1) == 'X') sol_cp++;
        if (y-1 >= 0 && T.at((y-1)*C+x) == 'X') sol_cp++;
        if (x+1 < C && T.at(y*C+x+1) == 'X') sol_cp++;
        if (y+1 < R  && T.at((y+1)*C+x) == 'X') sol_cp++;
        res = min(solve(cpy,cur+1, sol_cp), res);
      }
    }
  }
  return res;
}

int main()
{
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> R>> C>>N;
    string t(R*C,'.');
    cout << "Case #" << i+1 << ": ";
    solved[R][C][N] = solve(t,0,0);
    solved[C][N][N] = solved[R][C][N];
    a[R][C][N] = true;
    a[C][R][N] = true;
    cout << solved[R][C][N] << endl;
    done.clear();
  }
}
