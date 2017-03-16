#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int T;
int N;
priority_queue< pair<int, int> > q;
int ans[1005][2];
int ca;

int main(){
	scanf("%d", &T);
	for(int tt = 1; tt <= T; tt++){
		scanf("%d", &N);
		int in;
		for(int i = 0; i < N; i++){
			scanf("%d", &in);
			q.push(make_pair(in, i));
		}

		ca = 0;
		while(!q.empty()){
			pair<int, int> a, b;

			a = make_pair(q.top().first, q.top().second);
			q.pop();
			//printf("___%d %d : %d\n", a.first, a.second, ca);

			if(q.empty()){
				ans[ca][0] = a.second;
				a.first--;

				if(a.first > 0){
					ans[ca][1] = a.second;
					a.first--;
				} else
					ans[ca][1] = -1;

				ca++;
				if(a.first > 0)
					q.push(a);
			} else{
				b = make_pair(q.top().first, q.top().second);
				q.pop();
				ans[ca][0] = a.second;
				ans[ca][1] = b.second;

				a.first--;
				b.first--;

				if(a.first > 0)
					q.push(a);
				if(b.first > 0)
					q.push(b);

				ca++;
			}

			//printf("__%d\n", ca);
		}

		printf("Case #%d: ", tt);
		for(int i = ca - 1; i >= 0; i--){
			printf("%c", ans[i][0] + 'A');
			if(ans[i][1] != -1)
				printf("%c", ans[i][1] + 'A');

			printf(" ");
		}
		printf("\n");
	}
}