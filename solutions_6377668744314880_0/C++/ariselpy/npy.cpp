//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <cmath>
//#include <map>
//using namespace std;
//typedef long long ll;
//int const N = 1e2 + 10, M = 1e5 + 10, inf = 1e5;
//int n, m, a[N], nd, cnt, h[M], vh[M], box[M], ik, jk, S, E;
//vector<int> prim;
//bool fg[M];
//struct Edge {
//	int next, to, c;
//} e[M];
//int aug(int x, int c) {
//	if (x == E) return c;
//	int tem = h[x], l = c;
//	for (int i = box[x]; ~i; i = e[i].next)
//		if (e[i].c && h[e[i].to] + 1 == h[x]) {
//			int d = aug(e[i].to, min(e[i].c,l));
//			e[i].c -= d, e[i^1].c += d, l -= d;
//			if (!l  ||  h[S] == N) return c - l;
//		}
//		for(int i = box[x]; ~i; i = e[i].next)
//			if(e[i].c) tem = min(tem, h[e[i].to]);
//		if (!--vh[h[x]]) h[S] = N;
//		else ++vh[h[x] = tem+1];
//		return c - l;
//}
//int SAP() {
//	int s = 0;
//	memset(h, 0, sizeof(h));
//	memset(vh, 0, sizeof(vh));
//	vh[0] = N;
//	while (h[S] < N) 
//		s += aug(S, ~0U >> 1);
//	return s;
//}
//map<int, int> cache;
//int calc(int &a, ll b) {
//	if (a % b) return 0;
//	else {
//		int ret = calc(a, b * b) * 2;
//		if (!(a % b)) {
//			a /= b;
//			ret++;
//		}
//		return ret;
//	}
//}
//int find(int a) {
//	if (cache.find(a) != cache.end()) return cache[a];
//	else return cache[a] = nd++;
//}
//void insert(int f, int t, int c) {
//	e[cnt].to = t;
//	e[cnt].c = c;
//	e[cnt].next = box[f];
//	box[f] = cnt++;
//	e[cnt].to = f;
//	e[cnt].c = 0;
//	e[cnt].next = box[t];
//	box[t] = cnt++;
//}
//void add(int a, int b, int c) {
//	if (a & 1) insert(a, find(b), c);
//	else insert(find(b), a, c);
//}
//int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	cin >> n >> m;
//	for (ll i = 2; i < inf; i++) {
//		if (fg[i]) continue;
//		prim.push_back(i);
//		for (ll j = i * i; j < inf; j += i) fg[j] = true;
//	}
//	memset(box, -1, sizeof(box));
//	nd = n * 2 + 1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		for (int j = 0; prim[j] * prim[j] <= a[i]; j++) {
//			if (a[i] % prim[j]) continue;
//			int c = calc(a[i], prim[j]);
//			add(i, prim[j], c);
//		}
//		if (a[i] != 1) add(i, a[i], 1);
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> ik >> jk;
//		if (ik & 1) swap(ik, jk);
//		insert(ik, jk + n, inf);
//	}
//	S = 0; E = nd;
//	for (int i = 1; i <= n; i += 2) insert(S, i, inf);
//	for (int i = 1; i <= n; i += 2) insert(i + n, E, inf);
//	cout << SAP() << endl;
//	return 0; 
//}