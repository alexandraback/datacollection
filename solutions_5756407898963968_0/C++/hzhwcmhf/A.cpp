#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <iomanip>
#include <string>
#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include <cassert>
#include <complex>
using namespace std;
#ifdef _GLIBCXX_DEBUG
string filename(__FILE__,string(__FILE__).find(".cpp"));
#endif
#define PB push_back
#define MP make_pair
#define SIZE(a) ((int)a.size())
#define REP(x,a) for(typeof(a.begin()) x=a.begin();x!=a.end();x++)
#define ACS(a,b) (a?a->b:0)
#define EACS(a,b,c) (a?a->b:c)
#define AUTO(a,b) typeof(b) a=(b)
#define ft first
#define sd second
const int INF=0x3f3f3f3f;
const long long INFLL=0x3f3f3f3f3f3f3f3fLL;
template<class T>
inline bool tension(T &a,const T &b)
{
	if(b<a){
		a=b;
		return true;
	}
	return false;
}
template<class T>
inline bool relax(T &a,const T &b)
{
	if(a<b){
		a=b;
		return true;
	}
	return false;
}
int T;
int mark[20];
void input()
{
	int p;
	scanf("%d",&p);
	int i,j;
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			int tmp;
			scanf("%d",&tmp);
			if(i==p) mark[tmp]++;
		}
	}
}
int main()
{
	//freopen((filename+".in").c_str(),"r",stdin);
	//freopen((filename+".out").c_str(),"w",stdout);
	//freopen((filename+".err").c_str(),"w",stderr);
	scanf("%d",&T);
	int CN=0;
	while(T--){
		printf("Case #%d: ",++CN);
		memset(mark,0,sizeof(mark));
		input();
		input();
		int i;
		vector<int> ans;
		for(i=1;i<=16;i++){
			if(mark[i]==2){
				ans.PB(i);
			}
		}
		if(SIZE(ans)==1){
			printf("%d\n",ans[0]);
		}else if(SIZE(ans)>1){
			printf("Bad magician!\n");
		}else{
			printf("Volunteer cheated!\n");
		}
	}
	return 0;
}
