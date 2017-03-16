#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Google Code Jam
Qualification 2014
Problem A. Magic Trick
*/

#define TRUE 1
#define FALSE 0

#define NROWS 4
#define NCOLS 4


typedef int *row;

row Row_Alloc()
{
  return (int*)(malloc(NCOLS * sizeof(int)));
}

row Populate_Row()
{
  int i;
  row r;
  r = Row_Alloc();
  for(i=0;i<NCOLS;i++){
    scanf("%d", &r[i]);
  }
  return r;
}

row Print_Row(row r)
{
  int i;
  for(i=0;i<NCOLS;i++){
    fprintf(stderr, " %d", r[i]);
  }
  fprintf(stderr, "\n");
}

int Has_Int(row r, int test)
{
  int i;
  for (i=0;i<NCOLS;i++) {
    if (r[i] == test) {
      return TRUE;
    }
  }
  return FALSE;
}

int Number_Of_Matches(row a, row b)
{
  int i,n;
  n=0;
  for (i=0;i<NCOLS;i++) {
    if (Has_Int(a, b[i])) {
      n++;
    }
  }
  return n;
}

int Get_Single_Match(row a, row b)
{
  int i;
  for (i=0;i<NCOLS;i++) {
    if (Has_Int(a, b[i])) {
      return b[i];
    }
  }
  fprintf(stderr, "ERROR: No match in Get_Single_Match function!!!");
  return 0;
}

typedef row *arrangement;

arrangement Arr_Alloc()
{
  return (row*)(malloc(NROWS*sizeof(row)));
}

arrangement Populate_Arrangment()
{
  int i;
  arrangement a;
  a = Arr_Alloc();
  for(i=0;i<NROWS;i++){
    a[i] = Populate_Row();
  }
  return a;
}

row Get_Selected_Row(arrangement a, int sel)
{
  return a[sel-1];
}

void Run(int c)
{
  arrangement a1,a2;
  int answer1, answer2;
  row sel1, sel2;
  scanf("%d", &answer1);
  a1 = Populate_Arrangment();
  scanf("%d", &answer2);
  a2 = Populate_Arrangment();

  sel1 = Get_Selected_Row(a1, answer1);
  sel2 = Get_Selected_Row(a2, answer2);

  //fprintf(stderr, "\nSelected Row: %d\n", answer1);
  //fprintf(stderr, "Row:");
  //Print_Row(sel1);
  //fprintf(stderr, "\nSelected Row: %d\n", answer2);
  //fprintf(stderr, "Row:");
  //Print_Row(sel2);

  fprintf(stdout, "Case #%d: ", c);
  switch (Number_Of_Matches(sel1, sel2))
    {
    case 0:
      fprintf(stdout, "Volunteer cheated!\n");
      break;
    case 1:
      fprintf(stdout, "%d\n", Get_Single_Match(sel1, sel2));
      break;
    default:
      fprintf(stdout, "Bad magician!\n");
      break;
    }
}


int main() {
  int T;
  int i;
  scanf("%d", &T);

  for(i=1;i<=T;i++){
    Run(i);
  }
  return 0;
}
