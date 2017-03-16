#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<functional> //highest
#include<algorithm>	//sort, heap etc.
#include<utility>	//pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef stack<int> si;
typedef queue<int> qi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> elst;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(a,b) ((a) < (b) ? (b)-(a) : (a)-(b))

#define FORN(i,j,n) for(int i=j;i<(int)n;i++)
#define forn(i,n) FORN(i,0,n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define sz size()
#define ff first
#define ss second
#define pq priority_queue
#define all(x) (x).begin(),(x).end()
#define mlc(t,n) ((t*)malloc(n*sizeof(t)))
#define mset(m,v) memset(m,v,sizeof(m))

#define INF 1000000000
#define M 1000000007

//---------------------------------------------//

int comp (ii a, ii b) {
	return a.second > b.second;
}

void  evacuate() {
	int N;
	cin >> N;
	vii p = vii(N);
	int c = 0;
	forn(i, N) {
		int x ;
		cin >> x;
		c += x;
		p[i] = ii(i+1, x);
	}
	//cout << N;

	sort(p.begin(), p.end(), comp);

	while(p[0].second != 0) {
		char t0 = 'A' + p[0].first - 1;
		char t1 = 'A' + p[1].first - 1;

		if (p[0].second == p[1].second && c == p[0].second * 2) {
			cout << t0 << t1 << " ";
			c -= 2;
			p[0].second--;
			p[1].second--;
		} else {
			cout << t0 << " ";
			c--;
			p[0].second--;
		}

		sort(p.begin(), p.end(), comp);
	}

	cout << endl;
}

int main() {
//	freopen("1C/in.txt", "r", stdin);
//	freopen("1C/A-small-attempt0.in", "r", stdin);
	freopen("1C/A-large.in", "r", stdin);
	freopen("1C/out.txt","w", stdout);

	int T;
	scanf("%d",&T);

	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		evacuate();
	}
}
