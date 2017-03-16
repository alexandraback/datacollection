#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int Maxn = 1e5 + 7;
ll powMod(ll x, ll y)
{
	ll ret = 1;
	while (y)
	{
		if (y & 1) ret = ret * x % MOD;
		y >>= 1;
		x = x * x % MOD;
	}
	return ret;
}
ll jie[Maxn];
ll dao[Maxn];
void getJie()
{
	jie[0] = 1;
	dao[0] = 1;
	for (int i = 1; i < Maxn; ++i) {
		
		jie[i] = jie[i - 1] * i % MOD;
		dao[i] = dao[i - 1] * powMod(i, MOD - 2) % MOD;
	}
}
ll c(ll x, int y)
{
	return jie[x] * dao[x - y] % MOD * dao[y] % MOD;
	
}
int prim[Maxn], top;
int flag[Maxn];
void makePrim()
{
	top = 0;
	flag[1] = 1;
	for (int i = 2; i < Maxn; i++)
	{
		if (flag[i] == 0){
			prim[top++] = i;
			flag[i] = i;
		}
		for (int j = 0; j < top && prim[j] * i < Maxn; ++j) 
		{
			flag[prim[j] * i] = prim[j];
			if (i % prim[j] == 0) break;
		}
	}
}
int sign(int x)
{
	int cnt = 0;
	while (x != 1 && x)
	{
		int p = flag[x];
		x /= p;
		//while (x %p == 0) x /= p;
		if (x % p == 0) return 0;
		cnt++;
	}
	return cnt % 2 == 0 ? 1 : -1;
}
int n, m;
int main()
{
	makePrim();
	
	getJie();
	//while(scanf("%d %d", &n, &m) != EOF)
	for (n = 1; n <= 100000; ++n)
	{
		m = max(n / 2 - 1, 1);
		ll ret = 0;
		for (int i = 1; i <= n; ++i) {
			if (n % i) continue;
			int x = n / i;
			if (x < m) break;
			ret += sign(i) * c(x - 1, m - 1);
			ret %= MOD;
			//cout << ret << " " << i << endl;
		}
		if (ret < 0)printf("%d %d\n", n, int(ret));
	}
	return 0;
}

