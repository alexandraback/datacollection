#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;

#define N  64
#define ALL(x)     x.begin(),x.end()
#define CLR(x,a)   memset(x,a,sizeof(x))
typedef pair<int,int> PI;
typedef long long 	  ll;
const int INF    = 0x3fffffff;
const int MOD    = 1000000007;
/*-----------code----------------*/

int cnt[128][128];
char s[128];
string tag;

string get(char *s, int p){
	string tmp(1,s[0]);
	cnt[p][0]++;
	for(int i=1;s[i];i++){
		if(s[i]!=s[i-1]){
			tmp+=s[i];
			cnt[p][tmp.size()-1]++;
		}else{
			cnt[p][tmp.size()-1]++;
		}
	}
	return tmp;
}

int solve(vector<int> &a){
	int ans=INF,sum;
	for(int i=1;i<=100;i++){
		sum=0;
		for(int j=0;j<a.size();j++){
			sum+=abs(a[j]-i);
		}
		ans=min(ans,sum);
	}
	return ans;
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int re,Case=1;
	scanf("%d",&re);
	while(re--){
		int n;
		scanf("%d",&n);
		tag="";
		CLR(cnt,0);
		bool can=true;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			string now=get(s,i);
			if(tag=="") tag=now;
			else if(tag!=now){
				can=false;
			}
		}
		int m=tag.size(), ans=0;

		for(int i=0;i<m;i++){
			vector<int> d;
			for(int j=0;j<n;j++){
				d.push_back(cnt[j][i]);
			}
			sort(ALL(d));
			ans+=solve(d);
		}
		printf("Case #%d: ",Case++);
		if(can){
			printf("%d\n",ans);
		}else{
			puts("Fegla Won");
		}
	}
	return 0;
}
