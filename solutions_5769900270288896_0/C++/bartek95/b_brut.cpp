#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

int t[25][25][25];
int pot2[25];
int p[25][25];

int ile(int r, int c, int n)
{
  int ret=0;
  
  int X[4]={-1, 0, 1, 0};
  int Y[4]={0, -1, 0, 1};
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++)
      for(int k=0; k<=3; k++)
      {
	int nx=i+X[k];
	int ny=j+Y[k];
	
	if(nx>=1 && nx<=r && ny>=1 && ny<=c)
	  if(p[i][j] == 1) ret += p[nx][ny];
      }
    
  return ret/2;
}

int policz(int r, int c, int n)
{
  int wynik=2000;
  
  for(int i=0; i<pot2[r*c]; i++)
  {
    int k=i;
    int x=1, y=1;
    int yolo=0;
    
    for(int j=1; j<=r*c; j++)
    {
      p[x][y]=k%2; yolo += k%2;
      k/=2;
      
      y++; if(y>c) y=1, x++;
    }
    if(yolo == n) wynik = min(wynik, ile(r,c,n));
  }

  return wynik;
}

int foo(int r, int c, int n)
{
  if(t[r][c][n] == -1) t[r][c][n] = policz(r, c, n);
  return t[r][c][n];
}

int main()
{
  for(int i=0; i<=20; i++)
    for(int j=0; j<=20; j++)
      for(int k=0; k<=20; k++)
	t[i][j][k]=-1;
  
  pot2[0]=1;
  for(int i=1; i<=20; i++) pot2[i] = 2 * pot2[i-1];
  
  int t;
  scanf("%d", &t);

  for(int i=1; i<=t; i++)
  {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    
    printf("Case #%d: %d\n", i, foo(r, c, n));
  }
  
  return 0;
}