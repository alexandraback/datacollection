#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<string>
#include<set>
#include<map>
#include<iomanip>
#include<sstream>
#include<functional>
#include<climits>
#define eps 1e-9
const int mod = 281683;
using namespace std;

int t, r, c, n, ret = 0, dx[4] = { 0, 0, 1, -1 }, dy[4] = { -1, 1, 0, 0 };
int ne[17][17];
bool used[17][17];
void tryall(int x) {
  if (x == 0) {
    int cnt = 0;
    for (int i = 0; i < 17; ++i) memset(used[i], 0, sizeof(used[i]));
    for (int i = 0; i < r; ++i) {
	for (int j = 0; j < c; ++j) {
	  if (ne[i][j] == 1) {
	    for (int k = 0; k < 4; ++k) {
		int nx = i + dx[k], ny = j + dy[k];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c && !used[nx][ny] && ne[nx][ny] == 1) cnt++;
	    }
	    used[i][j] = 1;
	  }
	}
    }
    ret = min(ret, cnt);
    return;
  }
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
	if (ne[i][j] == 1) {
	  ne[i][j] = 0;
	  tryall(x - 1);
	  ne[i][j] = 1;
	}
    }
  }
}
int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0Result.txt", "w", stdout);
  scanf("%d", &t);
  for(int test= 1; test <=t; ++test) {
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 0; i < 17; ++i) {
	memset(ne[i], 0, sizeof(ne[i]));
	memset(used[i], 0, sizeof(used[i]));
    }
    ret = 0;
    if (2 * n <= r*c) {
	ret = 0;
    }
    else {
	for (int i = 0; i < r; ++i) {
	  for (int j = 0; j < c; ++j) {
	    ne[i][j] = 1;
	  }
	}
	ret = (1 << 30);
	tryall(r*c - n);
    }
    printf("Case #%d: %d\n", test, ret);
  }
  return 0;
}