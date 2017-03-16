#include <stdio.h>


int gcd(int a, int b){return a%b?gcd(b, a%b) : b;}
int LCM(int a, int b){return a / gcd(a, b) * b;}

int main()
{
	int T, cas;
	int i, j;
	int lcm, b, n;
	int bb[10], t[10];
	int mod;
	int minv;
	int ans;
	
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d%d", &b, &n);
		for (i = 0; i < b; i++)
			scanf ("%d", &bb[i]);
		lcm = 1;
		for (i = 0; i < b; i++)
			lcm = LCM(lcm, bb[i]);
		mod = 0;
		for (i = 0; i < b; i++)
			mod += lcm / bb[i];
		n %= mod;
		if (n == 0) n += mod;
		for (i = 0; i < b; i++) t[i] = 0;
		for (i = 0; i < n; i++)
		{
			minv = 0;
			for (j = 1; j < b; j++)
				if (t[j] < t[minv]) minv = j;
			ans = minv;
			t[minv] += bb[minv];
		}
		printf ("Case #%d: %d\n", cas, ans+1);
	}
	return 0;
}
