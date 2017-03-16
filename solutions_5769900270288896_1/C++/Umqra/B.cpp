#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};
const int INF = (int)1e9 + 10;
const int V = (int)1e5 + 10;
const int SZ = (int)1e4 + 10;
const int E = 5 * V;

struct Edge
{
	int a, b, cap, flow;
	Edge () {}
	Edge (int _a, int _b, int _cap, int _flow) : a(_a), b(_b), cap(_cap), flow(_flow) {}
};

vector <int> edgeNum[4][SZ];
Edge listEdge[E];
int dist[V];
int q[V];
int ptr[V];
vector <int> g[V];
int indE = 0;
int mv = 0;

void addEdge(int a, int b, int cap)
{
	g[a].push_back(indE);
	listEdge[indE++] = Edge(a, b, cap, 0);
	g[b].push_back(indE);
	listEdge[indE++] = Edge(b, a, 0, 0);
}

bool bfs(int source, int sink)
{
	fill(dist, dist + mv, INF);
	int topQ = 0;
	q[topQ++] = source;
	dist[source] = 0;
	for (int i = 0; i < topQ; i++)
	{
		int v = q[i];
		for (int eid : g[v])
		{
			int to = listEdge[eid].b;
			if (listEdge[eid].cap - listEdge[eid].flow > 0 && dist[to] > dist[v] + 1)
			{
				dist[to] = dist[v] + 1;
				q[topQ++] = to;
			}
		}
	}
	return dist[sink] != INF;
}

int dfs(int v, int en, int flow)
{
	if (v == en)
		return flow;
	for (int &i = ptr[v]; i < (int)g[v].size(); i++)
	{
		int eid = g[v][i];
		Edge e = listEdge[eid];
		if (e.cap - e.flow > 0 && dist[e.b] == dist[v] + 1)
		{
			int tmp = dfs(e.b, en, min(flow, e.cap - e.flow));
			if (tmp > 0)
			{
				listEdge[eid].flow += tmp;
				listEdge[eid ^ 1].flow -= tmp;
				return tmp;
			}
		}
	}
	return 0;
}

int maxFlow(int source, int sink)
{
	int maxFlow = 0;
	while (bfs(source, sink))
	{
		int flow = 0;
		fill(ptr, ptr + mv, 0);
		while ((flow = dfs(source, sink, INF)) != 0)
			maxFlow += flow;
	}
	return maxFlow;
}

bool checkCoord(int x, int y, int mx, int my)
{
	return x >= 0 && y >= 0 && x < mx && y < my;
}

void solve()
{
	int r, c, n;
	scanf("%d%d%d", &r, &c, &n);

	for (int i = 0; i < mv; i++)
		g[i].clear();
	mv = 0;
	for (int i = 0; i < r; i++)
		for (int dir = 0; dir < 4; dir++)
		{
			edgeNum[dir][i].resize(c);
			for (int s = 0; s < c; s++)
				edgeNum[dir][i][s] = -1;
		}
	for (int i = 0; i < r; i++)
		for (int s = 0; s < c; s++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + DX[dir];
				int ny = s + DY[dir];
				if (checkCoord(nx, ny, r, c) && edgeNum[(dir + 2) % 4][nx][ny] != -1)
					edgeNum[dir][i][s] = edgeNum[(dir + 2) % 4][nx][ny];
				else
					edgeNum[dir][i][s] = mv++;
			}
		}
	int edgeCount = mv;

	int source = mv++;
	int sink = mv++;
	int middle = mv++;
	addEdge(source, middle, 4 * n);
	for (int i = 0; i < r; i++)
		for (int s = 0; s < c; s++)
		{
			int cur = mv++;
			addEdge(middle, cur, 4);
			for (int dir = 0; dir < 4; dir++)
				addEdge(cur, edgeNum[dir][i][s], 1);
		}

	for (int i = 0; i < edgeCount; i++)
		addEdge(i, sink, 1);
	int flow = maxFlow(source, sink);
	printf("%d\n", 4 * n - flow);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
