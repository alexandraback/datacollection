#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn = 20;
int f[maxn][maxn][maxn],two[maxn];
int main(){

	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T,cas;
	int r,c,n;
	scanf("%d",&T);
	for(int i=0;i<20;i++) two[i]=1<<i;
	memset(f,-1,sizeof(f));
	for(cas=1;cas<=T;cas++){
		scanf("%d%d%d",&r,&c,&n);
		int ans;
		if(f[r][c][n]!=-1) ans=f[r][c][n];
		else{
			ans=1<<30;
			int state=1<<(r*c); int p=r*c;
			for(int s=0;s<state;s++){
				int sum=0;
				for(int i=0;i<p;i++)
					if(two[i]&s) sum++;
				if(sum!=n) continue;
				int tmp=0;
				for(int i=0;i<r;i++)
					for(int j=1;j<c;j++)
						if((two[i*c+j]&s)&&(two[i*c+j-1]&s)) tmp++;
				for(int i=1;i<r;i++)
					for(int j=0;j<c;j++)
						if((two[i*c+j]&s)&&(two[i*c-c+j]&s)) tmp++;
				if(tmp<ans) ans=tmp;
			}
			f[r][c][n]=ans;
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
