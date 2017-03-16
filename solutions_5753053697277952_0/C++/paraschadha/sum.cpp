#include <bits/stdc++.h>
using namespace std;

long long arr[26];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long T, cas, N, i, t, x=0, f, y;
	cin >> T;
	for(cas=1;cas<=T;cas++){
		cout << "Case #" << cas << ": ";
		cin >> N;
		for(i=0;i<26;i++) arr[i] = 0;
		t=0;
		for(i=0;i<N;i++){
			cin >> arr[i];
			t += arr[i];
		}
		while(t){
			x=0;
			for(i=1;i<N;i++) if(arr[i]>arr[x]) x=i;
			arr[x]--;
			f=0;
			for(i=0;i<N;i++){
				if(arr[i]>(t-1)/2){
					f=1;
					break;
				}
			}
			if(f){
				y=0;
				for(i=0;i<N;i++) if(arr[i]>arr[y]) y=i;
				arr[y]--;
				t--;
				cout << char(x+'A') << char(y+'A') << ' ';
			}
			else cout << char(x+'A') << ' ';
			t--;
		}
		cout << '\n';
	}
	return 0;
}
