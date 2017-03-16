#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int M[100];

int Solver1(int N){
  int i;
  int res = 0;

  for( i = 0; i < N - 1; i ++ ){
    if( M[i+1] < M[i] ){
      res += M[i] - M[i+1];
    }
  }
  return res;
}

int Solver2(int N){
  int i, maxspeed, res;

  maxspeed = 0;
  for( i = 0; i < N - 1; i ++ ){
    if( M[i+1] < M[i] ){
      if( maxspeed < M[i] - M[i+1] ){
        maxspeed = M[i] - M[i+1];
      }
    }
  }

  res = 0;
  for( i = 0; i < N - 1; i ++ ){
    if( maxspeed < M[i] ){
      res += maxspeed;
    }
    else{
      res += M[i];
    }
  }
  return res;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i, N, Y, Z;

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
    for( i = 0; i < N - 1; i ++ ){
      fscanf(filein, "%d ", M+i);
      printf("%d ", M[i]);
    }
    fscanf(filein, "%d\n", M+N-1);
    printf("%d\n", M[N-1]);

    // Solve & Output
    Y = Solver1(N);
    Z = Solver2(N);
    fprintf(fileout, "Case #%d: %d %d\n", t + 1, Y, Z);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
