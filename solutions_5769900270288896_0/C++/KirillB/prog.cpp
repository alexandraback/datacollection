#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <string.h>
#include "windows.h"
using namespace std;
#pragma comment(linker, "/STACK:20000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "B-small-attempt0(3)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}


int u[22][22];
int res = 1<<29;
int r,c;
void go(int x, int y, int left, int cur)
{
	if (x>r) 
	{
		if (left) return;
		res = min(res, cur);	
		return;
	}
	
	if (y>c) {
		go(x+1,1,left,cur);
		return ;
	}
	

	if (left)
	{
		u[x][y] = 1;
		go(x,y+1,left-1,cur + u[x-1][y] + u[x][y-1]);
		u[x][y] = 0;
	}

	go(x,y+1,left,cur);

}


int main()
{
   init();


	
	
   int tst;
   //scanf("%d",&tst);
   cin >> tst;

   for (int cas = 1; cas<=tst;cas++)
   {
	      
	   int n;
	   cin >> r >> c >> n;
   
	   res = 1<<29;
	   go(1,1,n,0);
   
	   printf("Case #%d: %d\n",cas,res);	
   }
	





	
  return 0;
}

