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
#define ft first
#define sc second
#define inf 3000000
#define lcm(a,b) a*b/__gcd(a,b)
#define lsb(a) (a & (-a))

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
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int testcase=getnum<int>();
	for(int tc=1;tc<=testcase;tc++)
	{
		int ans=0;
		int bny=getnum<int>();
		char hitung[105][105];
		int id[105],ktmu[105],maks;
		memset(id,0,sizeof id);
		
		bool g=true;
		for(int x=0;x<bny;x++)cin>>hitung[x];
		
		//cout<<hitung[0];
		while(id[0]<strlen(hitung[0]))
		{
			char tmp=hitung[0][id[0]];
			maks=0;
			//cout<<id[0]<<endl;
			for(int x=0;x<bny;x++)
			{
				int now=0; bool visited=false;
				for(int y=id[x];y<strlen(hitung[x]);y++)
				{
					//cout<<x<<" "<<y<<" "<<tmp<<" "<<hitung[x][y]<<endl;
					visited=true;
					if(y==id[x] && hitung[x][y]!=tmp){g=false; break;}
					if(hitung[x][y]!=tmp){break;}
					now++;
				}
				id[x]+=now;
				ktmu[x]=now;
				maks=max(maks,now);
				if(visited==false){g=false; break;}
			}
			int temp=99999999,now=0;
			for(int x=1;x<=maks;x++)
			{
				now=0;
				for(int y=0;y<bny;y++)
				{
					now+=abs(ktmu[y]-x);
				}
				temp=min(temp,now);
			}
			ans+=temp;
		}
		
		for(int x=0;x<bny;x++)
		{
			if(id[x]!=strlen(hitung[x]))g=false;
		}
		if(g==false)printf("Case #%d: Fegla Won\n",tc);
		else printf("Case #%d: %d\n",tc,ans);
	}
  return 0;
}


