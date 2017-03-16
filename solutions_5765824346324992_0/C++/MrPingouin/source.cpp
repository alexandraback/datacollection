#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream lire("small.in", ios::in);
ofstream ecrire("out.txt", ios::out);

int pgcd(int a, int b)
{
	return b == 0 ? a : pgcd(b, a % b);
}

int ppcm(int a, int b)
{
	return (a * b) / pgcd(a,b);
}

int main()
{
	int T;
	lire >> T;
	for (int t = 1; t <= T; t++)
	{
		int B, N;
		vector<int> M(1000, 0);
		lire >> B >> N;
		for (int i = 0; i < B; i++)
			lire >> M[i];
		int p = M[0];
		int u = 0;
		for (int i = 0; i < B; i++)
			for (int j = i + 1; j < B; j++)
                        	p = ppcm(p, ppcm(M[i], M[j]));
		for (int i = 0; i < B; i++)
			u += p / M[i];
		N %= u;
		if (N == 0)
			N = u;
		vector<int> G(1000, 0);
		while (N > 1)
		{
			int v = 0;
			for (int i = 0; i < B; i++)
				if (G[i] < G[v])
					v = i;
			G[v] += M[v];
			N--;
		}
		int v = 0;
                for (int i = 0; i < B; i++)
			if (G[i] < G[v])
                        	v = i;
		ecrire << "Case #" << t << ": " << v + 1 << endl;
	}
	return 0;
}
