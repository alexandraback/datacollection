#include <stdio.h>

int Span(int a, int b, int num, int plus) {
	if (num <= a) {
		return 0;
	}
	if (num < b) {
		b = num;
	}
	return (b-a)*plus;
}

int Solve0(int r, int n) {
	int x = (r+1)/2; // +0
	int y = x + (r%2 ? 0 : 1); // +1
	int z = r; // +2
	int ans = 0;
	ans += Span(x, y, n, +1);
	ans += Span(y, z, n, +2);
	return ans;
}

int Solve1(int r, int c, int n) {
	int x = (r*c+1)/2; // +0
	int y = x + (r%2 && c%2 ? 0 : 2); // +2
	int z = r*c - (r>2 ? r-2 : 0)*(c>2 ? c-2 : 0)/2; // +3
	int w = r*c; // +4
	//printf("%d %d %d %d\n", x, y, z, w);
	int ans = 0;
	ans += Span(x, y, n, +2);
	ans += Span(y, z, n, +3);
	ans += Span(z, w, n, +4);
	return ans;
}


int Solve2(int r, int c, int n) {
	int x = (r*c)/2; // +0
	int y = x + (r%2 && c%2 ? 4 : 2); // +2
	int z = r*c - ((r>2 ? r-2 : 0)*(c>2 ? c-2 : 0)+1)/2; // +3
	int w = r*c; // +4
	//printf("%d %d %d %d\n", x, y, z, w);
	int ans = 0;
	ans += Span(x, y, n, +2);
	ans += Span(y, z, n, +3);
	ans += Span(z, w, n, +4);
	return ans;
}

void Solve() {
	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);
	int ans;
	if (r == 1) {
		ans = Solve0(c, n);
	} else if (c == 1) {
		ans = Solve0(r, n);
	} else {
		int ans1 = Solve1(r, c, n);
		int ans2 = Solve2(r, c, n);
		ans = ans1 < ans2 ? ans1 : ans2;
	}
	// int x = (r*c+1)/2;
	// int xx =((r>2 ? r-2 : 0)*(c>2 ? c-2 : 0)+1)/2; 
	// int y = ((r>2 ? r-2 : 0)*(c>2 ? c-2 : 0)+1)/2 + (r>1 ? c*2 : c) + (r>2 ? (c>1 ? (r-2)*2 : r-2) : 0);
	// int z = r*c;
	printf("%d\n", ans);
}

int main() {
	int nt;
	scanf("%d", &nt);
	for (int i=1; i<=nt; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
