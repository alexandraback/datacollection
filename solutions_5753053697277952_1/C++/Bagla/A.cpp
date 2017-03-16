#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<climits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define S(x) scanf("%d",&x)
#define SD(x) scanf("%lf",&x)
#define SL(x) scanf("%lld",&x)
#define pb(x) push_back(x)
#define mp make_pair
#define F(i, a, b) for (int i = int(a); i < int(b); i++)
#define forit(it, a) for (it = (a).begin(); it != (a).end(); it++)
#define M(x,i) memset(x,i,sizeof(x))

/* -------------------CODE GOES HERE---------------------- */

int main(){

	int T, tst = 1; S(T);
	int N, temp;
	vi A,m;
	bool flag;

	while(T--){

		S(N);
		A.clear();

		F(i,0,N){
			S(temp);
			A.pb(temp);
		}

		printf("Case #%d: ", tst++);
		
		flag = true;
		while(flag){
			flag = false;
			m.clear();

			int mx = -1;
			
			F(i,0,N){

				if(A[i] == 0) continue;
				else flag = true;

				if(A[i] > mx){
					m.clear();
					m.pb(i);
					mx = A[i];
				}

				else if(A[i] == mx){
					m.pb(i);
				}
			}

			if(!flag) continue;

			int a = m.size();
			if(a == 1){
				cout<<char('A'+m[0])<<" ";
				A[m[0]]--;
			}
			else if(a == 2){
				cout<<char('A'+m[0])<<char('A'+m[1])<<" ";
				A[m[0]]--;
				A[m[1]]--;
			}
			else if(a >= 3){
				cout<<char('A'+m[0])<<" ";
				A[m[0]]--;
			}
		}

		printf("\n");
	}
}
