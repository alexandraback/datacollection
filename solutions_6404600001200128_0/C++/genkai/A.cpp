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
int n;
int m[100];
int s[50];
//vector<pair<string, int> > w;

int main () {

    freopen ("q1.in", "r", stdin); 
    freopen ("q1.out", "w", stdout);


	int idxCase;
	cin >> idxCase;
	for (int it = 1; it <= idxCase; it++) {
		cin >> n ;
		for (int i = 0; i < n; i++) cin >> m[i];

		int ans_A = 0;
		int diff_max = 0;
		for(int i=1; i<n;i++){
			if(m[i-1] > m[i]){	
				ans_A += m[i-1] - m[i];
			}
			if((m[i-1] - m[i]) > diff_max){
				diff_max = (m[i-1] - m[i]);
			}
		}
		int ans_B = 0;
		for(int i=1; i< n ; i++){
 			if(m[i-1] < diff_max){
				ans_B += m[i-1];
			}
			else{
				ans_B += diff_max;
			}
		}


		//fill in answer
		cout << "Case #" << it << ": "<< ans_A << " " << ans_B ;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, idxCase, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * idxCase) / CLOCKS_PER_SEC);
	}
	return 0;
}
