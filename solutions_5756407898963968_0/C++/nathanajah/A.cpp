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
int n,i,j;
int arr[4][4];
int arr2[4][4];
int ans1,ans2;
int t;
int cs;
int main()
{
	scanf("%d",&t);
	while (t--) {
		n=4;
		scanf("%d",&ans1);
		for (i=0;i<4;++i)
			for (j=0;j<4;++j)
				scanf("%d",&arr[i][j]);
		scanf("%d",&ans2);
		for (i=0;i<4;++i)
			for (j=0;j<4;++j)
				scanf("%d",&arr2[i][j]);
		--ans1;--ans2;
		int num=0;
		int ans;
		for (i=0;i<4;++i)
			for (j=0;j<4;++j)
				if (arr[ans1][i]==arr2[ans2][j])
				{
					
					num++;
					ans = arr[ans1][i];
				}
		printf("Case #%d: ",++cs);
		if (num==0)
			printf("Volunteer cheated!\n");
		else if (num==1)
			printf("%d\n",ans);
		else
			printf("Bad magician!\n");
	}
}
