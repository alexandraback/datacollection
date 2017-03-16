#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int R, C, N;
std::vector<bool> v;

int score(int r, int c) {
  int ret = 0;
  if(r > 0 && v[(r-1)*C + c]) ++ret;
  if(r + 1 < R && v[(r+1)*C + c]) ++ret;
  if(c > 0 && v[r*C + c-1]) ++ret;
  if(c+1 < C && v[r*C + c+1]) ++ret;
  return ret;
}
int newScore(int r, int c, int ro, int co) {
  int ret = 0;
  if(r > 0 && v[(r-1)*C + c] && (r - 1 != ro || c != co)) ++ret;
  if(r + 1 < R && v[(r+1)*C + c] && (r + 1 != ro || c != co)) ++ret;
  if(c > 0 && v[r*C + c-1] && (r != ro || c - 1!= co)) ++ret;
  if(c+1 < C && v[r*C + c+1] && (r != ro || c + 1 != co)) ++ret;
  return ret;
}

int TotalScore() {
  int ret = 0;
  for(int r = 0; r < R; ++r)
    for(int c = 0; c < C; ++c)
      if(v[r*C+c])
        ret += score(r,c);
  ret /= 2;
  return ret;
}
void Run(int testcase) {
  cin >> R >> C >> N;
  v.resize(R*C);

  int best = 4 * N;
  for(int i = 0; i < (1 << (R*C)); ++i) {
    if(__builtin_popcount(i) != N) continue;
    for(unsigned j = 0; j < v.size(); ++j)
      v[j] = (i & (1 << j)) ? true : false;
    int r = TotalScore();
    if(r < best)
      best = r;
  }
  cout << "Case #" << testcase << ": " << best << "\n";
  /*for(int r = 0; r < R; ++r)
    for(int c = 0; c < C; ++c)
    std::cerr << v[r*C+c] << "(" << score(r,c) << ") ";
  std::cerr << "\n";*/
}

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i)
    Run(i);
}