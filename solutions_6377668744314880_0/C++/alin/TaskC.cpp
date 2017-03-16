#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int X[3000], Y[3000];

int Solver(int N, int Num){
  int i, j;
  int n1, n2, res;
  __int64 A, B, C, val;

  if( N <= 3 ){
    return 0;
  }

  res = N;
  for( i = 0; i < N; i ++ ){
    if( i == Num ){
      continue;
    }
    A = (__int64)Y[i] - (__int64)Y[Num];
    B = - ((__int64)X[i] - (__int64)X[Num]);
    C = - (__int64)X[Num] * ((__int64)Y[i] - (__int64)Y[Num]) + (__int64)Y[Num] * ((__int64)X[i] - (__int64)X[Num]);
//    printf("A1=(%d,%d) A2=(%d,%d): %lldx + %lldy + %lld = 0\n", X[Num], Y[Num], X[i], Y[i], A, B, C);
    n1 = 0;
    n2 = 0;
    for( j = 0; j < N; j ++ ){
      val = A * (__int64)X[j] + B * (__int64)Y[j] + C;
      if( val > 0 ){
        n1 ++;
      }
      if( val < 0 ){
        n2 ++;
      }
    }
    if( n1 < res ){
      res = n1;
    }
    if( n2 < res ){
      res = n2;
    }
  }
  return res;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i, N, res;

  if( argc < 3 ){
    printf("Usage is: task1 filein fileout\n");
    return 0;
  }

  // Input 

  filein = fopen(argv[1], "r");
  if( filein == NULL ){
    printf("Error open(); filein\n");
    return 0;
  }
  fileout = fopen(argv[2], "w");
  if( fileout == NULL ){
    printf("Error open(); fileout\n");
    return 0;
  }

  fscanf(filein, "%d\n", &T);
  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
    printf("-------------\t=%d\n", t);
    fscanf(filein, "%d\n", &N);
    printf("%d\n", N);
    for( i = 0; i < N; i ++ ){
      fscanf(filein, "%d %d\n", X + i, Y + i);
      printf("%d %d\n", X[i], Y[i]);
    }

    // Solve & Output
    fprintf(fileout, "Case #%d:\n", t + 1);
    for( i = 0; i < N; i ++ ){
      res = Solver(N, i);
      fprintf(fileout, "%d\n", res);
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
