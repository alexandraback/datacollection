#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct Node
{
	int size, x;
};
bool operator< (Node a, Node b)
{
	return a.size < b.size;
}
priority_queue<Node> h;

int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int Case = 0;
	while (T --)
	{
		++ Case;
		int n, sum = 0;
		Node cur;
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i)
		{
			int x;
			scanf("%d", &x);
			cur.size = x, cur.x = i;
			h.push(cur);
			sum += x;
		}
		printf("Case #%d: ", Case);
		while (!h.empty())
		{
			Node Mx = h.top(); h.pop();
			if (h.empty())
			{
				printf("%c ", 'A' + Mx.x);
				Mx.size --;
				sum --;
				if (Mx.size) h.push(Mx);
				continue;
			}
			Node sMx = h.top(); h.pop();
			if (Mx.size == sMx.size && Mx.size + sMx.size == sum)
			{
				printf("%c%c ", 'A' + Mx.x, 'A' + sMx.x);
				Mx.size --;
				sMx.size --;
				if (Mx.size) h.push(Mx);
				if (sMx.size) h.push(sMx);
				sum -= 2;
			}
			else 
			{
				printf("%c ", 'A' + Mx.x);
				Mx.size --;
				sum --;
				if (Mx.size) h.push(Mx);
				h.push(sMx);
			}
		}
		puts("");
	}
}