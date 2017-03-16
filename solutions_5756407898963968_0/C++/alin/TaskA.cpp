#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int A[4][4], AA, B[4][4], BB;
char Answers[2][30] = {"Bad magician!", "Volunteer cheated!"};

int Solver(){
  int i, j, num = 0, val = 0;

  for( i = 0; i < 4; i ++ ){
    for( j = 0; j < 4; j ++){
      if( A[AA-1][i] == B[BB-1][j] ){
        num ++;
        val = A[AA-1][i];
      }
    }
  }

  if( num == 0 ){
    return -1;
  }
  if( num == 1 ){
    return val;
  }
  return 0;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int res, t, i;

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
    fscanf(filein, "%d\n", &AA);
    printf("%d\n", AA);
    for( i = 0; i < 4; i ++){
      fscanf(filein, "%d %d %d %d\n", &(A[i][0]),&(A[i][1]),&(A[i][2]),&(A[i][3]));
      printf("%d %d %d %d\n", (A[i][0]),(A[i][1]),(A[i][2]),(A[i][3]));
    }
    fscanf(filein, "%d\n", &BB);
    printf("%d\n", BB);
    for( i = 0; i < 4; i ++){
      fscanf(filein, "%d %d %d %d\n", &(B[i][0]),&(B[i][1]),&(B[i][2]),&(B[i][3]));
      printf("%d %d %d %d\n", (B[i][0]),(B[i][1]),(B[i][2]),(B[i][3]));
    }

    // Solve & Output
    res = Solver();
    if( res <= 0 ){
      fprintf(fileout, "Case #%d: %s\n", t + 1, Answers[-res]);
    }
    else{
      fprintf(fileout, "Case #%d: %d\n", t + 1, res);
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
