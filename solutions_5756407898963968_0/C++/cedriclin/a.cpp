#include <iostream>
#include <cstring>

using namespace std;

int possible[17];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		memset(possible,0,sizeof(possible));
		int m[2];
		int a[4];
		for (int k = 0; k <= 1; k++){
			cin >> m[k];
			//cout << "m[k] = " << m[k] << endl;
			for (int i = 1; i <= 4; i++){
				for (int j = 0; j < 4; j++){
					cin >> a[j];
					if (i==m[k]) possible[a[j]]++;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= 16; i++){
			//cout << possible[i] << " ";
			if (possible[i] == 2) cnt++;
		}
		//cout << endl;
		//cout << "cnt = " << cnt << endl;
		if (cnt==0) cout << "Case #" << zz << ": Volunteer cheated!" << endl;
		else if (cnt > 1) cout << "Case #" << zz << ": Bad magician!" << endl;
		else{
			for (int i = 1; i <= 16; i++){
				if (possible[i] == 2){
					cout << "Case #" << zz << ": " << i << endl;
					break;
				}
			}
		}
	}
	
	return 0;
}
