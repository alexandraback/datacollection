#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };
int calc(bool f, int R, int C, int n){
	vector<vector<bool> > g(R, vector<bool>(C, 0));
	vector<int> free;
	for(int i=0;i<R;++i){
		bool cur = i == 0 ? f : !g[i - 1][0];
		for (int j = 0; j<C; ++j){
			g[i][j]=cur;
			if(cur)
				--n;
			cur=!cur;
		}
	}
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			if(!g[i][j]){
				int adj = 0;
				for (int d = 0; d<4; ++d){
					int nr=i+dr[d];
					int nc=j+dc[d];
					if(nr<0 || nr==R || nc<0 || nc==C)
						continue;
					++adj;
				}
				free.push_back(adj);
			}
	sort(free.begin(), free.end());
	reverse(free.begin(), free.end());
	int res=0;
	while(n>0){
		res+=free.back();
		free.pop_back();
		--n;
	}
	return res;
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int qq;
	scanf("%d", &qq);
	int R, C, n;
	for (int T = 1; T <= qq; ++T){
		printf("Case #%d: ", T);
		cin >> R >> C >> n;
		int res = calc(false, R, C, n);
		res = min(res, calc(true, R, C, n));
		printf("%d\n", res);
	}
	return 0;
}