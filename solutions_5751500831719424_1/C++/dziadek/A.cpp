#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define f first
#define s second

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

void testcase(){
	vector<char> tab[100];
	vector<int> cou[100];

	int n;
	cin >> n;	

	REP(j,n){
		string s;
		cin >> s;

		int c = 0;
		char last = '#';

		REP(i,s.length())
			if(s[i] != last){
				last = s[i];
				tab[j].PB(s[i]);
				cou[j].PB(c);
				c = 1;
			}
			else
				++c;

		if(c>0) cou[j].PB(c);
	}

	int s = tab[0].size();

	bool ok = true;
	
	REP(i,n)
		if(tab[i].size() != s) ok = false;
	
	REP(i,n) REP(j,n) REP(k,s)
		if(tab[i][k] != tab[j][k]) ok = false;

	if(!ok){
		cout << "Fegla Won";
		return;
	}

	int res = 0;
	FOR(i,1,s){
		int mini = 101;
		int maxi = 0;

		REP(j,n){
			mini = min(cou[j][i],mini);
			maxi = max(cou[j][i],maxi);
		}

//		cout << "\n" << mini << " " << maxi << "\n";

		int best = 1000000000;
		FOR(j,mini,maxi){
			int tmp = 0;
			REP(k,n) tmp += abs(cou[k][i]-j);
			best = min(best,tmp);
	//		cout << "best: " << best << endl;
		}

		res += best;
	}

	cout << res;
}

int main(){
	int t;
	cin >> t;

	FOR(i,1,t){
		cout << "Case #" << i << ": ";
		testcase();
		cout << endl;
	}

	return 0;
}
