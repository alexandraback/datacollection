#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

bitset<17> get_step()
{
	int r;
	scanf("%d",&r);
	int arr[4][4];
	REP(i,4) REP(j,4)
		scanf("%d",&arr[i][j]);
	bitset<17> res;
	REP(i,4)
		res[arr[r-1][i]]=1;
	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		bitset<17> step1=get_step();
		bitset<17> step2=get_step();
		bitset<17> res=step1&step2;
		if(res.count()==0)
			printf("Case #%d: Volunteer cheated!\n",test);
		else if(res.count()==1)
		{
			int result=0;
			for(int i=0;i<17;i++)
				if(res[i])
					result=i;
			printf("Case #%d: %d\n",test,result);
		}
		else
			printf("Case #%d: Bad magician!\n",test);
	}
	return 0;
}
