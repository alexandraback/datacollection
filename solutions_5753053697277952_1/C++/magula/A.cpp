#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii > vii;
typedef queue<int> qi;
typedef set<int> si;

#define RE(i,b) for(int i=0; i<(int)(b); i++)
#define REP(i,a,b) for(int i=(a); i<(int)(b); i++)
#define BREP(i,a,b) for(int i=(a)-1; i>=(b); i--)
#define FE(i,X) for(typeof((X).begin()) i=(X).begin(); i!=(X).end(); ++i)

#define INF 1000000000
#define MP make_pair
#define FI first
#define SE second
template<class t> void setmin(t &a, t b){a=min(a,b);}

int P[100];

int main(){
	int TC;scanf("%d ",&TC);
	RE(tc,TC){
		printf("Case #%d:",tc+1);
		int N;scanf("%d ",&N);
		RE(i,N){
			scanf("%d ",&P[i]);
		}
		while(1){
			int A=0,B=0,sum=0;
			RE(i,N){
				sum+=P[i];
				if(P[i]>=P[A]){
					B=A;
					A=i;
				}else if(P[i]>=P[B]){
					B=i;
				}
			}
			if(sum==0)
				break;
			P[A]--;
			printf(" %c",A+'A');
			if(P[B]*2>sum-1){
				P[B]--;
				printf("%c",B+'A');
			}
		}
		printf("\n");
	}
	return 0;
}
