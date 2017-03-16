#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define forn(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)

using namespace std;
priority_queue< pair<int,char> > pq;


int main(){
	int testc,n;
	int sum = 0;
	scanf("%d", &testc);

	rep(tc, testc){
		scanf("%d", &n);	
		printf("Case #%d: ", tc+1);
		rep(i,n){
			char c = 'A' + i;
			int pocet;
			scanf("%d", &pocet);
			sum += pocet;
			pq.push({pocet,c});
		}
		if(sum%2 == 1){
			int pocet = pq.top().F;
			char znak = pq.top().S;
			pq.pop();
			pocet -= 1;
			printf("%c ", znak);
			if(pocet > 0)
				pq.push({pocet,znak});
			sum -= 1;
		}
		while(sum > 0){
			int pocet1 = pq.top().F;
			char znak1 = pq.top().S;
			pq.pop();
			pocet1 -= 1;
			if(pocet1 > 0)
				pq.push({pocet1,znak1});
			int pocet2 = pq.top().F;
			char znak2 = pq.top().S;
			pq.pop();
			pocet2 -= 1;
			if(pocet2 > 0)
				pq.push({pocet2,znak2});
			sum-=2;
			printf("%c%c", znak1,znak2);
			if(sum >= 0) printf(" ");
			if(sum == 0) printf("\n");
		}
	}
	return 0;
}
