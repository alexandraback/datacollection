//Template for Dev-C++ 5.5.3 by unlimitedsky
//2014 April 14 2135 hours (UTC +0800)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FOR(i,a,b,c) for (int i = a; i <= b; i+=c)
#define FORR(i,a,b,c) for (int i = a; i >= b; i-=c)
#define INCE(i,a,b) for (int i = a; i <= b; i++)
#define DECE(i,a,b) for (int i = a; i >= b; i--)
#define INC(i,a,b) for (int i = a; i < b; i++)
#define DEC(i,a,b) for (int i = a; i > b; i--)
#define MP make_pair
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a)
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int tc, n, tot, ctr, mid, len, ctr2;
char ch, str[105];
vector<int> v;
bool bisa;
queue<int> q[105];

int main(){
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++){
		scanf("%d", &n);
		for (int x = 0; x < n; x++){
			while(!q[x].empty()) q[x].pop();
			
			scanf("%s", str);
			len = strlen(str);
			for (int y = 0; y < len; y++){
				q[x].push(str[y]);
			}
		}
		bisa = true;
		tot = 0;
		while(!q[0].empty()){
			if (v.size() > 0) v.clear();
			ch = q[0].front();
			for (int x = 0; x < n; x++){
				ctr = 0;
				if (!q[x].empty()){
					while(q[x].front() == ch){
						ctr++;
						q[x].pop();
						if (q[x].empty()) break;
					}
				}
				if (ctr == 0){
					bisa = false;
					break;
				}
				else{
					v.push_back(ctr);
				}
			}
			if (bisa){
				sort(v.begin(), v.end());
				mid = (v.size()-1)/2;
				if (v.size() % 2 == 1){
					ctr = 0;
					for (int x = 0; x < v.size(); x++){
						ctr += abs(v[mid] - v[x]);
					}
					ctr2 = ctr;
				}
				else{
					ctr = 0;
					for (int x = 0; x < v.size(); x++){
						ctr += abs(v[mid] - v[x]);
					}
					ctr2 = 0;
					for (int x = 0; x < v.size(); x++){
						ctr2 += abs(v[mid+1] - v[x]);
					}
				}
				tot += min(ctr,ctr2);
			}
		}
		INC(x,0,n){
			if (!q[x].empty()){
				bisa = false;
				break;
			}
		}
		printf("Case #%d: ", i);
		if (bisa) printf("%d\n", tot);
		else printf("Fegla Won\n");
	}
	return 0;
}
