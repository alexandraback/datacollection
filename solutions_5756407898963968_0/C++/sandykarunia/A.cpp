#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <bitset>
#include <list>

#define EPS 1e-11
#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define swap(a,b) a=a^b, b=a^b, a=a^b;
#define OPENR(a) freopen(a,"r",stdin)
#define OPENW(a) freopen(a,"w",stdout)

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
int xhorse[8] = {1,2,1,2,-1,-2,-1,-2};
int yhorse[8] = {2,1,-2,-1,2,1,-2,-1};

using namespace std;

int t;
int ar[5][5];
int a;
int ans;
set<int> myset;

int main()
{
	OPENR("A-small-attempt0.in");
	OPENW("A-small-attempt0.out");
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		scanf("%d",&a); a--;
		for (int i=0;i<4;i++) for (int j=0;j<4;j++) scanf("%d",&ar[i][j]);
		
		myset.clear();
		for (int i=0;i<4;i++) myset.insert(ar[a][i]);
		
		scanf("%d",&a); a--;
		for (int i=0;i<4;i++) for (int j=0;j<4;j++) scanf("%d",&ar[i][j]);
		
		ans = -1;
		
		for (int i=0;i<4;i++)
		{
			if (myset.find(ar[a][i])!=myset.end())
			{
				if (ans==-1) ans = ar[a][i];
				else if (ans!=-1)
				{
					ans = -2;
					break;
				}
			}
		}
		
		if (ans==-1) printf("Case #%d: Volunteer cheated!\n",tc);
		else if (ans==-2) printf("Case #%d: Bad magician!\n",tc);
		else printf("Case #%d: %d\n",tc,ans);
	}
	
 	return 0;
}



