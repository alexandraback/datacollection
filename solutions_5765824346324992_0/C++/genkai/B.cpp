#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int idxCase;
long long int b;
long long int n;

long long int mk[5];

int main () {

    freopen ("q1.in", "r", stdin); 
    freopen ("q1.out", "w", stdout);


	int idxCase;
	cin >> idxCase;
	for (int it = 1; it <= idxCase; it++) {
		cin >> b >> n;
		if(n <= b){
			cout << "Case #" << it << ": "<<1<<endl ;
			continue;
		}
		for (int i = 0; i < b; i++){ 
			cin >> mk[i];
		}

		long long int mul_all = 1;
		for (int i = 0; i < b; i++) mul_all*=mk[i];

		long long int mul_idx=0;
		for (int i = 0; i < b; i++) mul_idx += (mul_all / mk[i]);


		n %= mul_idx;

		long long int sum=0;
		long long int time;
		int ans=0;
		for(time=0; ; time++ ){
			sum =0;
			for(int i=0; i<b; i++){
				sum += ((time/mk[i]) + ((time%mk[i])==0));
			}
			if(sum >= (n)){
				sum = 0;
				for(ans=0; ans<b; ans++){
					sum += (time/mk[ans]);
				}
				for(ans=0; ans<b; ans++){
					sum +=((time%mk[ans])==0);	
					if(sum >=n){
						break;
					}
				}
				break;
			}
		}

		//fill in answer
		cout << "Case #" << it << ": "<<(ans+1);
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, idxCase, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * idxCase) / CLOCKS_PER_SEC);
	}
	return 0;
}
