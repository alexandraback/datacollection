#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>


using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

#define cin fin
#define cout fout

int pw[20];

int main(){
	pw[0] = 1;
	for(int i = 1 ; i < 20 ; ++i){
		pw[i] = pw[i - 1] * 2;
	}

	int t;
	cin >> t;

	for(int o = 0 ; o < t ; ++o){
		int r , c , n;
		cin >> r >> c >> n; 
		int tmap[r + 1][c + 1];
		int tans = 100000;
		int ans = 0;
		int map[r + 1][c + 1];
		int kk = r * c;
		for(int k = 1 ; k < pw[kk] ; ++k){
			ans = 0;
			//cout << k << endl;
			int map[r][c];
			for(int i = 0 ; i < r ; ++i){
				for(int j = 0 ; j < c ; ++j){
					map[i][j] = 0;
				}
			}
			int tt = 0;
			int x = 0;
			int kkk = k;
			int a[20] = {0};
			while(kkk > 0){
				if(kkk % 2 == 1) ++tt;
				a[x] = kkk % 2;
				++x;
				kkk /= 2;
			}

			if(tt == n){
				for(int i = 0 ; i < kk ; ++i){
					if(a[i] == 1){
						map[i / c][i % c] = 1;
					}
				}
				for(int i = 0 ; i < r ; ++i){
					for(int j = 0 ; j < c ; ++j){
						if(map[i][j] == 1){
							if(i - 1 >= 0){
								if(map[i - 1][j] == 1){
									++ans;
									//cout << "S1" << endl;
								}
							} 
							if(i + 1 < r){
								if(map[i + 1][j] == 1){
									++ans;
									//cout << "S2" << endl;
								}
							}
							if(j - 1 >= 0){
								if(map[i][j - 1] == 1){
									++ans;
									//cout << "S3" << endl;
								}
							}
							if(j + 1 < c){
								if(map[i][j + 1] == 1){
									++ans;
									//cout << "S4" << endl;
								}
							}
						}
					}
				}
				//cout << "Ans : " << ans << endl;
				//ans /= 2;
				if(ans < tans){
					tans = ans;
				}
			}
		}
		cout << "Case #" << o + 1 << ": " ;
		if(n == 0) cout << 0 << endl;
		else cout << tans / 2 << endl;

	}
	return 0;
}
