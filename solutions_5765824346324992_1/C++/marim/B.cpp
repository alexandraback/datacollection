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

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		ll n, b;
		ll t[1000];

		cin >> b >> n;
		
		for(int i=0; i<b; i++){
			cin >> t[i];
		}
		
		ll start = 0, end = 1LL<<60;

//		cerr << endl << start << " : " << end << endl;

		while( start < end ){
			ll mid = (ll)start + (ll)(end - start) / 2L;

			ll count = 0;
			vi first;
			for(int i=0; i<b; i++){
				count += (ll)((ll)mid + t[i] - 1L) / (ll)t[i];
				if( (ll)mid % t[i] == 0L ){
					first.pb(i);
				}
			}

//			cerr << "mid: " << mid << " count: " << count << " n: " << n << " first.sz: " << first.sz << " # start: " << start << " end: " << end << endl;
			
			if( (ll)first.sz > 0L && count+1 <= n && count + (ll)first.sz >= n ){
				printf("%d\n", first[n-count-1]+1);
				break;
			} else if( count >= n ){
				end = mid;
			} else {
				start = mid+1;
			}
		}
	}

	return 0;
}
