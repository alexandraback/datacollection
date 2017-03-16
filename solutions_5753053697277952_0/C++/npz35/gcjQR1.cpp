#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
#define rep(i,n) for(ll i=0;i<(n);i++)
 
using namespace std;


int main(){
	int t;
	cin >> t;
	rep(times, t){
		int n;
		cin >> n;
		int p[n];
		rep(i, n)	cin >> p[i];

		ll sum = 0;
		rep(i, n)	sum += p[i];
		cout << "Case #"<< times+1<<": ";
		string pt = "";
		while(0 < sum){
			int max[2] = {0, 0};//	>
			rep(i, n){
				if(p[max[0]] <= p[i]){
					max[1] = max[0];
					max[0] = i;
				}
				else if(p[max[1]] <= p[i]){
					max[1] = i;
				}
			}


			if(sum <= n){
				if(sum == 2){
					p[max[1]]--;p[max[0]]--;
					sum -= 2;
					char c1 = 'A'+max[0], c2 = 'A'+max[1];
					cout << pt << c1 << c2;
				}
				else{
					p[max[0]]--;
					sum--;
					char c = 'A'+max[0];
					cout << pt << c;
				}
			}
			else if(p[max[1]] == p[max[0]] && max[0] != max[1]){
				p[max[1]]--;p[max[0]]--;
				sum -= 2;
				char c1 = 'A'+max[0], c2 = 'A'+max[1];
				cout << pt << c1 << c2;
			}
			else if(p[max[0]] - p[max[1]] < 2){
				p[max[0]]--;
				sum--;
				char c = 'A'+max[0];
				cout << pt << c;
			}
			else{
				p[max[0]] -= 2;
				sum -= 2;
				char c = 'A'+max[0];
				cout << pt << c << c;
			}
			pt = " ";
			//rep(i, n)	cout << p[i] << ", ";
			//cout << endl;
		}
		cout << endl;
	}


	return 0;
}