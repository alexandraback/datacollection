#include <cstdio>

struct Pos
{
  int row;
  int col;
  Pos(int r=0, int c=0): row(r), col(c) {}
} pos[17][2];

int response[2]; // by the volunteer
int grid[2][4][4];

void read()
{
  for ( int k=0; k<2; ++k ) {
    scanf("%d", &response[k]);
    --response[k];
    for ( int i=0; i<4; ++i ) {
      for ( int j=0; j<4; ++j ) {
	scanf("%d", &grid[k][i][j]);
	pos[grid[k][i][j]][k] = Pos(i, j);
      }
    }
  }
}

void check()
{
  int ans_count = 0;
  int ans = -1;
  for ( int num=1; num<=16; ++num ) {
    int row_old = pos[num][0].row;
    int row_new = pos[num][1].row;
    if ( row_old==response[0] && row_new==response[1] ) {
      ans = num;
      ++ans_count;
      if ( ans_count >= 2 ) {
	puts("Bad magician!");
	return;
      }
    }
  }
  if ( ans_count==0 ) {
    puts("Volunteer cheated!");
  }
  else {
    printf("%d\n", ans);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    printf("Case #%d: ", t);
    read();
    check();
  }
}
