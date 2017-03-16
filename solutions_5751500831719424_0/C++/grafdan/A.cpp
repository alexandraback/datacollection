#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int in;
typedef pair<char,int> PCI;
typedef vector<PCI> VPCI;
typedef vector<VPCI> VVPCI;

void testcase() {
	in N; cin>> N;
	VVPCI A = VVPCI(N);
	bool fegla_wins = false;
	for(in n=0; n<N; n++) {
		string s; cin>>s;
		A[n].PB(MP(s[0],1));
		for(in i=1; i<s.size();i++) {
			if(s[i] == A[n][A[n].size()-1].first) {
				A[n][A[n].size()-1].second++;
			} else {
				A[n].PB(MP(s[i],1));
			}
		}
		for(in i=0; i<A[n].size();i++) {
			if(n>0)
				if(A[n].size() != A[0].size() || A[n][i].first != A[0][i].first)
					fegla_wins = true;
			// cout << A[n][i].first << " " << A[n][i].second << " / ";
		} 
		// cout << endl;
	}
	if(fegla_wins) {
		cout << "Fegla Won";
		return;
	}
	in cost=0;
	for(int i=0; i<A[0].size(); i++) {
		vector<in> V;
		for(in n=0; n<N; n++)
			V.PB(A[n][i].second);
		sort(V.begin(), V.end());
		in med = V[V.size()/2];
		// cout << "med for " << A[0][i].first << ": " << med << endl;
		for(in n=0; n<N; n++) {
			cost += abs(V[n]-med);
		}
	}

	cout << cost;

}

int main() {
	in T;
	cin >> T;
	for(int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		testcase();
		cout << endl;
	}
}