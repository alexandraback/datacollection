//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<math.h>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//#define eps 1e-4
//
//FILE *fp, *fw;
//
//struct node {
//	int idx, n;
//	double lt, t, tt;
//	//friend bool operator<(const node &a, const node &b) {
//	//	if(a.lt != b.lt) return a.lt < b.lt;
//	//	return a.idx < b.idx;
//	//}
//}p[1010];
//
//bool cmp (node a, node b) {
//	if(a.lt != b.lt) return a.lt > b.lt;
//	return a.idx > b.idx;
//}
//
//bool cmp2 (node a, node b) {
//	if(a.tt != b.tt) return a.tt < b.tt;
//	return a.idx < b.idx;
//}
//
//int imin(int a, int b) {
//	return a < b ? a : b;
//}
//
//int main() {
//	fp = fopen("H:\\GCJ\\B-small-attempt3.in", "r");
//	//fp = fopen("H:\\GCJ\\in.txt", "r");
//	fw = fopen("H:\\GCJ\\outBs3.txt", "wt");
//	int cse, i, n, m, g = 1, cur, fg;
//	double mint, l, r, mid, maxt, rt;
//	fscanf(fp, "%d", &cse);
//	while(cse--) {
//		fscanf(fp, "%d %d", &n, &m);
//		mint = 1e6;
//		for(i = 0; i < n; ++i) {
//			fscanf(fp, "%lf", &p[i].t);
//			if(p[i].t < mint) mint = p[i].t;
//		}
//		r = (m - 1) * mint + 1; l = 0;
//		while(r - l > eps) {
//			mid = (l + r) / 2;
//			cur = m - 1;
//			for(i = 0; i < n; ++i) {
//				p[i].n = int(mid / p[i].t);
//				cur -= p[i].n;
//			}
//			if(cur <= 0) r = mid;
//			else
//				l = mid;
//		}
//		cur = 0;
//		for(i = 0; i < n; ++i) {
//			p[i].idx = i + 1;
//			p[i].n = int(r / p[i].t);
//			p[i].t = p[i].t;
//			cur += p[i].n;
//			if(p[i].n) {
//				p[i].lt = (p[i].n - 1) * p[i].t;
//			}
//			p[i].tt = p[i].n * p[i].t;
//		}
//		if(cur > m - 1) {
//			while(cur > m - 1) {
//				sort(p, p + n, cmp);
//				p[0].n--;
//				p[0].lt -= p[0].t;
//				p[0].tt -= p[0].t;
//				cur--;
//				if(cur == m - 1) break;
//			}
//		}
//		sort(p, p + n, cmp2);
//		printf("%d\n", p[0].idx);
//		fprintf(fw, "Case #%d: %d\n", g++, p[0].idx);
//	}
//	fclose(fp);
//	fclose(fw);
//	system("PAUSE");
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 0x7FFFFFFF

FILE *fp, *fw;

int cnt[1000010];

int Bit(int n) {
    int c =0 ;
    for(c = 0; n; ++c) {
        n &= (n - 1);
    }
    return c;
}

int cal(int r, int c, int x) {
	int i, j, cnt = 0;
	for(i = 0; i < r; ++i) {
		for(j = 0; j < c; ++j) {
			if(!(x & (1 << (i * r + j)))) continue;
			if(i > 0 && (x & (1 << ((i - 1) * r + j)))) cnt++;
			if(j > 0 && (x & (1 << (i * r + j - 1)))) cnt++;
			if(i < r - 1 && (x & (1 << ((i + 1) * r + j)))) cnt++;
			if(j < c - 1 && (x & (1 << (i * r + j + 1)))) cnt++;
		}
	}
	return cnt / 2;
}

int main() {
	//fp = fopen("H:\\GCJ\\B-small-attempt0.in", "r");
	fp = fopen("H:\\GCJ\\in.txt", "r");
	fw = fopen("H:\\GCJ\\outBs.txt", "wt");
	int cse, i, n, m, r, c, g = 1, res, tp;
	double mint, mid, maxt, rt;
	char s[15];
	fscanf(fp, "%d", &cse);
	while(cse--) {
		fscanf(fp, "%d %d %d", &r, &c, &n);
		res = INF;
		//printf("%d %d\n", 1<<0, (1 << 7) & 255);
		for(i = 0; i < (1 << (r * c)); ++i) {
			if(Bit(i) != n) continue;
			else {
				//printf("%d\n", Bit(i));
				tp = cal(r, c, i);
				if(tp < res) res = tp;
			}
		}
		printf("Case #%d: %d\n", g, res);
		fprintf(fw, "Case #%d: %d\n", g++, res);
	}
	fclose(fp);
	fclose(fw);
	system("PAUSE");
	return 0;
}