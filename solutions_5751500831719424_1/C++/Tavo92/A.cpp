#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a,all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

typedef long long tint;

int T, n;
string arr[104];

bool anda(string &s, string &comp) {
	string compac; compac += s[0];
	char last = s[0];
	forn(i,s.size()) {
		if(s[i] == last) continue;
		compac += s[i];
		last = s[i];
	}

	return compac == comp;
}

int calc(int pos, int len, string &s) {
	char last = s[0];
	int toy = 0, lenPos = 0;
	forn(i,s.size()) {
		
		if(s[i] == last){
			if(toy == pos) lenPos++;
			continue;
		}
		toy++;
		if(toy == pos) lenPos++;
		last = s[i];
	}
	//cout << pos << " " << len << " " << s << " " << lenPos << endl;
	return abs(len-lenPos);
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	cin >> T;
	forn(t, T) {
		cin >> n;
		forn(i,n) cin >> arr[i];
		string compac; compac += arr[0][0];
		char last = arr[0][0];
		forn(i,arr[0].size()) {
			if(arr[0][i] == last) continue;
			compac += arr[0][i];
			last = arr[0][i];
		}

		bool haySol = true;
		forn(i,n) {
			if(!anda(arr[i], compac)) {
				haySol = false;
				break;
			}
		}
		printf("Case #%i: ", t+1);
		if(!haySol) {
			cout << "Fegla Won" << endl;
			continue;
		}

		int ret = 0;
		forn(i, compac.size()) {
			int best = INT_MAX;
			forsn(len, 1, 106) {
				int sumcaso = 0;
				forn(j, n) {
					sumcaso += calc(i, len, arr[j]);
				}
				best = min(best, sumcaso);
			}
			//cout << i << " " << best << endl;
			ret += best;
		}
		//cout << calc(2, 1, arr[0]) << " " << calc(2, 1, arr[1]) << endl;
		cout << ret << endl;
	}

	return 0;
}
