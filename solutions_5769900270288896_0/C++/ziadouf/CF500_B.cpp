#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <string.h>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 1<<20
#define EPS 1e-5

vvi children;

int solveMax (int ind , int player)
{
	if (sz(children[ind]) == 0) return 1;
	if (player % 2)
	{
		int ret = 0;
		for (int i=0 ; i<sz(children[ind]) ; i++)
		{
			ret += solveMax(children[ind][i] , 1 - player);
		}
		return ret;
	}
	else
	{
		int ret = 1<<30;
		for (int i=0 ; i<sz(children[ind]) ; i++)
		{
			ret = min(ret , solveMax(children[ind][i] , 1 - player));
		}
		return ret;
	}
}

bool grid[20][20];

int main() {

	 freopen ("txt.in","r",stdin);
	    freopen ("txt.out","w",stdout);

	    int TC;
	    cin >> TC;
	    int CC = 1;

	    while (TC--)
	    {
	    	ll ret = 1<<30;
	    	ll R,C,N;
	    	cin >> R >> C >> N;

	    	for (int i=0 ; i<(1<<R*C) ; i++)
	    	{
	    		int r = 0 , c = 0;
	    		int num = 0;
	    		for (int j=0 ; j<(R*C) ; j++)
	    		{
	    			if ( (i & (1<<j)))
	    			{
	    				grid[r][c] = 1;
	    				num ++;
	    			}
	    			else grid[r][c] = 0;

	    			c++;
	    			if (c == C) c = 0 , r++;
	    		}
	    		if (num != N) continue;

	    		int un = 0;
	    		for (int j=0 ; j<R ; j++)
	    		{
	    			for (int k=0 ; k<C ; k++)
	    			{
	    				if (grid[j][k] != 1) continue;
	    				if (k < C-1 && grid[j][k+1] == 1) un++;
	    				if (j < R-1 && grid[j+1][k] == 1) un++;
	    			}
	    		}
	    		if (un < ret) ret = un;
	    	}
	    	printf("Case #%d: ",CC++);
	    	cout << ret << endl;
	    }
}
