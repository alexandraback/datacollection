#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

int r1, r2, a1[4][4], a2[4][4];

bool check(int a[4][4], int x, int r)
{
	r--;
	for(int i = 0; i < 4; i++) if (a[r][i] == x) return true;
	return false;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%d", &r1);
		for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) scanf("%d", &a1[i][j]);
			
		scanf("%d", &r2);
		for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) scanf("%d", &a2[i][j]);
			
		int choice = -1;
		for(int i = 1; i <= 16; i++)
		{
			if (check(a1, i, r1) && check(a2, i, r2))
			{
				if (choice == -1) choice = i;
				else
					choice = -2;
			}
		}

		if (choice == -1) puts("Volunteer cheated!");
		else 
			if (choice == -2) puts("Bad magician!");
		else printf("%d\n", choice);
	}
	return 0;
}