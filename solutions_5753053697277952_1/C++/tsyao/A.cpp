#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int T, n, x;

struct Node {
	int c, val;
	bool operator < (const Node &B) const {
		return val < B.val;
	}
};


priority_queue<Node> q;

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++) {
        printf("Case #%d:",cas);
        scanf("%d",&n);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
			scanf("%d",&x);
			cnt += x;
			q.push((Node){i,x});
        }
        n = cnt;
		while(!q.empty()) {
			Node a = q.top(); q.pop();
			Node b = q.top(); q.pop();
			if(!q.empty()) {
				int x = a.val, y = b.val;
				int z = q.top().val;
				if(z*2 > (n-2)) {
					printf(" %c",a.c+'A');
					a.val--;
					n -= 1;
					if(a.val) q.push(a);
					q.push(b);
				} else {
					printf(" %c%c",a.c+'A',b.c+'A');
					a.val--;
					b.val--;
					n -= 2;
					if(a.val) q.push(a);
					if(b.val) q.push(b);
				}
			} else {
				printf(" %c%c",a.c+'A',b.c+'A');
				a.val--;
				b.val--;
				n -= 2;
				if(a.val) q.push(a);
				if(b.val) q.push(b);
			}
		}
		puts("");
	}
	return 0;
}
