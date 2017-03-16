#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
#define LL long long
#define PII pair<int,int>
using namespace std;
int T,n,p[50],m;
priority_queue<PII> q;
PII t;
int main(){
	scanf("%d",&T);
	for (int I=1;I<=T;I++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			q.push(make_pair(p[i],i));
			m+=p[i];
		}
		printf("Case #%d:",I);
		while (!q.empty()){
			printf(" ");
			t=q.top();
			q.pop();
			printf("%c",t.second+64);
			m--;
			if (t.first!=1) q.push(make_pair(t.first-1,t.second));
			if (!q.empty() && m!=2){
				t=q.top();
				q.pop();
				printf("%c",t.second+64);
				if (t.first!=1) q.push(make_pair(t.first-1,t.second));
				m--;
			}
		}
		printf("\n");
	}
    return 0;
}

