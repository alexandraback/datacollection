#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[110][110];
int l[110][110];
int n,ans;

bool same(char *s1,char *s2) {
	while (*s1==*s2) {
		if(*s1=='\0') return true;
		while (s1[0]==s1[1]) s1++;
		while (s2[0]==s2[1]) s2++;
		s1++;s2++;
	}
	return false;
}

inline int abs(int x) {
	return (x>=0)?x:-x;
}

int main() {
	int t,tt,i,j,p;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		memset(l,0,sizeof(l));
		scanf("%d",&n);
		ans=0;
		for (i=0;i<n;i++) {
			scanf("%s",s[i]);
			p=0;
			l[p][i]++;
			for (j=1;s[i][j]!='\0';j++) {
				if (s[i][j]!=s[i][j-1]) p++;
				l[p][i]++;
			}
			if (i>0&&!same(s[i],s[i-1])) ans=-1;
		}
		printf("Case #%d: ",tt);
		if (ans==-1) printf("Fegla Won\n");
		else {
			for (i=0;i<=p;i++) {
				//for (j=0;j<n;j++) printf("%d ",l[i][j]);
				//printf("\n");
				//nth_element(l[i],l[i]+n,l[i]+n/2);
				sort(l[i],l[i]+n);
				int mid=l[i][n/2];
				//for (j=0;j<n;j++) printf("%d ",l[i][j]);
				//printf("\n");
				for (j=0;j<n;j++) ans+=abs(l[i][j]-mid);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
