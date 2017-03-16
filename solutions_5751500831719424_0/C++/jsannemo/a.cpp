#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pair<int,int>> groupify(){
    vector<pair<int,int>> groups;
    string x;
    cin >> x;
    for(int i = 0, cur = 0; i < x.size(); ++i){
	if(i+1 == x.size() || x[i] != x[i+1]){
	    groups.push_back(make_pair(x[i], i - cur + 1));
	    cur = i + 1;
	}
    }
    return groups;
}

string stringify(vector<pair<int,int>>& groups){
    string s;
    for(int i = 0; i < groups.size(); ++i) s += groups[i].first;
    return s;
}

bool solve(int tc){
    int n;
    scanf("%d", &n);
    vector<vector<pair<int,int>>> groups(n);
    for(int i = 0; i < n; ++i){
	groups[i] = groupify();
    }
    string s = stringify(groups[0]);
    for(int i = 1; i < n; ++i){
	if(s != stringify(groups[i])){
	    printf("Case #%d: Fegla Won\n", tc);
	    return true;
	}
    }
    int ans = 0;
    for(int i = 0; i < s.size(); ++i){
	vector<int> v(n);
	for(int j = 0; j < n; ++j) v[j] = groups[j][i].second;
	sort(v.begin(), v.end());
	int c = v[n/2];
	for(int j = 0; j < n; ++j) ans += abs(c - v[j]);
    }
    printf("Case #%d: %d\n", tc, ans);
    return true;
}

int main(){
    int n = 0;
    if(!n) cin >> n;
    for(int i = 1; i <= n && solve(i); ++i);
}
