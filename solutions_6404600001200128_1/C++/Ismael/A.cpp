#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

pair<int,int> result(vector<int> v) {
    int res1 = 0;
    int maxD = 0;
    for(int i = 0; i < (int)v.size()-1; i++) {
	int d = v[i]-v[i+1];
	if(d > 0)
	    res1 += d;
	maxD = max(maxD,d);
    }
    int res2 = 0;
    for(int i = 0; i < (int)v.size()-1; i++) {
	int d = v[i]-v[i+1];
	res2 += min(v[i],maxD);
    }
    return make_pair(res1,res2);
}

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
	int nb;
	cin >> nb;
	vector<int> v;
	for(int i = 0; i < nb; i++) {
	    int t;
	    cin >> t;
	    v.push_back(t);
	}
	pair<int,int> res = result(v);
	cout << "Case #" << t+1 <<": "
	     << res.first << " " << res.second << endl;
    }
    return 0;
}
