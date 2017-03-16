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

char inp[105][105];
int p[105];

int main(){
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.out", "w");
	int T;
	fscanf(fin, "%d", &T);
	for(int i=1; i <= T; ++i){
		int N;
		bool lost=0;
		long long ans=0;
		fscanf(fin, "%d", &N);
		for(int j=0; j < N; ++j){
			fscanf(fin, "%s", inp[j]);
			p[j]=0;
		}
		for(int k=0; inp[0][k]; ++k){
			if(k && inp[0][k] == inp[0][k-1])
				continue;
			char c = inp[0][k];
			vector<int> occur;
			for(int j=0; j < N; ++j){
				occur.push_back(0);
				while(inp[j][p[j]] == c){
					++occur[j];
					++p[j];
				}
			}
			sort(occur.begin(), occur.end());
			if(occur[0] == 0){
				lost=1;
				break;
			}
			int mid=occur[N/2];
			for(int j=0; j < N; ++j)
				ans += abs(occur[j]-mid);
		}
		for(int j=0; j < N; ++j){
			if(inp[j][p[j]]){
				lost=1;
				break;
			}
		}
		if(lost){
			fprintf(fout, "Case #%d: Fegla Won\n", i);
		}
		else{
			fprintf(fout, "Case #%d: %lld\n", i, ans);
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
