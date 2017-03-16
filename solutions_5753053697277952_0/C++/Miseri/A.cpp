#include <bits/stdc++.h>

using namespace std;
// Constants and macros
#define INF 		(int)1e9
#define EPS 		1e-9
#define bitcount 	__builtin_popcount
#define gcd 		__gcd
#define forall(i,a,b) 	for(int i=a;i<b;i++)
#define pb 		push_back
#define mp		make_pair
#define MAX(a,b)	( (a)>(b) ? (a):(b))
#define MIN(a,b)	( (a)<(b) ? (a):(b))
#define s(a)		scanf("%d", &a)
#define ss(a,b)		scanf("%d %d", &a,&b)
#define sss(a,b,c)	scanf("%d %d %d", &a,&b,&c)
#define sl(a)		scanf("%I64d", &a)

int T, N, P;
priority_queue < pair<int,char> , vector< pair<int,char> >> c;

int main(){
	s(T);
	forall(i,0,T){
		s(N);
		forall(j, 0, N) {
			s(P);
			c.push(mp(P,'A'+j));
		}
		printf("Case #%d:", i+1);
		char buf = 0, buf2 = 0;
		while (!c.empty()){
			pair<int, char> k = c.top();
			c.pop();
			if (k.first ==1 && c.top().first == 1 && c.size() == 1){
				buf2 = k.second;
				break;
			}
			if (buf) {
				printf(" %c%c", buf, k.second);
				buf = 0;
			}
			else {
				buf = k.second;
			}
			k.first--;
			if (k.first >0) c.push(k);
		}
		if (buf) {
			printf(" %c", buf);
			buf = 0;
		}
		buf = c.top().second; c.pop();
		printf(" %c%c\n", buf, buf2);
	}
}
