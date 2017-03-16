#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#define BSIZE 1<<15
using namespace std;
char buffer[BSIZE];
long bpos = 0L, bsize = 0L;
long readLong() 
{
	long d = 0L, x = 0L;
	char c;
	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}


void solver(int testcase)
{
  int answer;
  vector<int> count(17,0);
  int square[4][4];
  answer = readLong();
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      square[i][j]=readLong();
  for(int i=0;i<4;i++) count[square[answer-1][i]]++;
  answer = readLong();
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      square[i][j]=readLong();
  for(int i=0;i<4;i++) count[square[answer-1][i]]++;
  int k=0;
  bool first = true;
  for(int i=1;i<=16;i++)
    if(count[i]>1)
      if(first) {k=i;first=false;}
      else {printf("Bad magician!\n");return;}
  if(k>0)
    printf("%d\n",k);
  else
    printf("Volunteer cheated!\n");
}

int main()
{
  int testcases=readLong();
  for(int i=0;i<testcases;i++)
  {
    printf("Case #%d: ",i+1);
    solver(i);
  }
  return 0;
}
