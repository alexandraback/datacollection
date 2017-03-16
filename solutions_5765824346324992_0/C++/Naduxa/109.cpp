#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int gcd(int a, int b)
{
	if (a == 0) return b;
	else return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		int b;
		scanf("%d", &b);
		int n;
		scanf("%d", &n);
		vector <int> g(b);
		for (int i = 0; i < b; i++)
		{
			scanf("%d", &g[i]);
		}
		if (b == 1)
		{
			cout << "Case #" << q + 1 << ": " << 1 << endl;
			continue;
		}

		/*int G = g[0];
		int L = g[0];
		for (int i = 1; i < b; i++)
		{
			G = gcd(G, g[i]);
			L *= g[i];
		} 

		L /= G;
		   */
		int mod = 0;
		vector <int> t(b, 0);
		vector <int> ANS;
		int ans = 0;
		for (int i = 0; i < n ; i++)
		{
			int min = 1e9;
			int idx = -1;
			bool fl = true;
			for (int j = 0; j < b; j++)
			{
				if (j != 0)
				{
					if (t[j] != t[j - 1]) fl = false;
				}
				if (t[j] < min)
				{
					min = t[j];
					idx = j;
				}
			}
			t[idx] += g[idx];
			ANS.push_back(idx);
			if (fl && i != 0) break;
			mod++;
		}

		//cout << "mod = " << mod << endl;
		cout << "Case #" << q + 1 << ": " << ANS[(n % mod - 1 + mod) % mod]  + 1 << endl;
	}
	return 0;
}