#include <iostream>
#define LL long long

using namespace std;

LL N;
LL WSP[3005][2];
LL ODP[3005];

LL ilwek(LL x1, LL y1, LL x2, LL y2)
{
	LL ODP = x1*y2 - x2*y1;
	if (ODP < 0)
		return (-1);
	if (ODP == 0)
		return 0;
	return 1;
}
void zrob(LL K)
{
	ODP[K] = max((LL)0, N-(LL)2);
	for(int i=0; i<N; i++) // i - partner na boku
	{
		if (i == K)
			continue;
		LL akt;
		LL lewe = 0, prawe = 0;
		for(int j = 0; j < N; j++)
		{
			if (j == i || j == K)
				continue;
			akt = ilwek(WSP[i][0] - WSP[K][0], WSP[i][1] - WSP[K][1], WSP[j][0] - WSP[K][0], WSP[j][1] - WSP[K][1]);
			if (akt < (long long)0)
				lewe++;
			if (akt > (long long)0)
				prawe++;
		}
			
		lewe = min(lewe, prawe);
		ODP[K] = min(ODP[K], lewe);
	}
	
}



int main()
{
	int TEST;
	cin>>TEST;
	for(int test=1; test<=TEST; test++)
	{
		cin >> N;
		for(int i=0; i<N; i++)
			cin >> WSP[i][0] >> WSP[i][1];
		
		for(int i=0; i<N; i++)
			zrob(i);
		
		cout << "Case #" << test << ": " << endl;
		for(int i=0; i<N; i++)
			cout << ODP[i] << endl;
	}
	
}
