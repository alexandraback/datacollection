#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <queue> 

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, n) FOR(i, 0, n)
#define sz(e) (int)e.size()
#define all(e) e.begin(), e.end()
#define pb push_back
#define CLR(x, a) memset(x, a, sizeof(x))
  
#define ll long long
#define ull unsigned ll
#define ii pair<int, int>
#define vi vector<int>
  
using namespace std;

const int INF = 1000000000;

int mat[101][101];

int main (){
	int N, T;
	cin >> T;
	FORR (c, T){
		cin >> N;
		vector<string> vec;
		FORR (i, N){
			string str;
			cin >> str;
			vec.pb (str);
		}
		string str = "";
		bool ok = true;
		FORR (i, N){
			int pos = 0, cnt = 1;
			string tmp = "";
			tmp += vec[i][0];
			FOR (j, 1, sz(vec[i])){
				if (vec[i][j]!=vec[i][j-1]){
					tmp += vec[i][j];
					mat[i][pos] = cnt;
					cnt = 1;
					pos++;
				} else {
					cnt++;
				}
			}
			mat[i][pos] = cnt; 
			if (str.empty()) {
				str = tmp;
			} else if (str.compare(tmp)) {
				ok = false;
			}
		}
		cout << "Case #" << (c+1) << ": ";
		if (ok){
			int res = 0;
			FORR (j, sz(str)){
				int best = INF;
				FORR (k, N){
					int aux = 0; 
					FORR (i, N){
						aux += abs (mat[i][j]-mat[k][j]);
					}
					best = min (aux, best);
				}
				res += best;
			}
			cout << res << endl;
		} else {
			cout << "Fegla Won" << endl;
		}
		

	}
}

