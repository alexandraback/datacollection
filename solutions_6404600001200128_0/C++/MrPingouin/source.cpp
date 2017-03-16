#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


ifstream lire("small.in", ios::in);
ofstream ecrire("out.txt", ios::out);

int main()
{
	int T;
	lire >> T;
	for (int t = 1; t <= T; t++)
	{
		int N;
		int y = 0, r = 0, z = 0;
		int m[1000];
		lire >> N;
		for (int i = 0; i < N; i++)
			lire >> m[i];
		for (int i = 0; i < N - 1; i++)
			if (m[i] > m[i + 1])
				y += m[i] - m[i + 1];
		for (int i = 0; i < N - 1; i++)
                        if (m[i] > m[i + 1])
                                r = max(r, m[i] - m[i + 1]);
		for (int i = 0; i < N - 1; i++)
                	z += min(r, m[i]);
		ecrire << "Case #" << t << ": " << y << " " << z << endl;
	}
	return 0;
}
