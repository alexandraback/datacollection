#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()
#define each(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizoef(a))
#define sz(s) (int)((s).size())
#define INRANGE(x,s,e) ((s)<=(x) && (x)<(e))
#define pb push_back
#define MP(x,y) make_pair((x),(y))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

bool is_all_empty(vector<P> party){
	int n = party.size();
	rep (i, n){
		if (party[i].first != 0) return false;
	} //end rep
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int T; cin >> T;
	rep (i, T){
		int N; cin >> N;
		vector<P> party(N);	// first: number of party second: name of party
		int sum = 0;
		rep (j, N){
			party[j].second = j;
			int in; cin >> in;
			party[j].first = -in;
			sum += in;
		} // end rep
		vector<P> curr_party = party;
		vector<string> res; res.clear();
		while(!is_all_empty(curr_party)){
			sort(ALL(curr_party));
			if (curr_party[0].first == curr_party[1].first){
				string s = "";
				s += (char)(curr_party[0].second + 'A');
				s += (char)(curr_party[1].second + 'A');
				res.push_back(s);
				++curr_party[0].first;
				++curr_party[1].first;
			}else{
				string s = "";
				int max_cnt = min(-curr_party[0].first, 2);
				rep (j, max_cnt)
					s += (char)(curr_party[0].second + 'A');
				res.push_back(s);
				curr_party[0].first += max_cnt;
			} // end rep
			vector<P> next_party; next_party.clear();
			rep (j, curr_party.size()){
				if (curr_party[j].first == 0){
					continue;
				}else{
					next_party.push_back(curr_party[j]);
				} // end if
			} // end rep
			curr_party = next_party;
		} // end while

		if (sum % 2 != 0){
			swap (res[res.size() - 2], res[res.size() - 1]);
		} // end if

		cout << "Case #" << i+1 << ": ";
		rep (j, res.size()){
			cout << res[j] << (j != res.size() - 1 ? ' ' : '\n');
		} // end rep
	} // end rep

	return 0;
}
