#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool valid( vector< pair< int, char > > &v ){
	for( int i = 0; i < int(v.size()); i++ ){
		int sum = 0;
		for( int j = 0 ; j < int(v.size());j++ ){
			if( i == j ) continue;
			sum += v[ j ].first;
		}	
		if( v[ i ].first > sum ) 
			return false;
	}
	return true;
}

int main(){
	int T; cin >> T;
	for( int t = 1; t <= T; t++ ){
		cout << "Case #" << t <<":";
		int N; cin >> N;
		vector< pair< int , char > > P(N);
		for( int n = 0; n < N; n++ ){
			cin >> P[ n ].first;
			P[ n ].second = 'A'+n;
		}
		sort( P.rbegin(), P.rend() );
		while( P[ 0 ].first != 0 ){
			P[ 0 ].first--;
			P[ 1 ].first--;
			if( valid( P ) ){
				cout << " " << P[ 0 ].second << P[ 1 ].second;
			}
			else{
				P[ 1 ].first++;
				if( valid( P ) ){
					cout << " " << P[ 0 ].second;
				}
			}
			sort( P.rbegin(), P.rend() );
		}
		cout << endl;
	}
}
