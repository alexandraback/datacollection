#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 4;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int x, y;
    vector<vector<int>> a(N, vector<int>(N));
    vector<vector<int>> b(N, vector<int>(N));
    cin >> x;
    x--;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> a[i][j];
      } 
    }
    cin >> y;
    y--;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> b[i][j];
      }
    }
    int r = -1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (a[x][i] == b[y][j]) {
          if (r != -1) {
            r = -2;
          } else {
            r = a[x][i];
          }
        }
      }
    }
    printf("Case #%d: ", t);
    if (r == -2) {
      printf("Bad magician!\n");
    } else if (r == -1) {
      printf("Volunteer cheated!\n");
    } else {
      printf("%d\n", r);
    }
  }
}