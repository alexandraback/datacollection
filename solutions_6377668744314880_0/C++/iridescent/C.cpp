#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll eps = 1e-12;

int N;
ll X[3005], Y[3005];

pair<ll, ll> V[3005];
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
	return atan2(a.second, a.first) < atan2(b.second, b.first);
}
ll cross(pair<ll, ll> u, pair<ll, ll> v)
{
	//cout << u.first << ' ' << u.second << ' ' << v.first << ' ' << v.second << ' ' <<(u.first * v.second - u.second * v.first) <<endl;
	return (u.first * v.second - u.second * v.first);
}

int main()
{
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> X[i] >> Y[i];
		cout << "Case #" << test << ":\n";
		for(int c = 0; c < N; c++)
		{
			for(int i = 0; i < N; i++)
			{
				if(i == c) continue;
				pair<ll, ll> v(Y[i] - Y[c], X[i] - X[c]);
				if(i < c) V[i] = v;
				else V[i - 1] = v;
			}
			sort(V, V + N - 1, cmp);
			//for(int i = 0; i < N - 1; i++) cout << V[i].first << ',' << V[i].second << ' '; cout << endl;
			int r = 0;
			int m = 0;
			for(int l = 0; l < N - 1; l++)
			{
				if(r == l) r = (l + 1) % (N - 1);
				while(r != l)
				{
					r = (r + 1) % (N - 1);
					//cout << l << ' ' << r << ' ' << cross(V[l], V[r]) << endl;
					if(cross(V[l], V[r]) < 0) break;
					//cout << "r = " << r << endl;
				}
				//cout << r << ' ' << l << endl;
				if(r == l) m = N - 1;
				m = max(m, (r - l + (N - 1)) % (N - 1));
			}
			cout << N-1-m << '\n';
		}
	}
}
