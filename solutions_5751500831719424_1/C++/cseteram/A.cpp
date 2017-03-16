#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char str[110][110];

int pivot[110], pivotcnt[110];

int Abs(int x) { return x>0? x:-x; }

int main() {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int t,num=0;
	int n,i,ans=0,len_max,th;
	char cmp;
	bool chk;

	scanf("%d", &t);
	while(t--) {

		scanf("%d", &n);
		for(i=0,len_max=0, ans=0,len_max=0 ; i<n ; i++) {
			scanf("%s", str[i]);
			if(strlen(str[i]) > len_max) { len_max=strlen(str[i]); th=i; }
		}

		for(i=0,chk=true ; i<n ; i++) {
			pivot[i]=0; pivotcnt[i]=0;
		}

		while(true) {
			cmp = str[th][pivot[th]];
			if(cmp==0) break;

			for(i=0 ; i<n ; i++) {
				if(str[i][pivot[i]] != cmp) { chk=false; break; }
			}

			for(i=0 ; i<n ; i++) {
				for( ; str[i][pivot[i]] != 0 ; pivot[i]++) {
					if(cmp != str[i][pivot[i]]) break;
					pivotcnt[i]++;
				}
			}

			sort(pivotcnt, pivotcnt+n);
			for(i=0 ; i<n ; i++) {
				if(pivotcnt[i]==0) chk=false;
				break;
			}
			for(i=0 ; i<n ; i++)
				ans += Abs(pivotcnt[i]-pivotcnt[n/2]);
			for(i=0 ; i<n ; i++)
				pivotcnt[i]=0;
		}

		for(i=0 ; i<n ; i++) {
			if(str[i][pivot[i]] !=0 ) {
				chk=false;
				break;
			}
		}

		printf("Case #%d: ", ++num);
		if(chk) printf("%d\n", ans);
		else printf("Fegla Won\n");
	}

	return 0;
}