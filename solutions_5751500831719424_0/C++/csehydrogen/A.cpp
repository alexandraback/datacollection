#include <cstdio>
#include <algorithm>

using namespace std;

int const MAXN = 111;

char str[MAXN][MAXN];
char ord[MAXN];
int ordcnt;
int cnt[MAXN][MAXN];
int buf[MAXN];

int myabs(int x){
	return x>0?x:-x;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,ti,n,i,j,k,ans;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",str[i]);
		}

		ordcnt=0;
		ord[ordcnt++]=str[0][0];
		for(i=1;str[0][i]>0;i++){
			if(str[0][i]!=ord[ordcnt-1]){
				ord[ordcnt++]=str[0][i];
			}
		}

		for(i=0;i<n;i++)
			for(j=0;j<ordcnt;j++)
				cnt[i][j]=0;

		for(i=0;i<n;i++){
			k=0;
			for(j=0;str[i][j]>0;j++){
				if(str[i][j]!=ord[k]){
					if(cnt[i][k]==0) break;
					k++;
					if(k>=ordcnt || str[i][j]!=ord[k]) break;
					cnt[i][k]++;
				}else{
					cnt[i][k]++;
				}
			}
			if(str[i][j]>0 || k!=ordcnt-1)
				break;
		}

		if(i<n){
			printf("Case #%d: Fegla Won\n",ti);
		}else{
			ans=0;
			for(i=0;i<ordcnt;i++){
				for(j=0;j<n;j++){
					buf[j]=cnt[j][i];
				}
				sort(buf,buf+n);
				for(j=0;j<n;j++){
					ans+=myabs(buf[j]-buf[n/2]);
				}
			}
			printf("Case #%d: %d\n",ti,ans);
		}


		
	}
}