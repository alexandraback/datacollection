#include<stdio.h>
#include<string.h>
#include<algorithm>
#define M 10000
using namespace std;
void maximize(int &a,int b){
	if(a < b) a = b;
}
int m[M + 5];
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int c = 1 ; c <= T ; c++){
		int n;
		int method1 , method2 , rate;
		method1 = 0 ; method2 = 0 ; rate = 0;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i++)	scanf("%d",&m[i]);
		for(int i = 1 ; i < n ; i++){
			if(m[i] > m[i + 1]) method1+=(m[i] - m[i + 1]);
			maximize(rate , m[i] - m[i + 1]);
		}
		for(int i = 1 ; i < n ; i++)
			method2+=min(rate , m[i]);
		printf("Case #%d: %d %d\n",c,method1,method2);
	}
}
