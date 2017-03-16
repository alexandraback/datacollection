#include "headers.h"
int main(){
	int T,tab[26],n;
	cin >> T;
	REP(t,T){
		cout << "Case #" << t+1 << ": ";
		cin >> n;
		int sum = 0;
		REP(i,n){
			cin >> tab[i];
			sum+=tab[i];
		}
		while(sum > 2){
			if(sum > 2){
				int max = -1;
				int id = -1;
				REP(i,n){
					if(tab[i] > max){
						max = tab[i];
						id = i;
					}	
				}
				cout << char('A' + id);
				tab[id]--;
				sum--;
			}
			if(sum > 2){
				int max = -1;
				int id = -1;
				REP(i,n){
					if(tab[i] > max){
						max = tab[i];
						id = i;
					}	
				}
				cout << char('A' + id);
				tab[id]--;
				sum--;
			}
			cout << " ";

/*
			int cs = 0;
			REP(i, n) cs += tab[i];
			REP(i,n) if(tab[i] > cs/2) cout << "ERROR! " << t+1 << endl;
*/

		}	

		if(sum < 3){
			REP(i,n){
				while(tab[i]){
					cout << char('A' + i);
					tab[i]--;
				}
			}
		}
		cout << endl;
	}
}
