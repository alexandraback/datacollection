#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int field[2][4][4];

int main(){
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");
	int T;
	fscanf(fin, "%d", &T);
	int tN=0;
	while(T--){
		++tN;
		int p[2];
		for(int i=0; i < 2; ++i){
			fscanf(fin, "%d", p+i);
			for(int j=0; j < 4; ++j)
				for(int k=0; k < 4; ++k)
					fscanf(fin, "%d", field[i][j]+k);
		}
		vector<int> ans;
		for(int i=1; i <= 16; ++i){
			bool OK=1;
			for(int j=0; j < 2; ++j){
				bool ok=0;
				for(int k=0; k < 4; ++k)
					if(field[j][p[j]-1][k] == i)
						ok=1;
				if(!ok){
					OK=0;
				}
			}
			if(OK)
				ans.push_back(i);
		}
		if(ans.size() > 1)
			fprintf(fout, "Case #%d: Bad magician!\n", tN);
		else if(ans.empty())
			fprintf(fout, "Case #%d: Volunteer cheated!\n", tN);
		else
			fprintf(fout, "Case #%d: %d\n", tN, ans[0]);	
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
