#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int M[1000];

int Solver(int B, int N){
  __int64 MaxTime = 1000000000000000ULL;
  __int64 l, r, m, finished, inprogress, busy;
  int i, res;

  l = 0;
  r = MaxTime;
  while( r > l + 1 ){
    m = (r + l) / 2;
    finished = 0;
    inprogress = 0;
    for( i = 0; i < B; i ++ ){
      finished += m / M[i];
      if( m % M[i] ){
        inprogress ++;
      }
    }
    if( finished + inprogress < N ){
      l = m;
    }
    else{
      r = m;
    }
  }
  printf("l = %lld m = %lld r = %lld finished = %lld inprogress = %lld\n", l, m, r, finished, inprogress);
  finished = 0;
  inprogress = 0;
  for( i = 0; i < B; i ++ ){
    finished += l / M[i];
    if( l % M[i] ){
      inprogress ++;
    }
  }
  printf("l = %lld m = %lld r = %lld finished = %lld inprogress = %lld\n", l, m, r, finished, inprogress);
  busy = 0;
  for( i = 0; i < B; i ++ ){
    if( l % M[i] == 0 ){
      busy ++;
    }
    if( busy == N - finished - inprogress ){
      res = i;
      break;
    }
  }


  return res + 1;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i, B, N, res;

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
    fscanf(filein, "%d %d\n", &B, &N);
    printf("%d %d\n", B, N);
    for( i = 0; i < B - 1; i ++ ){
      fscanf(filein, "%d ", M + i);
      printf("%d ", M[i]);
    }
    fscanf(filein, "%d\n", M + B - 1);
    printf("%d\n", M[B-1]);

    // Solve & Output
    res = Solver(B,N);
    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
