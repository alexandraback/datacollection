#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#define FOR(i,p,k) for(int i = (p);i<(k);i++)
typedef long long int LL;
using namespace std;

int Tab[2][5][5];
int n;

void dane()
{
	cin>>n;
	FOR(i,0,n)
	{
		int a,b;
		cin>>a;
		FOR(r,0,4)
			FOR(c,0,4)
				cin>>Tab[0][r][c];
		cin>>b;
		FOR(r,0,4)
			FOR(c,0,4)
				cin>>Tab[1][r][c];
		int powt = 0,kto;
		FOR(c,0,4)
			FOR(c2,0,4)
				if (Tab[0][a-1][c]==Tab[1][b-1][c2])
					powt++,kto=Tab[0][a-1][c];
		printf("Case #%d: ",i+1);		
		if(powt==1)
			printf("%d\n",kto);
		else if(powt==0)
			printf("Volunteer cheated!\n");
		else
			printf("Bad magician!\n");	
	}
}

int main()
{
	dane();
	return 0;
}
