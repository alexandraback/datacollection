#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

int ileTestow;

int count(int val){
	int res = 0;
	while( val > 0 ){
		if( val & 1 ) res++;
		val /= 2;
	}
	return res;
}

bool get(int val, int r, int c, int rows){
	return val & 1<<(r+c*rows);
}

bool ok(int val, int mx){
	return val >= 0 && val < mx;
}

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		int r,c,n;
		cin >> r >> c >> n;

		int res = r * c * 4;
		
		fu(a,1<<(r*c)){
			if( count(a) != n ) continue;

			int tmp = 0;

			fu(x,c) fu(y,r) if( get(a, y, x, r) ){
				int xx[] = {-1,0,0,1};
				int yy[] = {0,-1,1,0};	

				fu(i,4) if( ok(x+xx[i], c) && ok(y+yy[i], r) && get(a, y+yy[i], x+xx[i], r) ){
					tmp++;
				}
			}

			res = min(res, tmp/2);
		}

		cout << res << endl;
	}

	return 0;
}
