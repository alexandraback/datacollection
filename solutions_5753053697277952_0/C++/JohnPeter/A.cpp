#include <bits/stdc++.h>

using namespace std;

priority_queue<pair <int, char> > pq;

void extract() {
	printf("%c", pq.top().second);
	int num = pq.top().first-1;
	int car = pq.top().second;
	pq.pop();
	if(num==0) return;
	pq.push(make_pair(num, car));
	
}
int main() {
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);
	pair<int, int> num[30];
	int test;
	scanf("%d",&test);
	int cnt = 1;
	while(test--) {
		int n, tot = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			int x;
			scanf("%d", &x);
			tot+=x;
			pq.push(make_pair(x, 'A'+i-1));
			num[i] = make_pair(x, i-1+'A');
		}
		
		int pt = n;
		printf("Case #%d:", cnt++);
		while(tot) {
		
			printf(" ");
			if(tot%2) {
				extract();
				tot--;
			}
			else {
				extract();
				extract();
				tot-=2;
			}
			
		}
		printf("\n");
		
	}
	
	return 0;
}
