#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>

using namespace std;

vector<string> v;

string sequence( const string& s, vector<int>& pos ) {
	int n = s.size();

	pos.clear();
	pos.push_back(0);

	string res;
	res += s[0];

	for( int i = 1; i < n; ++i ) {
		if( s[i] != s[i-1] ) {
			res += s[i];
			pos.push_back(i);
		}
	}
	return res;
}

string seq;
vector<int> pos[105];
int N;

int rec( int k ) {
	if( k == (int)seq.size() ) {
		return 0;
	}

	int minl = 1000000000;
	int maxl = -1;
	for( int i = 0; i < N; ++i ) {
		minl = min( minl, pos[i][k+1]-pos[i][k] );
		maxl = max( maxl, pos[i][k+1]-pos[i][k] );
	}


	int mincost = 1000000000;
	for( int i = minl; i <= maxl; ++i ) {
		int cost = 0;
		for( int j = 0; j < N; ++j ) {
			cost += abs( (pos[j][k+1]-pos[j][k])- i );
		}
		mincost = min( mincost, cost );
	}

	return mincost + rec( k+1 );
}

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		cin >> N;
		v.resize(N);
		for( int i = 0; i < N; ++i ) {
			cin >> v[i];
		}

		seq = sequence( v[0], pos[0] );
		bool ok = true;
		for( int i = 1; i < N; ++i ) {
			if( sequence( v[i], pos[i] ) != seq ) {
				ok = false;
				break;
			}
		}

		if( !ok ) {
			cout << "Fegla Won\n";
			continue;
		}

		for( int i =1 ; i < N; ++i ) {
			assert( pos[i].size() == pos[0].size() );
		}

		for( int i =0 ; i < N; ++i ) {
			pos[i].push_back(v[i].size());
		}

		cout << rec(0) << endl;
	}
	return 0;
}

