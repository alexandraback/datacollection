//:) :( :P =D :o ;) :v >:( :/ :'( ^_^ -_- o.O >:o :3 
//http://fixed-point.org/index.php/video/35-full-length/164-the-dawkins-lennox-debate
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000000

int main() {
	int T, N;
	scanf("%d", &T);
	for(int cs = 1; cs <= T; cs++) {
		scanf("%d", &N);
		int arr[N];
		int one = 0, two = 0;
		int ma = 0;
		for(int c = 0; c < N; c++) {
			scanf("%d", &arr[c]);
		}
		for(int c = 0; c < N-1; c++) {
			one += max(0, arr[c]-arr[c+1]);
			ma = max(ma, arr[c]-arr[c+1]);
		}
		for(int c = 0; c < N-1; c++)
			two += min(ma, arr[c]);
		printf("Case #%d: %d %d\n", cs, one, two);
	}
}

/*#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int dp[50005];
int arr[50005];
int N;
int f(int i) {
    if(i == N) return 0;
    if(dp[i] != -1) return dp[i];
    int debt = 0;
	int res = 0;
    for(int j = i; j < N; j++) {
        res = max(0, (j-i)*arr[j] - debt + f(j+1));
        debt += arr[j];
    }
    return dp[i] = res;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T-->0) {
        scanf("%d", &N);
        memset(dp, -1, sizeof(int)*(N+1));
        for(int c = 0; c < N; c++)
            scanf("%d", &arr[c]);
        printf("%d\n", f(0));
    }
    return 0;
}*/


/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N,M;
	while(scanf("%d%d", &N,&M) != -1) {
		int val[N];
		int adj[N];
		fill(val, val+N, 1);
		fill(adj, adj+N, 0);
		bool G[N][N];
		memset(G, 0, sizeof(bool)*N*N);
		for(int c = 0; c < M; c++) {
			int i,j;
			scanf("%d%d", &i,&j);
			G[i-1][j-1] = G[j-1][i-1] = true;
			adj[i-1]++;
			adj[j-1]++;
		}
		while(1) {
			bool stop = true;
			for(int c = 0; c < N; c++) {
				if(val[c]%2 != 0) {stop = false; break;}
			}
			if(stop) break;
			for(int c = 0; c < N; c++) {
				if(adj[c] == 1) {
					stop = false;
					for(int d = 0; d < N; d++) {
						if(G[c][d]) {
							if(val[c]%2 != 0) {
								val[d] += val[c];
								M--;
							}
							G[c][d] = G[d][c] = false;
							val[c] = 0;
							adj[c]--;
							adj[d]--;
							break;
						}
					}
					adj[c] = 0;
				}
			}
		}
		printf("%d\n", M);
	}
}*/

//bahay03214guinto
/*#include<cstdio>
using namespace std;

void printNumberedTriangle(int sz) {
	for(int c = 1; c <= sz; c++) {
		int print = c*(c+1)/2;
		for(int d = 1; d <= sz; d++) {
			if(d < c) printf(" ");
			else {
				printf("%d", print%10);
				print += d;
			}
		}
		printf("\n");
	}
}

int gcf(int a, int b) {
	if(b == 0) return a;
	return gcf(b, a%b);
}

int main() {
	int N;
	scanf("%d", &N);
	printNumberedTriangle(N);
}*/

/*#include<cstdio>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SZ 50000

bool sieve[SZ];
vector<int> primes;
set<int> squares;
vector<int> yes;

int main() {
	fill(sieve, sieve+SZ, true);
	sieve[0] = sieve[1] = false;
	for(int c = 2; c <= 8000; c++) {
		if(c*c < 2000000000) squares.insert(c*c);
		if(sieve[c]) {
			if(c >= 5) primes.push_back(c);
			for(int d = c; c*d < SZ; d++)
				sieve[c*d] = false;
		}
	}
	for(int c = 0; c < primes.size(); c++) {
		for(int d = 1; primes[c]*primes[c] - d*d > 0; d++) {
			if(squares.find(primes[c]*primes[c] - d*d) != squares.end()) {
				yes.push_back(primes[c]);
				//printf("%d %.0f %d\n", d, sqrt(primes[c]*primes[c]-d*d), primes[c]); 
				break;
			}
		}
		//printf("%d %d\n", primes[c], cntpairs);
	}
	/*printf("%d\n", primes[primes.size()-1]);
	printf("%d\n",(int)(yes.size()));* /
	int T,R,K;
	scanf("%d", &T);
	for(;T>0;T--) {
		scanf("%d%d", &R,&K);
		int lattice = 4;
		for(int c = 0; c < yes.size(); c++) {
			if(R%yes[c] == 0) { lattice += 8; break; }
		}
		if(K >= lattice) printf("possible\n");
		else printf("impossible\n");
	}
}*/
// ^-?\d{1,3}(,\d{3})*(\.\d+)?(e\d+)?$ regex for number

