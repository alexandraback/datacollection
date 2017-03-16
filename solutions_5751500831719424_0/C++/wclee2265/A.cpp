#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>

#define N 100
#define INF 1e9

using namespace std;

int n;
string a[N+5];
int b[N+5][N+5];
int sum;

void input()
{
	scanf("%d",&n);
	char c[105];
	for(int i=1; i<=n; i++) {
		a[i]="";
		scanf(" %s",c+1);
		int len=strlen(c+1);
		for(int j=1; j<=len; j++) {
			if(c[j]!=c[j-1]) {
				a[i]+=c[j];
				b[i][a[i].size()]=1;
			}
			else b[i][a[i].size()]++;
		}
	}
}

bool process()
{

	sum=0;
	for(int i=2; i<=n; i++) {
		if(a[i]!=a[i-1]) return false;
	}

	for(int i=1; i<=a[1].size(); i++) {
		int x=INF;
		for(int j=1; j<=100; j++) {
			int tmp=0;
			for(int k=1; k<=n; k++) tmp+=abs(j-b[k][i]);
			if(x>tmp) x=tmp;
		}
		sum+=x;
	}

	return true;
}

int main()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small-attempt0.out","wt",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {		
		printf("Case #%d: ",i);
		input();
		if(!process()) printf("Fegla Won");
		else printf("%d",sum);
		printf("\n");
	}
	return 0;
}