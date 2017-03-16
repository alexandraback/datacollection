#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
struct Node {
	char c;
	int t;
	Node( char _c=0, int _t=0 ) : c(_c), t(_t) {}
};

typedef vector<Node> String;
vector<String> arr;

int solve(){
	int tot = 0;
	vector<int> occr;
	for( int w=0; w<arr[0].size(); w++  ){
		occr.clear();
		occr.push_back( arr[0][w].t );

		for( int i=1; i<arr.size(); i++ ){
			if( arr[0].size() != arr[i].size() ) return -1;
			if( arr[0][w].c != arr[i][w].c ) return -1;
			occr.push_back( arr[i][w].t );
		}
		sort( occr.begin(), occr.end() );
		int target = occr[occr.size()/2];
		//cout << arr[0][w].c << target << " ";
		for( int i=0; i<occr.size(); i++ ){
			tot += abs(occr[i] - target );
		}
	}
	return tot;
}
int main(){
	int testCase, ans ;

	cin >> testCase;
	for( int cas = 1; cas <= testCase; cas++ ){
		
		int n;
		cin >> n ;	
		
		arr.clear();

		string str;

		for( int i=0; i<n; i++){
			cin >> str;
			arr.emplace_back();
			String & current = *arr.rbegin();

			int times = 1, l;
			for( l = 1; l < str.length(); l++){
				if( str[l] != str[l-1] ){
					current.emplace_back( str[l-1], times );
					times = 1;
				}else{
					times ++;
				}
			}
			current.emplace_back( str[l-1], times );
		}		
		
		cout << "Case #" << cas << ": ";
		
		ans = solve();

		if( ans < 0 ) cout << "Fegla Won\n";
		else cout << ans << "\n";
	}
}