/*#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

class Pt {
	public:
	double x, y;
	Pt(double a, double b) {
		x = a;
		y = b;
	}
	bool operator<(const Pt &p) const {
		if(x != p.x) return x < p.x;
		return y < p.y;
	}
};

bool ccw(Pt a, Pt b, Pt c) {
	double A = b.x-a.x;
	double B = b.y-a.y;
	double C = c.x-a.x;
	double D = c.y-a.y;
	if(A*D - B*C <= 0.0) return true;
	return false;
}

int main() {
	int T, N;
	double X, Y, W, H, phi;
	scanf("%d", &T);
	while(T-->0) {
		scanf("%d", &N);
		vector<Pt> pts;
		double boards = 0.0;
		for(int c = 0; c < N; c++) {
			scanf("%lf%lf%lf%lf%lf", &X,&Y,&W,&H,&phi);
			boards += W*H;
			double lX = X-(W/2.0);
			double lY = Y-(H/2.0);
			pts.push_back(Pt(lX,lY));
			pts.push_back(Pt(lX + h*cos(90.0-phi), lY + h*sin(90.0-phi)));
			
		}
	}
}*/

/*#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;

map<string, int> M;
map<string, int> order;
vector<string> arr;
int ma = 0;

int f(string S) {
	int val = M[S];
	ma = max(ma, val);
	string cp(S);
	for(int c = S.size()-1; c >= 0; c--) {
		for(int d = cp[c]-'a'+1; d < 26; d++) {
			cp[c] = 'a'+d;
			if(M[cp] == 1) {
				M[cp] = val+1;
				f(cp);
			}
		}
		cp[c] = S[c];
	}
	for(int c = S.size()-1; c >= 0; c--) {
		string cp2(S);
		if(S[c+1] > S[c]) {
			cp2.erase(cp2.begin()+c);
			if(M[cp2] == 1) {
				M[cp2] = val+1;
				f(cp2);
			}
		}
	}
	for(int c = 0; c < 26; c++) {
		string cp2(S);
		cp2.insert(cp2.end(), 1, 'a'+c);
		if(M[cp2] == 1) {
			M[cp2] = val+1;
			f(cp2);
		}
	}
	for(int c = S.size()-1; c >= 0; c--) {
		for(int d = S[c]-'a'; d < 26; d++) {
			string cp2(S);
			cp2.insert(cp2.begin()+c, 'a'+d);
			if(M[cp2] == 1) {
				M[cp2] = val+1;
				f(cp2);
			}
		}
	}
}
	/*ma = max(ma, vis[i]);
	for(int c = i+1; c < arr.size(); c++) {
		if(vis[c] == 1) {
			int fail = 0;
			if(arr[i].size() == arr[c].size()) {
				for(int d = 0; d < arr[i].size(); d++) {
					if(arr[i][d] != arr[c][d])
						fail++;
				}
			}
			else if(arr[i].size() - 1 == arr[c].size()) {
				int j = 0;
				for(int d = 0; d < arr[c].size(); d++) {
					if(arr[c][d] == arr[i][j]) j++;
					else fail++;
				}
				if(j == arr[c].size()) fail++;
			}
			else if(arr[i].size() + 1 == arr[c].size()) {
				int j = 0;
				for(int d = 0; d < arr[i].size(); d++) {
					if(arr[i][d] == arr[c][j]) j++;
					else fail++;
				}
				if(j == arr[i].size()) fail++;
			}
			
			if(fail == 1) {
				cout << arr[i] << " " << arr[c] << endl;
				vis[c] = vis[i]+1;
				f(c);
				//break;
			}
		}
	}* /

int main() {
	string s;
	int cnt = 0;
	while(!cin.eof()) {
		getline(cin, s);
		M[s] = 1;
		order[s] = cnt++;
		arr.push_back(s);
	}
	for(int c = 0; c < arr.size(); c++) {
		if(M[arr[c]] == 1) {
			vector<string> dfs;
			
		}	
	}
	printf("%d\n", ma);
}*/

