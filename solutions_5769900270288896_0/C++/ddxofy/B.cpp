/*
* @Author: mkg
* @FileName: B
* @Date:   2015-05-02 23:48:29
* @Last Modified by:   mkg
* @Last Modified time: 2015-05-03 00:02:28
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Long;
typedef double DD;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef pair<int, int> PII;
typedef pair<Long, Long> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

const int INF = 2000000000;
const int MOD = 1000000007;

#define sf scanf
#define pf printf
#define mem(a,b)          	memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b)        	for(int i=a; i<=b; ++i)
#define REPI(i,a,b,c)     	for(int i=a; i<=b; i+=c)
#define REPR(i,a,b)       	for(int i=b; i>=a; --i)
#define REPRD(i,a,b,c)    	for(int i=b; i>=a; i-=c)
#define REPB(i,a)         	for(int i=a; ;i++)
#define REPRB(i,a)        	for(int i=a; ; i--)
#define mp(a,b)   			make_pair(a,b)
#define fs        			first
#define sc        			second
#define SZ(s)     			((int)s.size())
#define PI        			3.141592653589793
#define VS        			vector<string>
#define VI        			vector<int>
#define VD        			vector<DD>
#define VL        			vector<Long>
#define VVL       			vector<VL >
#define lim       			10000003
#define tlim      			(1<<((int)ceil(log2(lim))+1))
#define unq(vec)  			stable_sort(vec.begin(),vec.end());\
                  			vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)     			a.begin(),a.end()
#define rev(a)    			reverse(BE(a))
#define sorta(a)  			stable_sort(BE(a))
#define sortc(a, comp)  	sort(BE(a),comp)

//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};//knight move
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};//8 move
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};//4 move

int DP[lim], R, C, N;

int get_unhappy(int mask)
{
	int ans = 0;
	REP(i, 0, (R - 1))
	{
		REP(j, 0, (C - 1))
		{
			if (i > 0 && (mask & (1 << (i * C + j))) != 0 && (mask & (1 << (i * C + j - C))) != 0) ans++;
			if (j > 0 && (mask & (1 << (i * C + j))) != 0 && (mask & (1 << (i * C + j - 1))) != 0) ans++;
		}
	}
	return ans;
}
int main(int argc, const char **argv)
{
	ios::sync_with_stdio(false);
	freopen("B_small_input.txt","r",stdin);
	freopen("B_small_output.txt","w",stdout);
	//double st=clock(),en;
	int Test, Res;
	cin >> Test;
	REP(kase, 1, Test)
	{
		cin >> R >> C >> N;
		Res = (R * C * N) * 1000;
		mem(DP, 0);
		REP(i, 1, (1 << (R * C)))
		{
			int hop = (i & -i);
			DP[i] = DP[i - hop] + 1;
			if (DP[i] == N) Res = min(Res, get_unhappy(i));
		}
		cout << "Case #" << kase << ": " << Res << endl;
	}
	//en=clock();
	//cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}