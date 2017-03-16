
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define DBG(X) 
char tab[120][120];

int main()
{
	
	int t;
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		int n;
		scanf("%d", &n);
		int sas[256];
		memset(sas,0,sizeof(sas));
		int r = 0;
		DBG(cout << endl << endl;)
			int SK = 0;		
			char S[120];
			int ile[120][120];
			memset(ile,0,sizeof(ile));
		for (int i = 0; i < n; i++)
		{
			scanf("%s", tab[i]);
			DBG(cout << tab[i] << endl;)
			
			
		
			if (r == -1) continue;

			if (i == 0)
			{
				int j = 0;
				memset(S,0,sizeof(S));
				while (tab[i][j])
				{
					char pop = tab[i][j];
					S[SK] = pop;
					while (pop == tab[i][j])
					{
						j++;
						ile[i][SK]++;
					}
					SK++;
				}


			
			}
			else
			{
				char S2[120];
				int ile2[120];
				memset(S2,0,sizeof(S2));
				int k = 0;
				int j = 0;
				while (tab[i][j])
				{
					char pop = tab[i][j];
					S2[k] = pop;
					while (pop == tab[i][j])
					{
						j++;
						ile[i][k]++;
					}
					k++;
				}
				if (k != SK)
				{
					r = -1;
					DBG(cout << "Size wrong" << SK << " " << k << endl;)
					continue;
					
				}
				for (int j = 0; j < SK; j++)
				{
					if (S[j] != S2[j])
					{
						DBG(cout << "Sign wrong" << endl;)
						r = -1;
						break;
					}
				}
				if (r == -1)
				continue;
				
				
			}
			//				if (r == -1)
			//	break;
			
		}
		if (r != -1)
		{
			for (int j = 0; j < SK; j++)
			{
				int m = -1;
				vector<int> X;
				for (int i = 0; i < n; i++)
				{
					X.push_back(ile[i][j]);
				}
				sort(X.begin(), X.end());

				int med = X[n / 2];
				int best = 0;
				int best2 = 0;

				for (int i = 0; i < n; i++)
				best += fabs(X[i] - med);

				med = X[n / 2 - 1];
				for (int i = 0; i < n; i++)
				best2 += fabs(X[i] - med);
				
				r += min(best, best2);

			}
			
		}
		if (r != -1)
		cout << "Case #" << z << ": " << r << endl;
		else
		cout << "Case #" << z << ": Fegla Won" << endl;
	}
	
	return 0;
}
