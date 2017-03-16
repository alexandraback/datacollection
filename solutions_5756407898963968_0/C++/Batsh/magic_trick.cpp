#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <iostream>
#include <functional>
#include <sstream>
#include <numeric>

#define CLR( x , y ) ( memset( (x) , (y) , sizeof( (x) ) ) )
#define EPS 1e-9

using namespace std;

FILE *in=fopen("A.in","r");
FILE *out=fopen("A.out","w");

int n;

int main()
{
	int i,j,k,test,tests;
	fscanf(in,"%d",&tests);
	for(test=1;test<=tests;test++){
		int fa,sa,fgrid[5][5],sgrid[5][5];
		fscanf(in,"%d",&fa);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				fscanf(in,"%d",&fgrid[i][j]);
		fscanf(in,"%d",&sa);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				fscanf(in,"%d",&sgrid[i][j]);
		fa--;
		sa--;
		int fmask = 0,smask=0;
		for(i=0;i<4;i++) 
			fmask |= 1<<fgrid[fa][i];
		for(i=0;i<4;i++) 
			smask |= 1<<sgrid[sa][i];
		int x = fmask & smask;
		if (!x)
			fprintf(out,"Case #%d: Volunteer cheated!\n", test);
		else if(x&(x-1))
			fprintf(out,"Case #%d: Bad magician!\n", test);
		else {
			for(i=0;i<17;i++) {
				if((1<<i) == x) {
					x = i;
					break;
				}
			}
			fprintf(out,"Case #%d: %d\n", test, x);
		}
	}
	return 0;
}