/*#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

int main() {
	int N;
	int cases = 1;
	int diry[] = {-1, -1, 0, 0, 1, 1};
	int dirx[] = {-1, 0, -1, 1, 0, 1};
	string S;
	while(cin >> N) {
		if(N == 0) return 0;
		char grid[N][N];
		for(int c = 0; c < N; c++) {
			cin >> S;
			for(int d = 0; d < N; d++)
				grid[c][d] = S[d];
		}
		bool black = false;
		bool white = false;
		for(int c = 0; c < N; c++) {
			if(grid[0][c] == 'b') {
				list<int> bfs;
				bool vis[N][N];
				memset(vis, 0, sizeof(bool)*N*N);
				vis[0][c] = true;
				bfs.push_back(c);
				while(!bfs.empty()) {
					int i = bfs.front(); bfs.pop_front();
					int ro = i/N;
					int co = i%N;
					if(ro == N-1) black = true;
					for(int d = 0; d < 6; d++) {
						int rro = i+diry[d];
						int cco = i+dirx[d];
						if(rro >= 0 && rro < N && cco >= 0 && cco < N && grid[rro][cco] == 'b' && !vis[rro][cco]) {
							bfs.push_back(rro*N + cco);
							vis[rro][cco] = true;
						}
					}
				}
			}
			
			if(grid[c][0] == 'w') {
				list<int> bfs;
				bool vis[N][N];
				memset(vis, 0, sizeof(bool)*N*N);
				vis[c][0] = true;
				bfs.push_back(c*N);
				while(!bfs.empty()) {
					int i = bfs.front(); bfs.pop_front();
					int ro = i/N;
					int co = i%N;
					if(co == N-1) white = true;
					for(int d = 0; d < 6; d++) {
						int rro = i+diry[d];
						int cco = i+dirx[d];
						if(rro >= 0 && rro < N && cco >= 0 && cco < N && grid[rro][cco] == 'w' && !vis[rro][cco]) {
							bfs.push_back(rro*N + cco);
							vis[rro][cco] = true;
						}
					}
				}
			}
			if(black || white) break;
		}
		printf("%d", cases++);
		if(black) printf(" B");
		else if(white) printf(" W");
		printf("\n");
	}
}*/

/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define pii pair<int,int>

class comp {
	public:
	bool operator()(pii p1, pii p2) {
		if(p1.second > p2.second) return true;
		else return false;
	}
};

int main() {
	int V,E;
	int from, to, dist;
	int cnt = 1;
	while(true) {
		scanf("%d%d",&V,&E);
		if(!V && !E) return 0;
		priority_queue<pii, vector<pii>, comp> pq;
		vector<pii> G[V];
		int GG[V][V];
		memset(GG, -1, sizeof(int)*V*V);
		for(int c = 0; c < E; c++) {
			scanf("%d%d%d", &from,&to,&dist);
			G[from-1].push_back(pii(to-1,dist));
			G[to-1].push_back(pii(from-1,dist));
			GG[from-1][to-1] = GG[to-1][from-1] = dist;
		}
		int vis[V];
		fill(vis, vis+V, -1);
		vis[0] = 0;
		pq.push(pii(0, 0));
		double ans = 0.0;
		int one = 1, two = -1;
		while(!pq.empty()) {
			pii P = pq.top(); pq.pop();
			if(P.second > ans) { ans = (double)P.second; one = P.first+1; }
			for(int c = 0; c < G[P.first].size(); c++) {
				int i = G[P.first][c].first;
				int j = G[P.first][c].second;
				if(vis[i] == -1 || vis[i] > P.second+j) {
					vis[i] = P.second+j;
					pq.push(pii(i, vis[i]));
				}
			}
		}
		for(int c = 0; c < V; c++) {
			for(int d = c+1; d < V; d++) {
				if(GG[c][d] != -1) {
					if(abs(vis[c]-vis[d]) < GG[c][d]) {
						int ma = max(vis[c], vis[d]);
						int hmm = GG[c][d]-abs(vis[c]-vis[d]);
						double meet = (double)(ma + hmm/2.0);
						if(meet > ans) {
							ans = meet;
							one = c+1;
							two = d+1;
						}
					}
				}
			}
		}
		printf("System #%d\n", cnt++);
		if(two == -1)
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n", ans, one);
		else
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n", ans, one, two);
	}
}*/

