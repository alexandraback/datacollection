#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define mem(a, v) memset(a, v, sizeof(a))
#define PI 3.14159265358979323846
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<VI> matrix;
const ll MOD = 1000000007LL;

int P[27];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &P[i]);
		}
		vector<PII> v;
		while(true){
			for(int i=0; i<n; i++){
				v.pb(mp(P[i], i));
			}
			sort(v.begin(), v.end());
			if(v[n-1].ft == 0)	
				break;
			if(n >= 3 && v[n-1].ft == v[n-3].ft){
				printf("%c ", 'A' + v[n-1].sd);
				P[v[n-1].sd]--;
			}
			else if(v[n-1].ft == v[n-2].ft){
				printf("%c%c ", 'A' + v[n-1].sd, 'A' + v[n-2].sd);
				P[v[n-1].sd]--;
				P[v[n-2].sd]--;
			}
			else{
				printf("%c ", 'A' + v[n-1].sd);
				P[v[n-1].sd]--;
			}
			v.clear();
		}
		printf("\n");
	}
	return 0;
}