#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

int case1(int r, int c, int n)
{
  vector<int> t;
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++)
    {
      if((i+j) % 2 == 0) {t.PB(0); continue;}
      
      if((i==1 && j==c) || (i==r && j==1) || (i==r && j==c)) {t.PB(2); continue;}
      
      if(i==1 || i==r || j==1 || j==c) {t.PB(3); continue;}
      
      t.PB(4);
    }

  sort(t.begin(), t.end());  
  int ret = 0;
  for(int i=0; i<n; i++) ret += t[i];
  return ret;
}

int case2(int r, int c, int n)
{
  vector<int> t;
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++)
    {
      if((i+j) % 2 == 1) {t.PB(0); continue;}
      
      if((i==1 && j==1) || (i==1 && j==c) || (i==r && j==1) || (i==r && j==c)) {t.PB(2); continue;}
      
      if(i==1 || i==r || j==1 || j==c) {t.PB(3); continue;}
      
      t.PB(4);
    }

  sort(t.begin(), t.end());  
  int ret = 0;
  for(int i=0; i<n; i++) ret += t[i];
  return ret;
}

int foo(int r, int c, int n)
{
  if(c < r) swap(r,c);
  
  if(r==1)
  {
    if(c % 2 == 0)
    {
      if(n <= c/2) return 0;
      if(n == c/2 + 1) return 1;
      return 1 + 2*(n-(c/2 + 1));
    }
    
    if(n <= c/2 + 1) return 0;
    
    return 2*(n-(c/2+1));
  }
  
  return min(case1(r,c,n), case2(r,c,n));
}

int main()
{
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