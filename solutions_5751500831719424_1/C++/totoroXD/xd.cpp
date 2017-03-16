/*
 * totoroXD
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int INF = 1011110000, MOD=1000000000;
const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
const double EPS = 1e-6;
int kase=1;
int n;
char str[111][111];
vector<pair<char, int> > prs[111];
bool input(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s", &str[i]);
	}
	return 0;
}
void solve(){

	printf("Case #%d: ",kase++);
	for(int i=0; i<n; i++){
		int len=strlen(str[i]);
		prs[i].clear();
		for(int j=0, l=0; j<len; j++){
			if(j!=0 && str[i][j]==str[i][j-1]){
				prs[i].back().second++;
			}else{
				prs[i].push_back(make_pair(str[i][j], 1));
			}
		}
	}
	for(int i=1; i<n; i++){
		if(prs[i].size()!=prs[0].size()){
			printf("Fegla Won\n");
			return;
		}
		for(int j=0; j<prs[i].size(); j++){
			if(prs[i][j].first!=prs[0][j].first){
				printf("Fegla Won\n");
				return;
			}
		}
	}
	int num[111], res=0;
	for(int j=0; j<prs[0].size(); j++){
		for(int i=0; i<n; i++){
			num[i] = prs[i][j].second;
		}
		sort(num, num+n);
		int p=num[n/2];
		for(int i=0; i<n; i++){
			res+= abs(num[i]-p);
			//printf("+%d\n",abs(num[i]-p));
		}
	}
	printf("%d\n",res);
}
void pre(){
}
int main(){
	pre();
    int zz=1;
    cin>>zz;
    while(zz--){
    	input();
    	solve();
    }
    return 0;
}

/*

5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc

*/

