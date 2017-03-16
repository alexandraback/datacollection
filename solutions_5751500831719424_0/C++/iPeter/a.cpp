#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[200][200],p[200][200];
int r[200][200];

int abs(int a){return a<0?-a:a;}
int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        
		int n,m;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%s", s[i]);
		for(int i=0,j,k;i<n;i++){
			for(j=0, k=0;s[i][j];j++){
				if(j==0 || s[i][j] != s[i][j-1]){
					p[i][k++] = s[i][j];
					r[k-1][i] = 0;
				}
				r[k-1][i]++;
			}
			p[i][k]=0;
			m=k;
		}
		
		bool flag = true;
		for(int i=1;i<n && flag;i++){
			if(strcmp(p[i], p[i-1]) != 0)
				flag=false;
		}

		/*
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<m;j++)
				printf("%3d", r[j][i]);
		*/
		
		int ans = 0;
		for(int i=0;i<m;i++){
			sort(r[i], r[i]+n);
			for(int j=0;j<n;j++)
				ans += abs(r[i][j] - r[i][n/2]);
		}
		
        printf("Case #%d: ", tt);
		if(!flag)
			puts("Fegla Won");
		else printf("%d\n", ans);
    }
    return 0;
}

