#include <iostream>

using namespace std;

int qwe(int a, int b){
	if (a > b) swap(a, b);
	for (int i = 1; i <= a; i++){
		if ((b * i) % a == 0) return b * i;
	}
}

int main(){
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++){
		int b, n;
		cin >> b >> n;
		int q[b];
		for (int i = 0; i < b; i++) cin >> q[i];
		int aver = q[0];
		for (int i = 1; i < b; i++){
			aver = qwe(aver, q[i]);
		}
		int mou = 0;
		for (int i = 0; i < b; i++) mou += aver / q[i];
		if (n % mou == 0) n = mou;
		else n %= mou;
		int serve = 0, t, ans = 0;
		for (t = 0; !ans; t++){
			for (int i = 0; i < b; i++){
				if (t % q[i] == 0) serve++;
				if (serve == n){
					ans = i + 1;
					break;
				}
			}
		}
		cout << "Case #" << k << ": " << ans << endl;
	}
	
	return 0;
}
