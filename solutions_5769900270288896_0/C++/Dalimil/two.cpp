#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;

int r,c,n; 

int countWalls(vector<vector<int> > &v){
	int ns = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c-1;j++){
			if(v[i][j] == 1 && v[i][j+1] == 1){
				ns++;
			}
		}
	}
	for(int i=0;i<r-1;i++){
		for(int j=0;j<c;j++){
			if(v[i][j] == 1 && v[i+1][j] == 1){
				ns++;
			}
		}
	}

	return ns;
}
int main(){
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++){
		scanf("%d %d %d", &r, &c, &n);

		vector<vector<int> > v(r, vector<int>(c, 0));

		int ans = r*c *10;

		int x = r*c;
		for(int i=0;i<(2<<x);i++){
			int s =0;
			for(int j=0;j<x;j++){
				if(i & (1<<j)){
					v[j/c][j%c] = 1;
					s++;
				}
			}
			if(s == n){
				ans = min(ans, countWalls(v));
			}
			for(int j=0;j<x;j++){
				v[j/c][j%c] = 0;
			}

			
		}

		//int ans = n;
		printf("Case #%d: %d\n", t, ans);
	}
}