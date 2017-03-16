#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define Ari using
#define ganteng namespace
#define banget std

#define ll long long
#define ul unsigned long long
#define pb push_back
#define mp make_pair
#define lcm(a,b) a*b/__gcd(a,b)
#define lsb(a) (a & (-a))
#define ft first
#define sc second
#define inf 10000000

#define STRtoINT(a,b) istringstream(a)>>b
#define INTtoSTR(a,b) b=static_cast<ostringstream*>(&(ostringstream()<<a))->str()

//set -> pair <set<int>::iterator,bool> pa; pa=set.insert(x); pa.second return bool;

template<typename t>
t getnum()
{
 t res=0;
 char c;
 int sign=1;
 while(1){
	c=getchar();
	if(c==' '||c=='\n')continue;
	else break;}
 if(c=='+'){}
 else if(c=='-')sign=-1;
 else res=c-'0';
 while(1){
	c=getchar();
	if(c>='0'&&c<='9')res=res*10+c-'0';
	else break;}
return res*sign;
}

Ari ganteng banget;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int testcase=getnum<int>();
	for(int tc=1;tc<=testcase;tc++)
	{
		vector<int>ans;
		bool g[20];
		memset(g,false,sizeof g);
		int a=getnum<int>();
		for(int x=1;x<=4;x++)
		{
			for(int y=1;y<=4;y++)
			{
				int now=getnum<int>();
				if(x==a){g[now]=true;}
			}
		}
		a=getnum<int>();
		for(int x=1;x<=4;x++)
		{
			for(int y=1;y<=4;y++)
			{
				int now=getnum<int>();
				if(x==a && g[now]==true)ans.pb(now);
			}
		}
		printf("Case #%d: ",tc);
		if(ans.size()==1)printf("%d\n",ans[0]);
		else if(ans.size()>1)printf("Bad magician!\n");
		else printf("Volunteer cheated!\n");
	}

  return 0;
}

