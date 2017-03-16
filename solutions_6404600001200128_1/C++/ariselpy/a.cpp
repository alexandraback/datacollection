//#include <cstring>
//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int const N = 1e4 + 10, M = N * 100;
//int n, m, l[N], r[N], v[N], cnt, a[N], all[N * 2], root[N], ls[M], rs[M], crt, sum[M], ltree[20], rtree[20], lc, rc;
//char q[N][2];
//int ans(int k, int l = 1, int r = cnt) {
//	if (l == r) return l;
//	int lsum = 0, rsum = 0, delta, mid = (l + r) >> 1;
//	for (int i = 0; i < lc; i++) lsum += sum[ls[ltree[i]]];
//	for (int i = 0; i < rc; i++) rsum += sum[ls[rtree[i]]];
//	if ((delta = rsum - lsum) >= k) {
//		for (int i = 0; i < lc; i++) ltree[i] = ls[ltree[i]];
//		for (int i = 0; i < rc; i++) rtree[i] = ls[rtree[i]];
//		return ans(k, l, mid);
//	} else {
//		for (int i = 0; i < lc; i++) ltree[i] = rs[ltree[i]];
//		for (int i = 0; i < rc; i++) rtree[i] = rs[rtree[i]];
//		return ans(k - delta, mid + 1, r);
//	}
//}
//int ask(int l, int r, int k) {
//	lc = rc = 0;
//	for (; l > 0; l -= l & -l) ltree[lc++] = root[l];
//	for (; r > 0; r -= r & -r) rtree[rc++] = root[r];
//	return ans(k);
//}
//void insert(int p, int v, int &rt, int l = 1, int r = cnt) {
//	if (!rt) rt = ++crt;
//	sum[rt] += v;
//	if (l == r) return;
//	int mid = (l + r) >> 1;
//	if (p <= mid) insert(p, v, ls[rt], l, mid);
//	else insert(p, v, rs[rt], mid + 1, r);
//}
//void update(int pos, int val, int fg) {
//	for (; pos <= n; pos += pos & -pos)
//		insert(val, fg, root[pos]);
//}
//int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", a + i);
//		all[cnt++] = a[i];
//	}
//	for (int i = 0; i < m; i++) {
//		scanf("%s%d%d", q[i], &l[i], &r[i]);
//		if (q[i][0] == 'Q') scanf("%d", &v[i]);
//		else all[cnt++] = r[i];
//		
//	}
//	sort(all, all + cnt);
//	cnt = unique(all, all + cnt) - all;
//	for (int i = 0; i < n; i++) {
//		a[i] = lower_bound(all, all + cnt, a[i]) - all + 1;
//		update(i + 1, a[i], 1);
//	}
//	for (int i = 0; i < m; i++) {
//		if (q[i][0] == 'Q') printf("%d\n", all[ask(l[i] - 1, r[i], v[i]) - 1]);
//		else {
//			int val = lower_bound(all, all + cnt, r[i]) - all + 1;
//			update(l[i], a[l[i] - 1], -1);
//			a[l[i] - 1] = val;
//			update(l[i], a[l[i] - 1], 1);
//		}
//	}
//	return 0;
//}