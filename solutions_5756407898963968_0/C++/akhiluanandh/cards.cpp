#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm> 
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <string.h> 
#include <cstdlib> 
#include <limits.h> 
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <functional> 
#include <stack>
#include <queue>
using namespace std;


#define gc getchar_unlocked

int read_int(){
	register int x = 0, c = gc();
	int sign = 1;
	while(c!='-' && (c<48 || c>57) ) c = gc();
	if(c=='-')
		sign = -1, c = gc();
	while(c>=48 && c<=57) 
		x = (x<<1) + (x<<3) + c - 48, c = gc();
	return sign*x;
}

int grid[4][4];

void rd_grid(){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			grid[i][j] = read_int();
}

int main()
{
	int t = read_int();
	for(int cn=1;cn<=t;cn++){
		int g1 = read_int();
		rd_grid();
		int p1[4], p2[4];
		for(int j=0;j<4;j++){
			p1[j] = grid[g1-1][j];
		}
		int g2 = read_int();
		rd_grid();
		for(int j=0;j<4;j++){
			p2[j] = grid[g2-1][j];
		}
		int ans = -1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(p1[i]==p2[j]){
					if(ans==-1)
						ans = p1[i];
					else ans = 0;
				}
			}
		}
		printf("Case #%d: ",cn);
		if(ans==-1)
			printf("Volunteer cheated!\n");
		else if(ans==0)
			printf("Bad magician!\n");
		else printf("%d\n",ans);
	}
	return 0;
}
