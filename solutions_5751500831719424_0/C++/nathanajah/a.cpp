//nathanajah's template
//28-11-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE

vector <pair<char,int> > arr[10005];
string s;
int i,j;
int t,n;
int main()
{
	scanf("%d",&t);
	int cs = 0;
	while (t--) {
		printf("Case #%d: ",++cs);
		scanf("%d",&n);
		for (i=0;i<n;++i) {
			arr[i].clear();
			s = GetString();
			arr[i].push_back(mp(s[0],1));
			for (j=1;j<SZ(s);++j) {
				if (s[j]==s[j-1]) {
					arr[i][SZ(arr[i])-1].se++;
				}
				else
					arr[i].push_back(mp(s[j],1));
			}
		}
		bool can = true;
		for (i=0;i<n;++i) {
			if (SZ(arr[i])!=SZ(arr[0]))
				can = false;
		}
		for (i=0;i<n;++i) {
			if (!can)
				break;
			for (j=0;j<SZ(arr[i]);++j)
				if (arr[i][j].fi != arr[0][j].fi)
					can = false;
		}
		if (!can)
			printf("Fegla Won\n");
		else {
			int res = 0;
			for (j=0;j<SZ(arr[0]);++j) {
				int mini = 100000000;
				for (int k = 1; k<= 100; ++k) {
					int now = 0;
					for (i=0;i<n;++i) {
						now += abs(arr[i][j].se - k);
					}
					mini = min(mini,now);
				}
				res += mini;
			}
			printf("%d\n",res);
		}
	}
}
