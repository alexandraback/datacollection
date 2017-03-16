// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("vstup.txt", "r", stdin);
freopen("vystup.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	int r, c, n;
	int S;
	int rslt;
	for (int t = 1; t <= T; t++){
		scanf("%d %d %d", &r, &c, &n);
		rslt = (r - 1)*c + (c - 1)*r;
		S = r*c;
		if (n <= (S + 1) / 2){ 
			rslt = 0;
		}
		else if (min(r, c) == 1){
			int volnych = S - n;
			rslt -= 2 * volnych;
		}
		else{
			int volnych = S - n;
			if (volnych == 0){}
			else if (volnych <= ((r - 2)*(c - 2) + 1) / 2){
				rslt -= 4 * volnych;
			}
			else  {
				int rslt1 = rslt;
				int volnych1 = volnych;
				int rslt2 = rslt;
				int volnych2 = volnych;
				rslt1 -= 4 * (((r - 2)*(c - 2) + 1) / 2);
				volnych1 -= ((r - 2)*(c - 2)+1) / 2;
				rslt1 -= 3 * volnych1;
				if (volnych1 == (2*r+2*c+1-4)/2){
					if (r % 2 == 1 && c % 2 == 1){ rslt1 += 4; }
					else{ rslt1 += 2; }
				}
				if (volnych1 == (2 * r + 2 * c + 1-4) / 2 - 1){
					if (r % 2 == 1 && c % 2 == 1){ rslt1 += 3; }
					else{ rslt1 += 1; }
				}
				if (volnych1 == (2 * r + 2 * c + 1-4) / 2 - 2){
					if (r % 2 == 1 && c % 2 == 1){ rslt1 += 2; }
				}
				if (volnych1 == (2 * r + 2 * c + 1-4) / 2 - 3){
					if (r % 2 == 1 && c % 2 == 1){ rslt1 += 1; }
				}


				rslt2 -= 4 * (((r - 2)*(c - 2)) / 2);
				volnych2 -= ((r - 2)*(c - 2)) / 2;
				rslt2 -= 3 * volnych2;
				if (volnych2 == (2 * r + 2 * c -4) / 2){
					if (r % 2 == 1 && c % 2 == 1){ rslt2 += 4; }
					else{ rslt2 += 2; }
				}
				if (volnych2 == (2 * r + 2 * c -4) / 2 - 1){
					if (r % 2 == 1 && c % 2 == 1){ rslt2 += 3; }
					else{ rslt2 += 1; }
				}
				if (volnych2 == (2 * r + 2 * c -4) / 2 - 2){
					if (r % 2 == 1 && c % 2 == 1){ rslt2 += 2; }
				}
				if (volnych2 == (2 * r + 2 * c -4) / 2 - 3){
					if (r % 2 == 1 && c % 2 == 1){ rslt2 += 1; }
				}

				rslt = min(rslt1, rslt2);
			}
		}
		printf("Case #%d: %d\n", t, rslt);
	}
	return 0;
}

