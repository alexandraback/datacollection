#include <bits/stdc++.h>

using namespace std;

struct set_cmt{
    bool operator()(const pair<char, int>& a, const pair<char, int>& b){
	return ( a.second > b.second );
    };
};
  
int main(){
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
	int n;
	cin >> n;
	int p[n];
	for(int i = 0 ; i < n; i++) cin >> p[i];
	int total = 0;
	for(int i = 0; i < n; i++) total+=p[i];
	cout << "Case #" << cs << ": ";
	while( total > 0 ){
	    set<int> s;
	    int mx = 0;
	    for(int i = 0; i < n; i++){
		if( p[i] == mx ){
		    s.insert(i);
		}
		else if( p[i] > mx ){
		    s.clear();
		    s.insert(i);
		    mx = p[i];
		}
	    }
	    int cnt = 0;
	    
	    for( auto x: s ){
		cnt++;
		cout << (char)(x+'A');
		p[x]--;
		total--;
		if( total == 0 || s.size() > 2) break;
	    }
	    if( total ) cout << " ";
	}
	cout << endl;
    };
    return 0;
    
};
	    
	
