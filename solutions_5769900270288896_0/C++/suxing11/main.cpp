#include <stdio.h>


typedef long long ll;


ll gao(ll r, ll c, ll n)
{
	ll ans, m, edge;
	
	if (r > c) m = r, r = c, c = m;
	ans = 0;
	if (r == 1)
	{
		n -= (c+1)/2;
		if (n <= 0) return ans;
		if (c % 2 == 0) ans += 1, n --;
		if (n <= 0) return ans;
		ans += n*2;
		return ans;
	}
	else if (r == 2)
	{
		n -= c;
		if (n <= 0) return ans;
		if (n <= 2) return n * 2;
		n -= 2, ans += 2*2;
		ans += n*3;
		return ans;
	}
	else // r >= 3
	{
		if ((r*c)%2 == 0)
		{
			n -= r*c/2;
			if (n <= 0) return ans;
			if (n <= 2) return n*2;
			n -= 2, ans += 2*2;
			edge = r*c-(r-2)*(c-2) - r*c/2 + (r-2)*(c-2)/2 - 2;
			if (n <= edge) {ans += n * 3; return ans;}
			n -= edge, ans += edge*3;
			ans += n*4;
			return ans;
		}
		else
		{
			ll s, l, itot, is, il, tot;
			ll ans1, ans2, corn;
			tot = r*c;
			s = r*c/2, l = tot - s;
			itot = (r-2)*(c-2);
			is = itot/2, il = itot-is;
			m = n;
			//case 1
			do{
				ans1 = 0;
				n = m;
				n -= l;
				if (n <= 0) break;
				
				edge = tot - itot - (l - il);
				
				if (n <= edge) {ans1 = n*3; break;}
				
				n -= edge;
				ans1 += edge*3;
				
				ans1 += n*4;
				
			}while(0);
			
			do{
				ans2 = 0;
				n = m;
				n -= s;
				if (n <= 0) break;
				
				corn = 4;
				if (n <= corn) { ans2 += n*2; break;}
				n -= corn, ans2 += corn*2;
				
				edge = tot-itot-(s - is)-corn;
				if (n <= edge) { ans2 += n*3; break;}
				n -= edge, ans2 += edge*3;
				
				ans2 += n*4;
			}while (0);
			if (ans1 < ans2) return ans1;
			else return ans2;
		}
	}
	
}


int main()
{
	int T, cas;
	int r, c, n;
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d%d%d", &r, &c, &n);
		printf ("Case #%d: %I64d\n", cas, gao(r,c, n));
	}
	return 0;
}
