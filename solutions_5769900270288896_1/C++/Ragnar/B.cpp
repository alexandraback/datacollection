#include <iostream>
#include <cstdio> // for printf
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <sstream>
#include <math.h>

#define REP(i,n) for(int i = 0; i<(n); i++)
#define ITER(i,v) for(auto i : v)
#define INF 1000000000
#define F(v) (v).begin(), (v).end()
#ifdef DEBUG
const bool DEBUG = true;
#else
const bool DEBUG = false;
#endif

using namespace std;

template <class T>
using priority_queue_asc =  priority_queue<T,vector<T>, greater<T> >;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int TC; cin >> TC;
	for(int tc=1; tc<=TC;tc++){
		int r,c,N;
		cin >> r >> c >> N;

		// r<=c
		if(r>c) swap(r,c);

		array<int,5> n;
		
		n[4] = ((r-2)*(c-2)+1)/2;
		if(r<=2) n[4]=0;

		n[3] = r + c - 4;
		// both odd
		if(r%2 && c%2) n[3] = r + c - 6;
		if(r==1) n[3]=0;
		if(r==2) n[3]=c-2;

		// n[2] = 4 iff r==c mod 2
		n[2]=2;
		// only 4 when odd*odd
		if((r*c)%2)
			n[2]=4;
		if(r==1) n[2]=(c-1)/2;
		if(r==2) n[2]=2;


		n[1]=0;
		if(r==1 && (c+1)%2)
			n[1]=1;


		n[0]=r*c-n[1]-n[2]-n[3]-n[4];
		

		// now calculate the answer
		int ans = (r-1)*c + r*(c-1);
		int empty = r*c-N;
		if(empty>0)
			ans -= 4*min(empty, n[4]), empty-=n[4];
		if(empty>0)
			ans -= 3*min(empty, n[3]), empty-=n[3];
		if(empty>0)
			ans -= 2*min(empty, n[2]), empty-=n[2];
		if(empty>0)
			ans -= 1*min(empty, n[1]), empty-=n[1];
		if(empty>0)
			ans -= 0*min(empty, n[0]), empty-=n[0];

		// special case: both odd and >=3
		if((r*c)%2 && r > 1){
			n[4] = ((r-2)*(c-2))/2;
			n[3] = r+c-2;
			n[2] = n[1] = 0;
			n[0] = r*c - n[4]-n[3];
			int ans2 = (r-1)*c + r*(c-1);
			empty = r*c-N;
			if(empty>0)
				ans2 -= 4*min(empty, n[4]), empty-=n[4];
			if(empty>0)
				ans2 -= 3*min(empty, n[3]), empty-=n[3];
			if(empty>0)
				ans2 -= 2*min(empty, n[2]), empty-=n[2];
			if(empty>0)
				ans2 -= 1*min(empty, n[1]), empty-=n[1];
			if(empty>0)
				ans2 -= 0*min(empty, n[0]), empty-=n[0];
			ans = min(ans,ans2);
		}

		cout << "Case #"<<tc<<": "<<ans<<"\n";
	}
	return 0;
}


