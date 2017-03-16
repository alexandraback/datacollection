#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
 
using namespace std;
 
const long long INF = 1000000007;
typedef pair <int, int> ii;

int a[5][5], b[5][5], c[18];

int main(){// freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int r=1; r<=T; r++){
		int f, s;
		scanf("%d", &f);
		memset( c, 0, sizeof( c ) );
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				scanf("%d", &a[i][j]);

		for(int i=0; i<4; i++)
			c[a[f-1][i]]++;

		scanf("%d", &s);
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				scanf("%d", &b[i][j]);

		for(int i=0; i<4; i++)
			c[b[s-1][i]]++;

		int p = -1, t = 0;
		for(int i=1; i<=16; i++){
			if( c[i] == 2 ) {
				++t;
				p = i;
			}
		}
		printf("Case #%d: ", r);

		if( t >= 2 ) puts("Bad magician!");
		else if( t == 0 ) puts("Volunteer cheated!");
		else if( t == 1 )
			printf("%d\n", p);


	}

}