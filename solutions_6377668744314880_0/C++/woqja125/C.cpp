#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
long long gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}
struct point
{
	int x, y;
} T[3001];
struct vec2
{
	long long x, y;
	vec2(int X, int Y) :x(X), y(Y){}
};
int type(const vec2 &A)
{
	if (A.y == 0 && A.x > 0) return 0;
	else if (A.y > 0) return 1;
	else if (A.y == 0) return 2;
	else return 3;
}
bool operator<(const vec2 A, const vec2 B)
{
	int a = type(A), b = type(B);
	if (a != b) return a < b;
	return A.y*B.x - A.x*B.y < 0;
}
vec2 operator-(const vec2 A){ return vec2(-A.x, -A.y); }
vec2 getdir(point A, point B)
{
	vec2 re = vec2(A.x - B.x, A.y - B.y);
	long long g = gcd(re.x, re.y);
	if (g < 0) g = -g;
	re.x /= g;
	re.y /= g;
	return re;
}
void solve()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d%d", &T[i].x, &T[i].y);
	std::vector<vec2> V;
	for (k = 1; k <= n; k++)
	{
		for (j = 1; j <= n; j++)
		{
			if (j == k) continue;
			V.push_back(getdir(T[k], T[j]));
		}

		int max = 0;

		std::sort(V.begin(), V.end());
		j = 1;
		int c = 1;
		for (i = 0; i <n - 1; i++)
		{
			vec2 A = -V[i];
			for (; j<n - 1; j++)
			{
				if (A < V[j]) break;
				c++;
			}
			if (max < c) max = c;
			c--;
		}

		for (i = 0; i < n - 1; i++) V[i] = -V[i];
		std::sort(V.begin(), V.end());
		j = 1;
		c = 1;
		for (i = 0; i < n - 1; i++)
		{
			vec2 A = -V[i];
			for (; j < n - 1; j++)
			{
				if (A < V[j]) break;
				c++;
			}
			if (max < c) max = c;
			c--;
		}
		printf("%d\n", n-max-1);
		V.clear();
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;
}