//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <functional>
#include <set>
using namespace std;

int main() {
	freopen("output.txt", "w", stdout);
	int t, tc = 0;
	cin>>t;
	while (tc++ < t) {
		int matrix[4][4];
		int i, j;
		int ans;
		set<int> poss;
		cin>>ans;
		for (i = 0; i < 4; i++)
			for (j = 0;j < 4; j++)
				cin>>matrix[i][j];
		for (i = 0; i < 4; i++)
			poss.insert(matrix[ans - 1][i]);
		
		cin>>ans;
		for (i = 0; i < 4; i++)
			for (j = 0;j < 4; j++)
				cin>>matrix[i][j];
		
		int counter = 0;
		int card = -1;
		for (i = 0; i < 4; i++)
			if (poss.find(matrix[ans - 1][i]) != poss.end()) {
				counter++;
				card = matrix[ans - 1][i];
			}

		
		if (counter > 1) printf("Case #%d: Bad magician!\n", tc);
		else if (counter == 1) printf("Case #%d: %d\n", tc, card);
		else printf("Case #%d: Volunteer cheated!\n", tc);
	
	}
	return 0;
}