/*#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[200][30];
int pred[200][30];
int N,H;
int F[30];
int D[30];
int G[30];
int times[30];

int f(int t, int i) {
	if(t >= H*12 || i == N) return 0;
	if(dp[t][i] != -1) return dp[t][i];
	int stay = 0;
	pred[t][i] = 0;
	for(int c = 0; c+t <= H*12; c++) {
		int leave = stay+f(t+c+G[i], i+1);
		stay += max(0, F[i]-(c*D[i]));
		if(leave >= dp[t][i]) {
			dp[t][i] = leave;
			pred[t][i] = c;
		}
	}
	return dp[t][i];
}

int main() {
	bool first = true;
	while(true) {
		scanf("%d", &N); if(!N) return 0;
		if(!first) printf("\n"); first = false;
		scanf("%d", &H);
		for(int c = 0; c < N; c++) scanf("%d", &F[c]);
		for(int c = 0; c < N; c++) scanf("%d", &D[c]);
		for(int c = 0; c < N-1; c++) scanf("%d", &G[c]);
		memset(dp, -1, sizeof(int)*200*30);
		memset(pred, 0, sizeof(int)*200*30);
		fill(times, times+30, 0);
		int ans = f(0, 0);
		int A = 0, B = 0;
		for(; B < N; B++) {
			if(B > 0) printf(", ");
			printf("%d", 5*pred[A][B]);
			A += pred[A][B]+G[B];
		}	
		printf("\nNumber of fish expected: %d\n", ans);
	}
}*/

/*#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000000

int main() {
	int N,E,Q;
	int cases = 1;
	while(true) {
		if(scanf("%d", &N) <= 0) return 0;
		int busy[N];
		int vals[N];
		int G[N][N];
		bool G2[N][N];
		fill(vals, vals+N, INF);
		for(int c = 0; c < N; c++) {
			scanf("%d", &busy[c]);
			fill(G[c], G[c]+N, INF);
			fill(G2[c], G2[c]+N, false);
		}
		vals[0] = 0;
		scanf("%d", &E);
		for(int c = 0; c < E; c++) {
			int from, to;
			scanf("%d%d", &from,&to);
			int go = busy[to-1]-busy[from-1];
			G[from-1][to-1] = go*go*go;
			G2[from-1][to-1] = true;
		}
		for(int k = 0; k < N; k++) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(G2[i][k] && G2[k][j])
						G2[i][j] = true;
				}
			}
		}
		for(int c = 0; c < N-1; c++) {
			for(int d = 0; d < N; d++) {
				for(int e = 0; e < N; e++) {
					if(G[d][e] != INF) {
						vals[e] = min(vals[e], vals[d]+G[d][e]);
					}
				}
			}
		}
		for(int d = 0; d < N; d++) {
			for(int e = 0; e < N; e++) {
				if(G[d][e] != INF) {
					if(vals[d]+G[d][e] < vals[e]) {
						for(int f = 1; f < N; f++) {
							if(G2[0][e] && G2[e][f])
								vals[f] = 0;
						}
					}
				}
			}
		}
		scanf("%d", &Q);
		printf("Set #%d\n", cases++);
		for(int c = 0; c < Q; c++) {
			int query;
			scanf("%d", &query);
			if(vals[query-1] < 3 || vals[query-1] == INF) printf("?\n");
			else printf("%d\n", vals[query-1]);
		}
	}
}*/

/*
Jeremiah 29:11
"For I know the plans I have for you," declares the Lord, "plans to prosper you and not to harm you, plans to give you hope and a future."

*/