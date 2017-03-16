#include <iostream>
#include <cstdio>

using namespace std;

int mat[20][20];
int viz[20][20];


void printMat(int mat[20][20], int R, int C) {
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

void reset(int mat[20][20], int R, int C) {
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      mat[i][j] = 0;
    }
  }
}

void findOptim(int R, int C) {
  int confMin = 5, iMin = -1, jMin = -1;
  int cnt;

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(mat[i][j] == 0) {
        cnt = 0;
        if(i > 0) cnt += mat[i-1][j];
        if(j > 0) cnt += mat[i][j-1];
        if(i < R-1) cnt += mat[i+1][j];
        if(j < C-1) cnt += mat[i][j+1];

        if(cnt < confMin) {
          confMin = cnt;
          iMin = i;
          jMin = j;
        }
      }
    }
  }

  mat[iMin][jMin] = 1;
}

int divisorias(int mat[20][20], int R, int C) {
  int cnt = 0;
  for(int i = 0; i < R-1; i++) {
    for(int j = 0; j < C; j++) {
      if(mat[i][j] == 1 && mat[i+1][j] == 1) cnt++;
    }
  }

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C-1; j++) {
      if(mat[i][j] == 1 && mat[i][j+1] == 1) cnt++;
    }
  }
  return cnt;
}

void realloc(int R, int C) {
  int m = 0;
  reset(viz, R, C);

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(i < R-1 && mat[i][j] == 1 && mat[i+1][j] == 1) viz[i][j]++;
      if(i > 0 && mat[i][j] == 1 && mat[i-1][j] == 1) viz[i][j]++;
      if(j < C-1 && mat[i][j] == 1 && mat[i][j+1] == 1) viz[i][j]++;
      if(j > 0 && mat[i][j] == 1 && mat[i][j-1] == 1) viz[i][j]++;
      if(viz[i][j] > m) m = viz[i][j];
    }
  }

  if(m == 0) return;

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(viz[i][j] == m) {
        mat[i][j] = 0;
        findOptim(R, C);
      }
    }
  }


}

int best;
int matbest[20][20];

void rec(int i, int j, int R, int C, int N, int div) {
  if(N == 0) {
    if(div < best) {
      best = div;
      for(int l = 0; l < R; l++) {
        for(int m = 0; m < C; m++) {
          matbest[l][m] = mat[l][m];
        }
      }
    }
    return;
  }

  if(i == R-1 && j == C-1 && N > 1) return;

  int temp = div;

  mat[i][j] = 1;
  if(i > 0) div += mat[i-1][j];
  if(i < R-1) div += mat[i+1][j];
  if(j > 0) div += mat[i][j-1];
  if(j < C-1) div += mat[i][j+1];

  if(j < C-1)
    rec(i, j+1, R, C, N-1, div);
  else rec(i+1, 0, R, C, N-1, div);
  mat[i][j] = 0;

  if(i == R-1 && j == C-1) return;

  if(j < C-1)
    rec(i, j+1, R, C, N, temp);
  else rec(i+1, 0, R, C, N, temp);

}

int main() {
  int T;
  int R, C, N, aux;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    scanf("%d %d %d", &R, &C, &N);
    reset(mat, R, C);
    reset(matbest, R, C);
    /*aux = N;

    while(aux > 0) {
      findOptim(R, C);
      aux--;
    }

    if(N > 0)
      realloc(R, C);
    //cout << R << " " << C << " " << N << endl;
    //printMat(mat, R, C);

    reset(mat, R, C);*/
    best = N*N*N;
    rec(0, 0, R, C, N, 0);
    //printMat(matbest, R, C);
    printf("Case #%d: %d\n", caso, divisorias(matbest, R, C));
  }

  return 0;
}

