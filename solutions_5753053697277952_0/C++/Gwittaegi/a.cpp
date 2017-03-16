#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tc = 0;++tc <= t;tc) {

		int n,p,st=0;
		scanf("%d", &n);
		priority_queue<pair<int, int> >pq;
		for (int i = 0;i < n;++i) {
			scanf("%d", &p);
			pq.push(make_pair(p, i));
			st += p;
		}

		printf("Case #%d:", tc);
		while(st) {
			pair<int, int>t1 = pq.top();
			pq.pop();
			pair<int, int>t2 = pq.top();
			pq.pop();
			if (st == 3) {
				printf(" %c", 'A' + t1.second);
				--t1.first;
				--st;
			}
			else if (t1.first > t2.first) {
				printf(" %c%c", 'A' + t1.second, 'A' + t1.second);
				t1.first -= 2;
				st -= 2;
			}
			else {
				printf(" %c%c", 'A' + t1.second, 'A' + t2.second);
				--t1.first;
				--t2.first;
				st -= 2;
			}
			pq.push(t1);
			pq.push(t2);
		}
		printf("\n");

	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}