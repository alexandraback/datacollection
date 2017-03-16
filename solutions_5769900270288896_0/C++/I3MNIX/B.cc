#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;
int N, R, C;

int unhappy(int num){
  int grid[R][C];
  int idx = 0;
  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      grid[i][j] = num & (1 << idx);
      idx++;
    }
  }

  int dx[] = {-1, 0, 0, 1};
  int dy[] = {0, -1, 1, 0};

  int tot = 0;
  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      if (grid[i][j] == 0) continue;
      for (int k = 0; k < 4; k++){
	int i2 = i + dx[k];
	int j2 = j + dy[k];
  	if (i2 < 0 || i2 >= R || j2 < 0 || j2 >= C) continue;
  	if (grid[i2][j2]) tot++;
      }
    }
  }
  assert(tot % 2 == 0);
  return (tot / 2);
}

int solve(){
  cin >> R >> C >> N;
  int total = R * C;
  int ans = 1000000000;
  for (int bm = 0; bm < (1 << total); bm++){
    int ct = 0;
    for (int i = 0; i < total; i++){
      if (bm & (1 << i)) ct++;
    }
    if (ct != N) continue;
    ans = min(ans, unhappy(bm));
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  for (int cs = 1; cs <= t; cs++){
    cout << "Case #" << cs << ": ";
    cout << solve() << endl;
  }
  return 0;
}
