//#include "stdafx.h"
//#include <time.h>
//#include "ryx_bignum.h"
/*基础题。
http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=3238&messageid=1&deep=0*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int a1[5], a2[5];
int main()
{
	int t, i, j, r, ans, p;
	FILE *fi, *fo;
	fi = fopen("A-small-attempt2.in", "r");
	fo = fopen("result.txt", "wb");
	//scanf("%d", &t);
	fscanf(fi, "%d", &t);
	for(r=0; r<t; r++) {
		//scanf("%d", &ans);
		fscanf(fi, "%d", &ans);
		for(i=0; i<4; i++) {
			if (i+1 == ans) {
				for(j=0; j<4; j++)
					//scanf("%d", &a1[j]);
					fscanf(fi, "%d", &a1[j]);
			}
			else {
				for(j=0; j<4; j++)
					//scanf("%d", &a1[4]);
					fscanf(fi, "%d", &a1[4]);
			}
		}
		//scanf("%d", &ans);
		fscanf(fi, "%d", &ans);
		for(i=0; i<4; i++) {
			if (i+1 == ans) {
				for(j=0; j<4; j++)
					//scanf("%d", &a2[j]);
					fscanf(fi, "%d", &a2[j]);
			}
			else {
				for(j=0; j<4; j++)
					//scanf("%d", &a2[4]);
					fscanf(fi, "%d", &a2[4]);
			}
		}
		ans = 0;
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				if (a1[i] == a2[j]) {
					ans++;
					p = i;
					break;
				}
		if (ans == 0)
			//printf("Case #%d: Volunteer cheated!\n", r+1);
			fprintf(fo, "Case #%d: Volunteer cheated!\n", r+1);
		else if (ans == 1)
			//printf("Case #%d: %d\n", r+1, a1[p]);
			fprintf(fo, "Case #%d: %d\n", r+1, a1[p]);
		else 
			//printf("Case #%d: Bad magician!\n", r+1);
			fprintf(fo, "Case #%d: Bad magician!\n", r+1);
	}
	return 0;
}