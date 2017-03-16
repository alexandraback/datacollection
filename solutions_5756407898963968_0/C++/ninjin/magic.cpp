#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T;
	cin >> T;
	for( int t=0; t<T; t++ ){
		int l;
		cin >> l;
		bool cand[16] = {0};
		for( int i=0; i<4; i++ ){
			for( int j=0; j<4; j++ ){
				int num;
				cin >> num;
				if( i == l-1 ) cand[num-1] = true;
			}
		}
		cin >> l;
		for( int i=0; i<4; i++ ){
			for( int j=0; j<4; j++ ){
				int num;
				cin >> num;
				if( i != l-1 ) cand[num-1] = false;
			}
		}
		int cnt = 0, ans = 0;
		for( int i=0; i<16; i++ ){
			if( cand[i] ){
				cnt++;
				ans = i+1;
			}
		}
		cout << "Case #" << t+1 << ": ";
		if( cnt > 1 ) cout << "Bad magician!";
		else if( cnt == 0 ) cout << "Volunteer cheated!";
		else cout << ans;
		cout << endl;
	}
}
