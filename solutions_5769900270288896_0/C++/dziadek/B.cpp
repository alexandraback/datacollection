#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define f first
#define s second

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

int t[20][20],r,c;

bool inside(int x, int y){
	if(x >= 0 && x < r && y >=0 && y < c) return true;
	return false;
}

int calc(int x, int y){
	int r = 0;
	if(inside(x-1,y) && t[x-1][y]) ++r;
	if(inside(x+1,y) && t[x+1][y]) ++r;
	if(inside(x,y-1) && t[x][y-1]) ++r;
	if(inside(x,y+1) && t[x][y+1]) ++r;
	return r;
}

void testcase(){
	int n;
	cin >> r >> c >> n;

	if(2*n <= r*c){
		cout << 0;
		return;
	}

	VI v;
	int result = 4*r*c;

	REP(i,r*c-n) v.PB(0);
	REP(i,n) v.PB(1);

	do{
		int cur = 0;
		REP(i,r) REP(j,c) t[i][j] = 0;
		REP(i,r*c)
			if(v[i] == 1) t[i / c][i % c] = 1;
		REP(i,r) REP(j,c)
			if(t[i][j]) cur += calc(i,j);
		result = min(result, cur);
	} while(next_permutation(ALL(v)));

 	cout << result / 2;

}

int main(){
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	FOR(i,1,t){
		cout << "Case #" << i << ": ";
		testcase();
		cout << endl;
	}

	return 0;
}
