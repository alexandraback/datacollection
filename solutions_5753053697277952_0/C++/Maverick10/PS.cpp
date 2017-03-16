#include<bits/stdc++.h>
#include<ext/numeric>
using namespace std;
using namespace __gnu_cxx;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)  (ll)v.size()
#define UNVISITED -1
#define CLR(a,v) memset(a,v,sizeof a)
#define PC(x) __builtin_popcount(x)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

const int MAX = 2005;
vi adjList[MAX];
bool adjMatrix[MAX][MAX];
vii edges;

class SmilesTheFriendshipUnicorn {
public:
	string hasFriendshipChain(int N, vector<int> A, vector<int> B) {
		int n = sz(A);
		for (int i = 0; i < n; ++i) {
			int u = A[i], v = B[i];
			adjList[u].push_back(v);
			adjList[v].push_back(u);
			adjMatrix[u][v] = 1;
			adjMatrix[v][u] = 1;
			edges.push_back(ii(u, v));
			edges.push_back(ii(v, u));
		}
		for (auto x : edges)
			for (auto y : edges) {
				int a = x.first, b = x.second, c = y.first, d = y.second;
				if (a != c && a != d && b != c && b != d && adjMatrix[b][c])
					for (auto i : adjList[a])
						if (i != a && i != b && i != c && i != d)
							return "Yay!";
			}
		return ":(";
	}
};

//int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//#endif
//	SmilesTheFriendshipUnicorn s;
//
//	s.hasFriendshipChain(7, A, B);
//}
