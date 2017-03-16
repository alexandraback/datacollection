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

string problem_name = "A-small-attempt2";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}

int val[111][255];
int cnt[111][255];

int main()
{
   init();


	int tst;
	scanf("%d",&tst);
	
	for (int cas = 1; cas<=tst;cas++)
	{
		int res = 0;
		int n;
		scanf("%d\n",&n);
		char st[1000];
		int ok = 1;
			memset(val,0,sizeof(val));
			memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++) {
			gets(st);
			string s = st;
			s+='0';
			int c = 1;
			int cur = 0;
		
			for (int j=1;j<sz(s);j++)
			{
				if (s[j]!=s[j-1])
				{
					val[i][cur] = s[j-1];
					cnt[i][cur] = c;
					cur++;
					c = 1;
				} else c++;
			
			}
		}

		for (int i = 0;i<111;i++)
		{
			int cur = 1<<20;
			int col = 0;
			for (int j=0;j<n;j++)
			{
				if (val[j][i]) col++;
				if (j && val[j][i]!=val[j-1][i]) ok = 0;
			}
			if (col>0 && col<n) ok = 0;
			if (col==0) break;
			for (int j=1;j<=111;j++)
			{
				int col = 0;
				int curval = 0;
				for (int k=0;k<n;k++)
				{
					if (val[k][i]!=0) col++;
					
					//if (val[k][i]!=0)
					curval+=abs(cnt[k][i]-j);
				}
				cur = min(cur,curval);
			//	if (col>0 && col<n) ok = 0;			
			}		
			res+=cur;
		}

		if (!ok) printf("Case #%d: Fegla Won\n",cas); else	
		printf("Case #%d: %d\n",cas, res);	
	}


	


	
  return 0;
}

