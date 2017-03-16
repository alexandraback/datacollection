#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define VI vector<int>

int main()
	{
	int TC;
	cin >> TC;
	for( int tc = 1; tc < TC+1; ++tc )
		{
		int t1[4][4], t2[4][4];
		int a1, a2;

		VI cnt(17,0);

		cin >> a1; --a1;
		FOR(i,0,4) FOR(j,0,4) cin >> t1[i][j];
		cin >> a2; --a2;
		FOR(i,0,4) FOR(j,0,4) cin >> t2[i][j];
			
		FOR(i,0,4) ++cnt[t1[a1][i]];
		FOR(i,0,4) ++cnt[t2[a2][i]];
	
		int result = -1;
		int fit = 0;

		FOR(i,1,17) if( cnt[i] == 2 )
			{ result = i; ++fit; }
		
		//FOR(i,1,17) cout << cnt[i] << " ";
		//cout << endl;

		if ( fit == 0 )
			printf("Case #%d: Volunteer cheated!\n",tc,result);	
		else if (fit > 1 )
			printf("Case #%d: Bad magician!\n",tc,result);	
		else
			printf("Case #%d: %d\n",tc,result);
		}	
	return 0;
	}
