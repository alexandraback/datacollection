#include<cstdio>
#include<queue>

using namespace std;

#define N 30

int n, tc;
int data[N];
priority_queue<pair<int, int> > pq;
int main(){
	int i,j,k;
	scanf("%d", &tc);
	for(int tcc = 1; tcc<=tc; tcc++){
		scanf("%d", &n);
		int m = 0;
		for(i = 0; i < n;i++) {
			scanf("%d", &data[i]);
			pq.push(make_pair(data[i], i));
			m+=data[i];
		}
		printf("Case #%d: ", tcc);
		pair<int, int> a;
		while(m>0){
			//printf("pq: %d\n", pq.size());
			a=pq.top();
			//printf("%d %d\n", a.first, a.second);
			pq.pop();
			printf("%c", a.second+'A');
			m--;
			a.first--;
			pq.push(a);
			a=pq.top();
			pq.pop();
			if (pq.top().first * 2 > m-1) {
				pq.push(a);
				printf(" ");
				continue;
			}
			printf("%c ", 'A'+a.second);
			a.first--;
			m--;
			pq.push(a);
		}
		printf("\n");
	}
	return 0;
}
