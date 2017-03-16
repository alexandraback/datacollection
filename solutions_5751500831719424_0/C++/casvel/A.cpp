#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define MP make_pair
#define INF (1<<30)

using namespace std;

typedef pair <int, int> ii;

vector <int> it[105];
string w[105];
int N;

bool revisa()
{
	int tam = it[0].size();

	For(i, 0, N)
		if (it[i].size() != tam)
			return false;

	For(i, 0, it[0].size())
		For(j, 0, N)
			if (w[j][it[j][i]] != w[0][it[0][i]])
				return false;

	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	int caso = 1;
	while (T--)
	{
		scanf("%d", &N);

		For(i, 0, N)
			cin >> w[i];

		For(i, 0, N)
		{
			it[i].clear();

			int j = 0;
			while (j < w[i].size())
			{
				it[i].push_back(j);
				while (j < w[i].size() and w[i][j] == w[i][it[i][it[i].size()-1]])
					j++;
			}
		}

		/*For(i, 0, N)
		{
			printf("palabra: %d\n", i);
			For(j, 0, it[i].size())
				printf("%d ", it[i][j]);
			printf("\n");
		}*/

		printf("Case #%d: ", caso++);
		if (revisa())
		{
			int res = 0;
			For(i, 0, it[0].size())
			{
				int best_letra = INF;
				For(k, 1, 101)
				{
					int aux = 0;
					For(j, 0, N)
					{
						int num_let = i == it[0].size()-1 ? w[j].size() - it[j][i] : it[j][i+1] - it[j][i];
						aux += abs(num_let - k);
					}

					best_letra = min(best_letra, aux);
				}

				//printf("%c: %d\n", w[0][it[0][i]], best_letra);
				res += best_letra;
			}

			printf("%d\n", res);
		}
		else
			printf("Fegla Won\n");
	}

	return 0;
}