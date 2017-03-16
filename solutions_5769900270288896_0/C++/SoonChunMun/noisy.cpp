#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int r, c, n, t, mr, mc, mr1, mc1;
const int alz = 16*16;

int check(bool area[alz]) {
  int ans = 0;
  for (int i=0; i<r-1; i++) {
    for (int j=0; j<c-1; j++) {
      if (area[i*c+j]) {
        if (area[(i+1)*c+j]) ans++;
        if (area[i*c+j+1]) ans++;
      }
    }
  }

  /*
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      printf("%d ", area[i*c+j]);
    }
    printf("\n");
  }
  */
  for (int i=0; i<r-1; i++)
    if (area[i*c+c-1] && area[(i+1)*c+c-1]) ans++;

  for (int j=0; j<c-1; j++)
    if (area[(r-1)*c+j] && area[(r-1)*c+j+1]) ans++;

  //printf("ANS: %d\n", ans);
  return ans;
}

bool islast(bool area[alz]) {
  for (int i=0; i<n; i++) {
    if (!area[i]) return false;
  }
  return true;
}

bool test[alz];
int best() {
  int ans = INT_MAX;
  memset(test, false, sizeof(test));
  for (int i=0; i<n; i++) {
    test[i] = true;
  }
  bool init = true;
  while (init || !islast(test)) {
    init = false;
    ans = min(ans, check(test));
    next_permutation(test, test+r*c);
  }
  return ans;
}

int main() {
  scanf("%d", &t);
  for (int ca=1; ca<=t; ca++) {
    scanf("%d %d %d", &r, &c, &n);

    // TEST
    int v = best();
    printf("Case #%d: %d\n", ca, v);

    /*
    mr = max(r-2,1); mc = max(c-2,1);
    mr1 = max(r-1,1); mc1 = max(c-1,1);

    int maxun = mr1 * mc1 * 2 + mr1 + mc1;
    int rem = r*c-n;

    if (n <= ceil(r*c/2)) {
      printf("Case #%d: %d\n", ca, 0);
    } else if (n == r * c) {
      printf("Case #%d: %d\n", ca, maxun);
    } else if (rem <= ceil(mc * mr / 2.0)) {
      printf("Case #%d: %d\n", ca, maxun - rem * 4);
    } else {
      int v = 0;
      bool m[r][c];
      int nei[r][c];

      memset(m, true, sizeof(m));
      for (int i=0; i<r; i++) {
        for (int j=0; j<c-1; j++) {
          nei[i][j] = 4;
        }
      }
      for (int i=0; i<r; i++) {
        nei[i][0] = 3;
        nei[i][c-1] = 3;
      }
      for (int j=0; j<c-1; j++) {
        nei[0][j] = 3;
        nei[r-1][j] = 3;
      }
      nei[0][0] = 2;
      nei[r-1][0] = 2;
      nei[0][c-1] = 2;
      nei[r-1][c-1] = 2;

      int dx[] = {0, 1, 0, -1};
      int dy[] = {1, 0, -1, 0};

      int sz = 4;
      while (rem > 0) {
        for (int i=0;i<r;i++) {
          for (int j=0;j<c;j++) {
            if (m[i][j] && nei[i][j] == sz) {
              m[i][j] = false;
              for (int k=0; k<4; k++) {
                int cx = dx[k]+i;
                int cy = dy[k]+j;
                if (cx >= 0 && cx < r && cy>=0 && cy<c) {
                  nei[cx][cy]--;
                }
                rem--;
              }
            }
          }
        }
        sz--;
      }
      for (int i=0; i<r-1; i++) {
        for (int j=0; j<c-1; j++) {
          if (m[i][j]) {
            if (m[i][j+1]) v++;
            if (m[i+1][j]) v++;
          }
        }
      }
      for (int i=0; i<r-1; i++) {
        if (m[i][c-1] && m[i+1][c-1]) v++;
      }

      for (int j=0; j<c-1; j++) {
        if (m[r-1][j] && m[r-1][j+1]) v++;
      }

      printf("Case #%d: %d\n", ca, v);
    }
  */
  }
  return 0;
}
