//Template for Dev-C++ 5.3.0.4 by unlimitedsky
//2013 March 4 20:58 (UTC +07.00)
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
#define INC(i,a,b) for (int i = a; i <= b; i++)
#define DEC(i,a,b) for (int i = a; i >= b; i--)
#define MP make_pair
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a)
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int tc, n, x, seth;
bool visit[20];

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &tc);
	INC(t,1,tc){
		reset(visit,0);
		
		scanf("%d", &n);
		INC(i,1,4){
			INC(j,1,4){
				scanf("%d", &x);
				if (i == n){
					visit[x] = true;
				}
			}
		}
		seth = 0;
		scanf("%d", &n);
		INC(i,1,4){
			INC(j,1,4){
				scanf("%d", &x);
				if (i == n){
					if (visit[x]){
						if (seth == 0){
							seth = x;
						}
						else{
							seth = -1;
						}
					}
				}
			}
		}
		printf("Case #%d: ", t);
		if (seth == 0) printf("Volunteer cheated!\n");
		else if (seth == -1) printf("Bad magician!\n");
		else{
			printf("%d\n", seth);
		}
	}
	
	return 0;
}
