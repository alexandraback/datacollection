#include<bits/stdc++.h>

int MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	int nn = n*(m+1) + (n+1)*m;
	int c;
	scanf("%d", &c);
	c *= 4;
	if(c <= nn)
		return 0;
	else
		return (c - nn) ;
}

int main() {
	freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		printf("Case #%d: %d\n", i, MAIN());
	return 0;
}
