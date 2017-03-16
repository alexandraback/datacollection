/*************************************************************************
    > File Name: a.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun May  8 17:28:22 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, cas;
int n;
int p[50];

int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int rest = n;
		for (int i = 0; i < n; i++)
			scanf("%d", &p[i]);
		printf("Case #%d:", ++cas);
		while (rest){
			if (rest == 2){
				rest = 0;
				int c1 = 0, c2 = 0;
				for (int i = 0; i < n; i++)
					if (p[i]){
						c1 = i;
						break;
					}
				for (int i = n-1; i >= 0; i--)
					if (p[i]){
						c2 = i;
						break;
					}
				for (int i = 0; i < p[c1]; i++)
					printf(" %c%c", c1+'A', c2+'A');
			}
			else{
				int ma = 0, mac = p[0];
				for (int i = 1; i < n; i++){
					if (p[i] > mac){
						ma = i;
						mac = p[i];
					}
				}
				p[ma] --; if (p[ma] == 0) rest--;
				printf(" %c", ma+'A');
			}
		}
		puts("");
	}
	return 0;
}
