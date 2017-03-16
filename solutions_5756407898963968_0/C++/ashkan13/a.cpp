#include <iostream>
#include <string>
using namespace std;

void main(){
	//*
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	//*/

	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		int ans, x;
		int num[17]={0};
		for(int k=0; k<2; k++){
			cin >> ans;
			for(int i=1; i<=4; i++){
				for(int j=1; j<=4; j++){
					cin >> x;
					if(i == ans) num[x]++;
				}
			}
		}
		int cnt = 0;
		for(int i=1; i<=16; i++){
			if(num[i] == 2){
				cnt++;
				ans = i;
			}
		}
		cout << "Case #" << tc << ": ";
		
		if(cnt == 1) cout << ans;
		else if(cnt > 1) cout << "Bad magician!";
		else cout << "Volunteer cheated!";
		cout << endl;
	}
}