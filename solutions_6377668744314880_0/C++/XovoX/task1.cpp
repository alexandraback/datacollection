#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
int line(int x,int y, int*X,int*Y,int j1,int j2)
{
	int x1 = X[j1];
	int x2 = X[j2];
	int y1 = Y[j1];
	int y2 = Y[j2];

	return x*(y2-y1)-y*(x2-x1)-x1*(y2-y1)+y1*(x2-x1);
}
int main()
{
	ifstream fin;
	fin.open("C-small-attempt0.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("C-small-attempt0.out");
		int T;
		fin >> T;
		for (int i = 0; i < T; i++)
		{
			int N;
			fin >>N;
			int* X = new int[N];
			int* Y = new int[N];
			int res = 0;
			for (int j = 0; j < N; j++)
			{
				int curx,cury;
				fin >> curx>>cury;
				X[j] = curx;
				Y[j] = cury;
			}
			cout << "Case #" << i + 1 << ":" << endl;
			fout << "Case #" << i + 1 << ":" << endl;
			for (int j = 0; j < N; j++)
			{
				int nn=N;
				for (int j1 = 0; j1 < N; j1++)
					for (int j2 = j1+1; j2 < N; j2++)
					{
						if (j == j1 || j == j2 || line(X[j], Y[j], X,Y, j1, j2) == 0)
						{
							int n1 = 0;
							int n2 = 0;
							for (int j3 = 0; j3 < N; j3++)
							{
								int l = line(X[j3], Y[j3], X, Y, j1, j2);
								if (l > 0) n1++;
								if (l < 0) n2++;
							}
							if (n1 < nn) nn = n1;
							if (n2 < nn) nn = n2;
						}
					}
				cout << nn << endl;
				fout << nn << endl;
			}
			delete[] X;
			delete[] Y;
		}
		fin.close();
		fout.close();
	}
	return 0;
}