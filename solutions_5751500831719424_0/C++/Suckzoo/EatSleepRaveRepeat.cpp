#include <cstdio>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;

char dict[110];
int cnt[110][110];
string a[110];
char tmp[110];
int T;
int n;
int ans;
int Abs(int x){return x<0?-x:x;}
int calcmedian(int x) {
	sort(cnt[x],cnt[x]+n);
	int val=0;
	int i;
	for(i=0;i<n;i++) {
		val+=Abs(cnt[x][n/2]-cnt[x][i]);
	}
	return val;
}
int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	for(int Ti=1;Ti<=T;Ti++) {
		ans=0;
		scanf("%d",&n);
		int i,j;
		for(i=0;i<n;i++) {
			scanf("%s",tmp);
			a[i]=tmp;
			memset(tmp,0,sizeof(tmp));
		}
		dict[0]=a[0][0];
		int pt=0;
		for(i=1;i<a[0].length();i++) {
			if(dict[pt]!=a[0][i]) {
				dict[++pt]=a[0][i];
			}
		}
		for(i=0;i<n;i++) {
			int cpt=0;
			for(j=0;j<a[i].length();j++) {
				if(dict[cpt]==a[i][j]) cnt[cpt][i]++;
				else {
					if(cnt[cpt][i]==0) break;
					cpt++;
					if(dict[cpt]==a[i][j]) cnt[cpt][i]++;
					else break;
				}
			}
			if(j<a[i].length()) break;
			if(cpt!=pt) break;
		}
		if(i<n) {
			printf("Case #%d: Fegla won\n",Ti);
		} else {
			for(i=0;i<=pt;i++) {
				ans+=calcmedian(i);
			}
			printf("Case #%d: %d\n",Ti,ans);
		}
		memset(a,0,sizeof(a));
		memset(dict,0,sizeof(dict));
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}