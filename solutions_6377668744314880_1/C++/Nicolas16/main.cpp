#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int N;
int X[4000], Y[4000];
int best[4000];

vector<double> angle;
double remember[4000];

int countminus(double x) // how many < x in angle?
{
	int a = 0;
	int b = angle.size()-1;
	int c;
	double y;
	// Cherche la plus grande valeur < x
	while(a < b)
	{
		c = (a+b+1)/2;
		y = angle[c];
		if(y >= x - 0.000000001)
		{
			b = c-1;
		}
		else a = c;
	}
	if(angle[a] >= x-0.000000001) a--;
	return a+1;
}

int countplus(double x) // how many > x in angle?
{
	int a = 0;
	int b = angle.size()-1;
	int c;
	double y;
	// Cherche la plus grande valeur < x
	while(a < b)
	{
		c = (a+b)/2;
		y = angle[c];
		if(y <= x + 0.000000001)
		{
			a = c+1;
		}
		else b = c;
	}
	if(angle[b] <= x+0.000000001) b++;
	return angle.size() - b;
}

int compare(int a, int b, int c)
{
	// Compare vectors ab and ac
	long long int e1 = X[b]-X[a];
	long long int e2 = Y[b]-Y[a];

	long long int f1 = X[c]-X[a];
	long long int f2 = Y[c]-Y[a];

	long long int res = e1*f2-e2*f1;
	if(res == 0) return 0;
	else if(res < 0) return 1;
	else return 2;
}

int main()
{
	int T;

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d:\n", t);

		scanf("%d", &N);

		for(int i = 0; i < N; i++)
		{
			scanf("%d %d\n", &X[i], &Y[i]);
			best[i] = 10000;
		}

		for(int i = 0; i < N; i++)
		{
			fprintf(stderr, "%d\n", i);
			angle.clear();
			for(int j = 0; j < N; j++)
			{
				int a = X[j]-X[i];
				int b = Y[j]-Y[i];
				double value;
				if(i != j)
				{
					if(a > 0)
					{
						value = atan((double)b/(double)a);
						if(value < 0) value += 4*acos(0);
					}
					else if(a == 0)
					{
						if(b > 0) value = acos(0);
						else value = 3*acos(0);
					}
					else
					{
						value = atan((double)b/(double)a) + 2 * acos(0);
					}

					remember[j] = value;
					angle.push_back(value);
				}
			}

			sort(angle.begin(), angle.end());

			for(int j = 0; j < N; j++)
			{
				if(i != j)
				{
					double angle0 = remember[j];
					int result;
					// Search how many in ]angle0, angle0+PI[.
					if(angle0 < 2*acos(0)+0.000000001)
					{
						// All - those <= angle0 - those >= angle0+PI
						// ALL - (ALL-those > angle0) - (ALL-those < angle0+PI)
						result = countplus(angle0) + countminus(angle0+2*acos(0)) - (N-1);
					}
					else
					{
						result = countplus(angle0) + countminus(angle0-2*acos(0));
					}
					best[j] = min(best[j], result);

					// Search how many in ]angle0-PI, angle0[.
					if(angle0 > 2*acos(0)-0.000000001)
					{
						// All - those <= angle0-PI - those >= angle0
						// ALL - (ALL-those > angle0-PI) - (ALL-those < angle0)
						result = countplus(angle0-2*acos(0)) + countminus(angle0) - (N-1);
					}
					else
					{
						result = countplus(angle0+2*acos(0)) + countminus(angle0);
					}
					best[j] = min(best[j], result);
				}
			}
		}


		if(N == 1) best[0] = 0;

		for(int i = 0; i < N; i++) printf("%d\n", best[i]);

	}

	return 0;
}
