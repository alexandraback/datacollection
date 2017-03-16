#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define N 110

using namespace std;

string str[N],t[N];
vector<int> V[N];
int T,n;

int main() {
	scanf("%d",&T);
	for(int Case = 1; Case <= T; Case++) {
		scanf("%d",&n);
		bool found = false;
		for(int i=0;i<N;i++) {
			V[i].clear();
		}
		for(int i=0;i<n;i++) {
			cin >> str[i];
			t[i] = "";
			int l = 0,k = 1;
			for(int j=0;str[i][j];j++) {
				if(!str[i][j+1] || str[i][j] != str[i][j+1]) {
					t[i] += str[i][j];
					V[l++].push_back(k);
					k = 1;
				}else {
					k++;
				}
			}
			if(i > 0 && t[i] != t[i-1]) {
				found = true;
				break;
			}
		}
		int ans = 0;
		for(int i=0;t[0][i];i++) {
			sort(V[i].begin(),V[i].end());
			for(int j=0;j<V[i].size();j++) {
				ans += abs(V[i][V[i].size()/2] - V[i][j]);
			}
		}
		printf("Case #%d: ",Case);
		if(found) {
			printf("Fegla Won\n");
		}else {
			printf("%d\n",ans);
		}
	}
	return 0;
}
