#include <cstdio>
#include <string>
using namespace std;

#define MAXROW 20
#define MAXCOL 20
int grid[MAXROW][MAXCOL];

int int_pow(int a, int b) {
  if (b == 0) return 1;
  return a * int_pow(a, b-1);
}

void clear() {
  for (int i = 0; i < MAXROW; i++) {
    for (int j = 0; j < MAXCOL; j++) {
      grid[i][j] = 0;
    }
  }
}

int numPeople(int rows, int cols) {
  int people = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      people += grid[i][j];
      // printf("%d", grid[i][j]);
    }
    // printf("\n");
  }
  // printf("\n");
  return people;
}

int score(int rows, int cols) {
  int score = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      score += grid[i][j] * grid[i][j+1];
      score += grid[i][j] * grid[i+1][j];
    }
  }
  return score;
}

void generate(int mask, int rows, int cols) {
  int M = rows * cols;
  for (int i = 0; i < M; i++) {
    int cur = (mask>>i)%2;
    int r = i / cols;
    int c = i % cols;
    grid[r][c] = cur;
  }
}

int tryAll(int rows, int cols, int N) {
  int best = 100000;
  int M = rows * cols;
  int max_mask = int_pow(2, M);
  for (int mask = 0; mask < max_mask; mask++) {
    clear();
    generate(mask, rows, cols);
    // printf("%d %d\n", mask, numPeople(rows, cols));
    if (numPeople(rows, cols) == N) {
      best = min(best, score(rows, cols));
    }
  }
  return best;
}

int main ()
{
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int R, C, N;
    scanf("%d %d %d", &R, &C, &N);
    printf("Case #%d: %d\n", i, tryAll(R, C, N));
  }
}