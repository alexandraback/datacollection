#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, N;
  int t, i, j, ti, P[26], sum;
  char Pc[26], tc;

  if( argc < 3 ){
    printf("Usage is: TaskA filein fileout\n");
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
      fscanf(filein, "%d ", P+i);
      printf("%d ", P[i]);
    }
    fscanf(filein, "%d\n", P+i);
    printf("%d\n", P[i]);

    // Solve & Output
    fprintf(fileout, "Case #%d:", t + 1);
    for( i = 0; i < N; i ++ ){
      Pc[i] = 'A' + i;
    }
    for( i = 0; i < N - 1; i ++ ){
      for( j = N - 1; j > i; j -- ){
        if( P[j-1] < P[j] ){
          ti = P[j-1];
          P[j-1] = P[j];
          P[j] = ti;
          tc = Pc[j-1];
          Pc[j-1] = Pc[j];
          Pc[j] = tc;
        }
      }
    }
    sum=0;
    for( i = 0; i < N; i ++ ){
      sum += P[i];
      printf("P[%d]=%d, Pc[%d]=%c\n", i, P[i], i, Pc[i]);
    }
    if( sum % 2 != 0 ){
      sum --;
      if( P[0] == P[1] ){
        fprintf(fileout, " %c", Pc[1]);
        P[1] --;
      }
      else{
        fprintf(fileout, " %c", Pc[0]);
        P[0] --;
      }
    }
    j = N - 1;
    while( sum > P[0] * 2 ){
      while( P[j] == 0 ){
        j --;
      }
      fprintf(fileout, " %c", Pc[j]);
      P[j] -= 1;
      sum -= 1;
      while( P[j] == 0 ){
        j --;
      }
      fprintf(fileout, "%c", Pc[j]);
      P[j] -= 1;
      sum -= 1;
      //if( P[j] >= 2 ){
      //  fprintf(fileout, " %cc", Pc[j], Pc[j]);
      //  P[j] -= 2;
      //  sum -= 2;
      //}
      //else{
      //  if( P[j] == 1 ){
      //    fprintf(fileout, " %c", Pc[j]);
      //    P[j] -= 1;
      //    sum -= 1;
      //    j --;
      //    while( P[j] == 0 ){
      //      j --;
      //    }
      //    fprintf(fileout, " %c", Pc[j]);
      //    P[j] -= 1;
      //    sum -= 1;
      //  }
      //  else{
      //    j --;
      //    while( P[j] == 0 ){
      //      j --;
      //    }
      //    fprintf(fileout, " %c", Pc[j]);
      //    P[j] -= 1;
      //    sum -= 1;
      //    while( P[j] == 0 ){
      //      j --;
      //    }
      //    fprintf(fileout, " %c", Pc[j]);
      //    P[j] -= 1;
      //    sum -= 1;
      //  }
      //}
    }
    while( sum > 0 ){
      while( P[j] == 0 ){
        j --;
      }
      fprintf(fileout, " %c%c", Pc[0], Pc[j]);
      P[0] -= 1;
      P[j] -= 1;
      sum -= 2;
    }
    fprintf(fileout, "\n");
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
