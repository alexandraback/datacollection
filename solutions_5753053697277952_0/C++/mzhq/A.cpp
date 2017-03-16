#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

struct node{
	int x, num;
	bool operator < (const node &b)const{
		return num < b.num;
	}
};
priority_queue <node> pq;
int n, m;

int main() {
	int T, num;

	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	For(cas, T) {
		n = 0;
		scanf("%d", &m);
		For(i, m) {
			scanf("%d", &num);
			pq.push((node){i, num});
			n += num;
		}
		printf("Case #%d:", cas + 1);
		while(1) {
			node c1 = pq.top();	pq.pop();
			node c2 = pq.top(); pq.pop();
			if(!c1.num) break;
			if(c1.num >= 2 && (c1.num - 2) * 2 <= n - 2 && c2.num * 2 <= n - 2) {
				printf(" %c%c", c1.x + 'A', c1.x + 'A');
				c1.num -= 2;
				n -= 2;
			}
			else if(c1.num >= 1 && (c1.num - 1) * 2 <= n - 1 && c2.num * 2 <= n - 1) {
				printf(" %c", c1.x + 'A');
				c1.num--;
				n--;
			}
			else {
				printf(" %c%c", c1.x + 'A', c2.x + 'A');
				c1.num--, c2.num--;
				n -= 2;
			}

			pq.push(c1);
			pq.push(c2);
		}
		puts("");
	}
	return 0;
}
