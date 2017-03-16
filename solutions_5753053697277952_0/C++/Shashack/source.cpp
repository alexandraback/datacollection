#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;

#define y1 mine
#define mp make_pair

double pi = acos(-1);
ll power(ll a, ll b){ ll p_res = 1; while (b > 0){ if (b % 2 == 1) { p_res *= a; b--;} a *= a; b /= 2;} return p_res;}
int n;

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++){
		cin >> n;
		int total = 0;
		priority_queue < pair<int, string> > pq;
		vector<string> ans;
		string emp = "";
		for (char i = 0; i < n; i++){
			int v; cin >> v;
			char apb = 'A' + i;
			total += v;
			pq.push(mp(v, apb + emp));
		}
		while (pq.size() != 0){
			int num = pq.top().first;
			string ap = pq.top().second + emp;
			pq.pop();

			total--;
			if (num > 1){
				pq.push(mp((num - 1), ap));
			}
			if (pq.size() != 0){
				if (pq.top().first * 2 > total){
					string ap2 = pq.top().second;
					ap += ap2;
					int n2 = pq.top().first;
					
					pq.pop();
					if (n2 - 1 > 0){
						pq.push(mp(n2 - 1, ap2));
					}
					total--;
				}

			}
			ans.push_back(ap + emp);

		}
		cout << "Case #" << t << ": ";
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
}


